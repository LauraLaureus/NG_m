#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff0,D,1.000000);
	DAT(0x11fe8,D,2.000000);
	CODE(1)
L 1:	STAT(2)
	DAT(0x11fd8,D,3.000000);
	DAT(0x11fd0,D,6.000000);
	CODE(2)
L 2:	R6=R7;
	R7=R7-16;
	RR3=D(0x11fe8);
	D(R7+8)=RR3;
	RR3=D(0x11fe0);
	D(R7+0)=RR3;
	R7=R7-16;
	RR3=D(0x11fd0);
	D(R7+8)=RR3;
	RR3=D(0x11fc8);
	D(R7+0)=RR3;
	R5=R6-R7;
	R5=R5/8;
	R5=R5%2;
	R0=-2;
	IF(!R5) GT(exit_);
	R4=R6-R7;
	R4=R4/2;
	R5=R7;
	R3=R6-R4;
L 3:IF(!R3) GT(4);
	RR1=D(R4);
	RR2=D(R5);
	RR0=RR1+RR2;
	D(R5)=RR0;
	R5=R5+8;
	R4=R4+8;
	R3=R6-R4;
	GT(3);
	R0=-1;
	R1=R7;
	R2=R6-R7;
	R2=R2/8;
L 5:	R3=R2;
	L 6: IF(!R3) GT(7);
	RR0=D(R1);
	D(0x11fd0)=RR0;
	R3=R2;
	GT(6);
	L 7:	STAT(3)
	STR(0x11fcc, "%f\n");
	CODE(3)
	R1=0x11fcc;
	RR2=D(0x11fd0);
	R0=8;
	GT(putd_);
L 8:	RR2=D(0x11fd8);
	R0=9;
	GT(putd_);
L 9:GT(-2);
END