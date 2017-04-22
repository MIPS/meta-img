#ifndef FDC_H
#define FDC_H

typedef int FDC_S32;
typedef unsigned int FDC_U32;
typedef unsigned char FDC_U8;
typedef unsigned short FDC_U16;
typedef signed short FDC_S16;

enum {
	FDC_SUCCESS=0,
	FDC_ERR_UNSPECIFIED=-1,
	FDC_ERR_INVALID_ARG=-2,
	FDC_ERR_CHANNEL_ALREADY_CLAIMED=-3,
	FDC_ERR_NO_MIPS_PROBE_ATTACHED=-4,		
	FDC_ERR_FDC_EMULATION_SYSCALL_NOT_INTERCEPTED=-5,
	FDC_ERR_PROCESSOR_HAS_NO_CDMM=-6,
	FDC_ERR_CDMM_BASE_ADDR_BAD_ALIGNMENT=-7,
	FDC_ERR_CDMM_BASE_ADDR_NOT_ACCESSIBLE_VIA_KSEG1=-8,	
	FDC_ERR_NO_FDC_HW_FOUND=-9,
	FDC_ERR_INVALID_PROCESSOR_NUMBER=-10,
	FDC_ERR_INVALID_VPE_NUMBER=-11,			
};

enum {
	false=-1,
	true=0
};

int fdc_init(void);
int fdc_printf(const char *format, ...);
int fdc_sprintf(char *out, const char *format, ...);
void fdc_flush (void) __attribute__ ((noinline));;
void fdc_putchar(int c) __attribute__ ((noinline));

#endif	/*FDC_H*/
