#ifndef __HCD62121_H__
#define __HCD62121_H__


enum
{
	HCD62121_IP=1, HCD62121_SP, HCD62121_F, HCD62121_LAR,
	HCD62121_CS, HCD62121_DS, HCD62121_SS, HCD62121_DSIZE,
	/* 128 byte register file */
	HCD62121_R00, HCD62121_R04, HCD62121_R08, HCD62121_R0C,
	HCD62121_R10, HCD62121_R14, HCD62121_R18, HCD62121_R1C,
	HCD62121_R20, HCD62121_R24, HCD62121_R28, HCD62121_R2C,
	HCD62121_R30, HCD62121_R34, HCD62121_R38, HCD62121_R3C,
	HCD62121_R40, HCD62121_R44, HCD62121_R48, HCD62121_R4C,
	HCD62121_R50, HCD62121_R54, HCD62121_R58, HCD62121_R5C,
	HCD62121_R60, HCD62121_R64, HCD62121_R68, HCD62121_R6C,
	HCD62121_R70, HCD62121_R74, HCD62121_R78, HCD62121_R7C,
};


/* I/O ports */
enum
{
	/* Output ports */
	HCD62121_KOL=0x00,
	HCD62121_KOH,
	/* Input ports */
	HCD62121_KI,
};


DECLARE_LEGACY_CPU_DEVICE(HCD62121, hcd62121);


extern CPU_DISASSEMBLE( hcd62121 );

#endif /* __HCD62121_H__ */

