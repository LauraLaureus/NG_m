#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff8,D,1.000000);
	CODE(1)
L 1:	R6=R7;
	R7=R7-8;
	RR3=D(0x11ff8);
	D(R7)=RR3;
	R7=R7-8;
	RR1=0.000000;
	D(R7)=RR1;
	RR2=D(R7);
	RR1=D(R7+8);
	RR0=RR1>RR2;
	R7=R7+8;
	D(R7)=RR0;
	R0=R7;
L 2:L 3:IF(!RR0) GT(4);
	STAT(2)
		STR(0x11fef, "hellow");
	CODE(2)
L 5:	R1=0x11fef;
	R2=0;
	R0=6;
	GT(putf_);
L 6:	R6=R7;
	R7=R7-8;
	RR3=D(0x11ff8);
	D(R7)=RR3;
	R7=R7-8;
	RR1=2.000000;
	D(R7)=RR1;
	RR2=D(R7);
	RR1=D(R7+8);
	RR0=RR1<RR2;
	R7=R7+8;
	D(R7)=RR0;
	R0=R7;
L 7:L 8:IF(!RR0) GT(9);
	STAT(3)
		STR(0x11fd9, "from the other side");
	CODE(3)
L 10:	R1=0x11fd9;
	R2=0;
	R0=11;
	GT(putf_);
L 11:GT(-2);
END