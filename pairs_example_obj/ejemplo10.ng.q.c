#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff8,D,3.000000);
	CODE(1)
L 1:	STAT(2)
	DAT(0x11fe8,D,1.000000);
	DAT(0x11fe0,D,2.000000);
	DAT(0x11fd8,D,3.000000);
	CODE(2)
L 2:	RR1=D(0x11fe8);
	D(0x11ff8)=RR1;
	STAT(3)
		STR(0x11fcb, "Valor de a");
	CODE(3)
L 3:	R1=0x11fcb;
	R2=0;
	R0=4;
	GT(putf_);
L 4:	STAT(4)
	STR(0x11fc7, "%f\n");
	CODE(4)
L 5:	R1=0x11fc7;
	RR2=D(0x11ff8);
	R0=6;
	GT(putd_);
L 6:	RR1=D(0x11ff8);
	D(0x11fd8)=RR1;
	D(0x11fe0)=RR1;
	D(0x11fe8)=RR1;
	STAT(5)
		STR(0x11fba, "Valor de b");
	CODE(5)
L 7:	R1=0x11fba;
	R2=0;
	R0=8;
	GT(putf_);
L 8:	STAT(6)
	STR(0x11fb6, "%f\n");
	CODE(6)
	R1=0x11fb6;
	RR2=D(0x11fd8);
	R0=9;
	GT(putd_);
L 9:	RR2=D(0x11fe0);
	R0=10;
	GT(putd_);
L 10:	RR2=D(0x11fe8);
	R0=11;
	GT(putd_);
L 11:GT(-2);
END