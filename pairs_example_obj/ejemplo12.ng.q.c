#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff8,D,1.000000);
	CODE(1)
L 1:	STAT(2)
	DAT(0x11fe8,D,1.000000);
	DAT(0x11fe0,D,2.000000);
	DAT(0x11fd8,D,3.000000);
	CODE(2)
L 2:	STAT(3)
	DAT(0x11fd0,D,2.000000);
	CODE(3)
L 3:	STAT(4)
	STR(0x11fcc, "%f\n");
	CODE(4)
L 4:	R1=0x11fcc;
	RR2=D(0x11fd0);
	R0=5;
	GT(putd_);
L 5:	RR0=D(0x11ff8);
	R0=6;
	GT(cast_);
L 6:	R2=0x11ff8;
	R1=R1*8;
	R1=R1+8;
	RR0=D(R2-R1);
	D(0x11fd0)=RR0;	STAT(5)
	STR(0x11fc8, "%f\n");
	CODE(5)
L 7:	R1=0x11fc8;
	RR2=D(0x11fd0);
	R0=8;
	GT(putd_);
L 8:GT(-2);
END