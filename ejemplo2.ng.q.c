#include "Q.h"
    BEGIN
	STAT(0)
	MEM(0x11ffc,4);
	MEM(0x11ff8,4);
	CODE(0)
	STAT(1)
		STR(0x11fef, "furula");
	CODE(1)
L 0:	R1=0x11fef;
	R2=0;
	R0=-2;
	GT(putf_);
L 1:GT(-2);END