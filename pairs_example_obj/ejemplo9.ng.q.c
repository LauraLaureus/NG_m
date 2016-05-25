#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff0,D,2.000000);
	DAT(0x11fe8,D,2.000000);
	CODE(1)
L 1:	STAT(2)
	DAT(0x11fd8,D,3.000000);
	DAT(0x11fd0,D,3.000000);
	CODE(2)
L 2:	RR1=D(0x11fd0);
	D(0x11fe8)=RR1;
	RR1=D(0x11fd0);
	D(0x11ff0)=RR1;
	RR1=D(0x11fd8);
	STAT(3)
	STR(0x11fcc, "%f\n");
	CODE(3)
	R1=0x11fcc;
	RR2=D(0x11fe8);
	R0=3;
	GT(putd_);
L 3:	RR2=D(0x11ff0);
	R0=4;
	GT(putd_);
L 4:GT(-2);
END