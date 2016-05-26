#include "Q.h"
    BEGIN
	STAT(0)
	FIL(0x11fb0,10,0);
	MEM(0x11fa8,8);
	CODE(0)
L 0:R6=R7;
	STAT(1)
		STR(0x11f9f, "furula");
	CODE(1)
L 1:	R1=0x11f9f;
	R2=0;
	R0=2;
	GT(putf_);
L 2:GT(-2);
END