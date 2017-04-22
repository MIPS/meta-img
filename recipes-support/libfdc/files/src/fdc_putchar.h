#ifndef FDC_PUTCHAR_H
#define FDC_PUTCHAR_H

#define MHZ     50            /* Digilent 4 DDR CPU clock. */


enum {
	SEMI_HOSTING_DISABLED = 0,
	SEMI_HOSTING_ENABLED = 1
};

typedef struct {
	unsigned long fdacsr;
	unsigned long reserved_0;
	unsigned long fdcfg;
	unsigned long reserved_1;
	unsigned long fdstat;
	unsigned long reserved_2;
	unsigned long fdrx;
	unsigned long reserved_3;
	unsigned long fdtx;
} FDC_REGS;


#define BYTES_PER_CDMM_DEVICE_RESOURCE_BLOCK 64
#define IS_PHYSICAL_ADDRESS_ADDRESSABLE_VIA_KSEG1(addr)  (((addr) & 0xE0000000) == 0)
#define MAKE_KSEG1_ADDR(addr)  (((addr) & 0x1FFFFFFF)|0xA0000000)

/********************************************************************************************
 *                                                                                          *
 * Software on the core accesses FDC through memory mapped registers. These memory mapped   *
 * registers are located within the Common Device Memory Map (CDMM). The CDMM is a region   *
 * of physical address space that is reserved for mapping IO device configuration registers *
 * within a MIPS processor. The base address and enabling of this region is controlled by   *
 * the CDMMBase CP0 register.                                                               *
 *                                                                                          *
 ********************************************************************************************/
typedef union {
	struct {
		FDC_U32 acsr;
		unsigned char data[BYTES_PER_CDMM_DEVICE_RESOURCE_BLOCK-sizeof(FDC_U32)];
	} primary;
	struct {
		unsigned char data[BYTES_PER_CDMM_DEVICE_RESOURCE_BLOCK];
	} secondary;
} CDMM_DEVICE_RESOURCE_BLOCK;

#define CDMM_DEV_TYPE(acsr) ((FDC_U32)(((acsr) >> 24) & 0xFF))
#define CDMM_DEV_SIZE(acsr) ((FDC_U32)(((acsr) >> 16) & 0x3F))

/********************************************************************************************
 *                                                                                          *
 * Read Config3 register                                                                    *
 *                                                                                          *
 ********************************************************************************************/
FDC_U32 ReadConfig3(void) {
	FDC_U32 val;
	__asm("mfc0 %0, $16, 3" : "=r"(val));	
	return val;
}

/********************************************************************************************
 *                                                                                          *
 * Read Common Device Memory Map Base register                                              *
 *                                                                                          *
 ********************************************************************************************/
static FDC_U32 ReadCDMMBase(void) {
	FDC_U32 val;
	__asm("mfc0 %0, $15, 2" : "=r"(val));	
	return val;
}

/********************************************************************************************
 *                                                                                          *
 * Write Common Device Memory Map Base register                                             *
 *                                                                                          *
 ********************************************************************************************/
void WriteCDMMBase(FDC_U32 val) {
	__asm("mtc0 %0, $15, 2" : : "r"(val));	

}

/********************************************************************************************
 *                                                                                          *
 * Read Cause register                                                                    *
 *                                                                                          *
 ********************************************************************************************/
FDC_U32 ReadCause(void) {
	FDC_U32 val;
	__asm("mfc0 %0, $13, 0" : "=r"(val));	
	return val;
}

/********************************************************************************************
 *                                                                                          *
 * Read Count register                                                                    *
 *                                                                                          *
 ********************************************************************************************/
volatile FDC_U32 ReadCount(void) {
	FDC_U32 val;
	__asm("mfc0 %0, $9, 1" : "=r"(val));	
	return val;
}

#endif	/*FDC_PUTCHAR_H*/

