#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 0:	STAT(1)
	DAT(0x11ff8,D,2.000000);
	DAT(0x11ff0,D,3.000000);
	CODE(1)
L 1:	STAT(2)
	STR(0x11fec, "%d\n");
	CODE(2)
	R1=0x11fec;
	R2=D(0x11ff0);
	R0=2;
	GT(putf_);
L 2:	R2=D(0x11ff8);
	R0=3;
	GT(putf_);
L 3:GT(-2);
END