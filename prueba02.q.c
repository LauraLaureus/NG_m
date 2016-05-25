#include "Q.h"
BEGIN
STAT(0)
        STR(0x11ff0,"%f\n");
        STR(0x11fe0,"%d\n");
CODE(0)
L 0:    R0=1;
        RR2=8.1;
        R1=0x11ff0;
        GT(putd_);
L 1:    RR0=-3.2;
        R0=2;
        GT(cast_);
L 2:    R0=3;
        R2=R1;
        R1=0x11fe0;
        GT(putf_);
L 3:    GT(exit_);
END
