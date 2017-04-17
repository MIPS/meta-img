#include "fdc.h"
#include "fdc_putchar.h"

static unsigned long fdcBaseAddr;
static int cdmm_was_mapped = 0;
static FDC_U32 gCDMMBase;
static int fdc_char_count = 0;

void fdc_putchar(int c) __attribute__ ((noinline));


/********************************************************************************************
 *                                                                                          *
 * fdc_hw_find_base_addr - is used to locate the base address of the FDC memory mapped       *
 * registers. The FDC memory-mapped registers are located in the common device memory       *
 * map (CDMM) region. FDC has a device ID of 0xFD. If FDC not found return                  *
 * FDC_ERR_NO_FDC_HW_FOUND otherwise return FDC_SUCCESS.                                    *
 *                                                                                          *
 ********************************************************************************************/
int fdc_hw_find_base_addr(unsigned long *fdcBaseAddr) {
	int result;
	int found = 0;
	FDC_U32 CDMMBase;
	FDC_U32 CDMMBaseAddr;
	FDC_U32 numdrbs;
	CDMM_DEVICE_RESOURCE_BLOCK *drb_begin;
	CDMM_DEVICE_RESOURCE_BLOCK *drb_end;
	CDMM_DEVICE_RESOURCE_BLOCK *drb_cur;			

	CDMMBase = gCDMMBase;
	CDMMBaseAddr = (CDMMBase >> 11) << 15;
	numdrbs = (CDMMBase & 0x1FF);
	drb_begin = (CDMM_DEVICE_RESOURCE_BLOCK*)CDMMBaseAddr;
	drb_end = drb_begin + numdrbs;

	drb_cur = ((CDMMBase & (1 << 9)) == 0) ? drb_begin : drb_begin+1;
	while (drb_cur < drb_end) {
		FDC_U32 acsr = drb_cur->primary.acsr;
		FDC_U32 extradrbs;

		if (CDMM_DEV_TYPE(acsr) == 0xFD) {
			found = 1;
			break;
		} 
		extradrbs = CDMM_DEV_SIZE(acsr);
		drb_cur += extradrbs;
	}
	if (found) {
		*fdcBaseAddr = (unsigned long) drb_cur;
		result = FDC_SUCCESS;
	} else {
		result = FDC_ERR_NO_FDC_HW_FOUND;
	}
	
	return result;
} // end of fdc_hw_find_base_addr

/********************************************************************************************
 *                                                                                          *
 * fdc_init is called to emable the Common Device Memory Map and save global pointer to     *
 * CDMM.                                                                                    *
 *                                                                                          *
 *                                                                                          *
 ********************************************************************************************/
int fdc_init(void) {
	int result = FDC_SUCCESS;
	FDC_U32 CDMMOverlayPhysicalAddr = 0x1fc10000;

	if (!IS_PHYSICAL_ADDRESS_ADDRESSABLE_VIA_KSEG1(CDMMOverlayPhysicalAddr))
		result = FDC_ERR_CDMM_BASE_ADDR_NOT_ACCESSIBLE_VIA_KSEG1;

	if (result == FDC_SUCCESS) {
		if ((CDMMOverlayPhysicalAddr & ((1 << 15)-1)) != 0) {
			result = FDC_ERR_CDMM_BASE_ADDR_BAD_ALIGNMENT;
		}
	}

	if (result == FDC_SUCCESS) {

		FDC_U32 kseg1Addr = MAKE_KSEG1_ADDR(CDMMOverlayPhysicalAddr);
		FDC_U32 config3 = ReadConfig3();

		if ((config3 & 0x8) != 0) {

			FDC_U32 CDMMBase = ReadCDMMBase();

			/* Is Memory-Mapped I/O enabled */
			if (((CDMMBase & 0x400) >> 10) != 1)
			{
				// set address
				cdmm_was_mapped = (CDMMBase & (1 << 10)) != 0;

				// enable
				CDMMBase |= (1 << 10);				
				WriteCDMMBase(CDMMBase);
				CDMMBase |= ((kseg1Addr >> 15) << 11);
			}

			gCDMMBase = CDMMBase;

		} else {
			result = FDC_ERR_PROCESSOR_HAS_NO_CDMM;
		}

	}

	fdc_hw_find_base_addr(&fdcBaseAddr);
	fdc_char_count = 0;
	return result;
} // end of fdc_init

//********************************************************************************************
// fdc_putchar
//
// Function writes a character to the next most significant byte of a 4 byte char buffer.
// Once buffer has 4 characters, checks for FIFO not full.  If it is not, it writes the word
// to channel 0 of FDC transmit port.
// If the FDC FIFO is full then it polls waiting for it to be not full. While polling, it
// counts up and if the count exceeds a constant, it sets static variable "timeout" which
// means the openOCD host is not polling for characters.  From then on if the function is called
// it is immediately bypassed so as not to waste time with each call.  The program has
// to be restarted to reset the timeout variable.
//
// Future enhancement could add a control channel to pass info like semi-hosting enable/disable.                                                       *
//
// FDC Channel Zero only with Polling. Interrupts not support at this time.
//
//********************************************************************************************/
#define FDC_PUTCHAR_TIMEOUT 1000000  //max spin count waiting to write to FIFO

static volatile int timeout = 0;    //initialize to no timeout
static volatile unsigned int fdc_buff;
static volatile unsigned int waitcount = 0;  //accumulated count waiting for FIFO to be not full, for analysis of performance purposes

void fdc_putchar(int c)
{
    volatile FDC_REGS *fdc = (FDC_REGS *)fdcBaseAddr;
    volatile unsigned long i;

    if (timeout == 1)
        return;  // once a timeout occurs, bypass the function to reduce the overhead of calling this
                 // function when the host-side semihosting is not enabled
    // Insert Char. in buffer
    fdc_buff = (fdc_buff >> 8) | (c << 24);

    // if char is null, this means flush out any remaining characters by shifting them right
    if (c == '\0') {
        if (fdc_char_count == 0)  
            return;                 // no char's accumulated, return
        while (fdc_char_count < 3) {
            fdc_buff >>= 8;
            fdc_char_count++;
        }
    } else {
        fdc_char_count++;  // non-null character, increment count
    }
    if ((fdc_char_count > 3) || (c == '\0')) { // write buffer to FDC outgoing FIFO
        i = 0;
        while (((fdc->fdstat) & 0x1) == 1) { // If Tx FIFO full, wait for not full or set timeout
            i++;
            waitcount++;
            if (i >= FDC_PUTCHAR_TIMEOUT) {
                timeout = 1;  // set timeout so this function is bypassed from now on, or until user program is restarted
                return;
            }
        }
        fdc->fdtx = fdc_buff;  // output word to FDC FIFO
        fdc_buff = 0;
        fdc_char_count = 0;
    }
} // end of fdc_putchar()
