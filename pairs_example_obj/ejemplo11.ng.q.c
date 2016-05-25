#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff8,D,0.000000);
	CODE(1)
L 1:	STAT(2)
	DAT(0x11fe8,D,1.000000);
	DAT(0x11fe0,D,2.000000);
	DAT(0x11fd8,D,3.000000);
	CODE(2)
L 2:	RR0=D(0x11fe0);
	D(0x11ff8)=RR0;	STAT(3)
	STR(0x11fd4, "%f\n");
	CODE(3)
L 3:	R1=0x11fd4;
	RR2=D(0x11ff8);
	R0=4;
	GT(putd_);
L 4:GT(-2);
END