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
 DAT(0x11ff8,D,1.000000);
 CODE(1)
L 1: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R5=R6-8;
 RR1=D(R5);
 R5=R5-8;
 R0=R5;
 R1=R7;
 R4=R7-R5;
L 2:IF(!R4) GT(3);
 RR2=D(R5);
 RR0=RR1>RR2;
 R5=R5-8;
 R4=R7-R5;
 GT(2);
 R2=R6-R7;
 R2=R2/8;
 R2=R2-1;
L 3: RR0=D(R0);
L 4:IF(!RR0) GT(5);
 STAT(2)
  STR(0x11fef, "hellow");
 CODE(2)
L 6: R1=0x11fef;
 R2=0;
 R0=7;
 GT(-12);
L 7: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R5=R6-8;
 RR1=D(R5);
 R5=R5-8;
 R0=R5;
 R1=R7;
 R4=R7-R5;
L 8:IF(!R4) GT(9);
 RR2=D(R5);
 RR0=RR1>RR2;
 R5=R5-8;
 R4=R7-R5;
 GT(8);
 R2=R6-R7;
 R2=R2/8;
 R2=R2-1;
L 9: GT(4);
L 5: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R5=R6-8;
 RR1=D(R5);
 R5=R5-8;
 R0=R5;
 R1=R7;
 R4=R7-R5;
L 10:IF(!R4) GT(11);
 RR2=D(R5);
 RR0=RR1<RR2;
 R5=R5-8;
 R4=R7-R5;
 GT(10);
 R2=R6-R7;
 R2=R2/8;
 R2=R2-1;
L 11: RR0=D(R0);
L 12:IF(!RR0) GT(13);
 STAT(3)
  STR(0x11fd6, "from the other siiiide");
 CODE(3)
L 14: R1=0x11fd6;
 R2=0;
 R0=15;
 GT(-12);
L 15: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R5=R6-8;
 RR1=D(R5);
 R5=R5-8;
 R0=R5;
 R1=R7;
 R4=R7-R5;
L 16:IF(!R4) GT(17);
 RR2=D(R5);
 RR0=RR1<RR2;
 R5=R5-8;
 R4=R7-R5;
 GT(16);
 R2=R6-R7;
 R2=R2/8;
 R2=R2-1;
L 17: GT(12);
L 13:GT(-2);
END
