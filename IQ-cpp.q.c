#include "Q.h"
# 1 "IQ-cpp.q.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 329 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "IQ-cpp.q.c" 2
# 1 "./Qlib.h" 1
# 2 "IQ-cpp.q.c" 2
 BEGIN
 STAT(0)
 CODE(0)
L 0: STAT(1)
 DAT(0x11ff8,D,2.000000);
 DAT(0x11ff0,D,3.000000);
 CODE(1)
L 1: STAT(2)
 STR(0x11fec, "%f\n");
 CODE(2)
 R1=0x11fec;
 RR2=D(0x11ff0);
 R0=2;
 GT(-13);
L 2: RR2=D(0x11ff8);
 R0=3;
 GT(-13);
L 3:GT(-2);
END
