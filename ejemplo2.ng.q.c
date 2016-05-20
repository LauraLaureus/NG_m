#include "Q.h"
    BEGIN
	STAT(0)
	MEM(0x11ffc,4);
	MEM(0x11ff8,4);
	STAT(1)
		STR(0x11ff0,"furula");
		STR(0x11fed,%s\n);
	CODE(1)
L 0:	R7=R7-12;
	P(R7+8)=0x11fed;
	R0=0x11ff0
	I(R7+4)=R0;
	I(R7)=2;
	GT(-12);
END