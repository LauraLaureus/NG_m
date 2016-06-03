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
 MEM(0x11ff8,8);
 CODE(0)
L 1000: R6=R7;
 R7=R7-8;
 RR3=D(0x0);
 D(R7)=RR3;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1==RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 1:L 2:IF(!RR0) GT(3);
 R6=R7;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1+RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 4: RR0=D(R0);
 D(0x0)=RR0;
 R3=R2;
 L 5: IF(!R3) GT(6);
 RR0=D(R1);
 D(0x00)=RR0;
 R3=R2;
 GT(5);
 L 6: R6=R7;
 R7=R7-8;
 RR3=D(0x0);
 D(R7)=RR3;
 R7=R7-8;
 RR1=1.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1==RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 7:L 8:IF(!RR0) GT(9);
 R6=R7;
 R7=R7-8;
 RR1=1.000000;
 D(R7)=RR1;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1+RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 10: RR0=D(R0);
 D(0x0)=RR0;
 R3=R2;
 L 11: IF(!R3) GT(12);
 RR0=D(R1);
 D(0x00)=RR0;
 R3=R2;
 GT(11);
 L 12: R5=I(R6);
 GT(R5);
L 0: R7=R7-8;
 D(R7)=0.000000;
L 13: R7=R7-8;
 D(R7)=0.000000;
L 14: R7=R7-24;
 I(R7)=R0;
 I(R7+4)=R1;
 I(R7+8)=R2;
 I(R7+12)=R3;
 I(R7+16)=R4;
 I(R7+20)=R5;
 R7=R7-24;
 D(R7)=RR1;
 D(R7+8)=RR2;
 D(R7+16)=RR3;
 R7=R7+8;
 RR0=D(0x11ff0);
 D(R7)=RR0;
 R7=R7-4;
 I(R7)=R6;
 R5=15;
 R7=R7-4;
 I(R7)=R5;
 R6=R7;
 GT(1000);
L 15: R6=D(R7+4);

 RR2=D(R7+12);
 RR1=D(R7+20);
 R0=I(R7+28);
 R1=I(R7+32);
 R2=I(R7+36);
 R3=I(R7+40);
 R4=I(R7+44);
 R5=I(R7+48);
 R7=R7+52;
 D(0x11fe8)=RR0;
 STAT(1)
 STR(0x11fe4, "%f\n");
 CODE(1)
L 16: R1=0x11fe4;
 RR2=D(0x11fe8);
 R0=17;
 GT(-13);
L 17:GT(-2);
END
