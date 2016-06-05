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
L 1000: STAT(1)
  STR(0x11fe4, "valor de n en la llamada ");
 CODE(1)
L 1: R1=0x11fe4;
 R2=0;
 R0=2;
 GT(-12);
L 2: STAT(2)
 STR(0x11fe0, "%f\n");
 CODE(2)
L 3: R1=0x11fe0;
 RR2=D(R6+8);
 R0=4;
 GT(-13);
L 4: STAT(3)
  STR(0x11fdb, "\n");
 CODE(3)
L 5: R1=0x11fdb;
 R2=0;
 R0=6;
 GT(-12);
L 6:

L 7: R7=R7-8;
 RR3=D(R6+8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1==RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 8:
IF(!RR1) GT(9);





 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1+RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 10: RR0=D(R0);
 D(R6+8)=RR0;
 L 11:L 9:


L 12: R7=R7-8;
 RR3=D(R6+8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=1.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1==RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 13:
IF(!RR1) GT(14);





 R7=R7-8;
 RR3=D(R6+8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1+RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 15: RR0=D(R0);
 D(R6+8)=RR0;
 L 16:L 14:


L 17: R7=R7-8;
 RR3=D(R6+8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=1.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1>RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 18:
IF(!RR1) GT(19);


 R7=R7-8;
 D(R7)=0.000000;

 R7=R7-8;
 D(R7)=0.000000;




 R7=R7-8;
 RR3=D(R6+8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=1.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1-RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 20: RR0=D(R0);
 D(R6+-80)=RR0;
 L 21:



 R7=R7-8;
 RR3=D(R6+8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=2.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1-RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 22: RR0=D(R0);
 D(R6+-88)=RR0;
 L 23:
 R7=R7-24;
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

 R7=R7-8;
 RR0=D(R6-88);
 D(R7)=RR0;
 R7=R7-4;
 I(R7)=R6;
 R5=24;
 R7=R7-4;
 I(R7)=R5;
 R6=R7;
 GT(1000);
L 24: R6=I(R7+4);

 R7=R7+8;
 RR1=D(R7);
 RR2=D(R7+8);
 RR3=D(R7+16);
 R7=R7+24;
 R0=I(R7);
 R1=I(R7+4);
 R2=I(R7+8);
 R3=I(R7+12);
 R4=I(R7+16);
 R5=I(R7+20);
 R7=R7+24;
 D(R6-88)=RR0;

 R7=R7-24;
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

 R7=R7-8;
 RR0=D(R6-80);
 D(R7)=RR0;
 R7=R7-4;
 I(R7)=R6;
 R5=25;
 R7=R7-4;
 I(R7)=R5;
 R6=R7;
 GT(1000);
L 25: R6=I(R7+4);

 R7=R7+8;
 RR1=D(R7);
 RR2=D(R7+8);
 RR3=D(R7+16);
 R7=R7+24;
 R0=I(R7);
 R1=I(R7+4);
 R2=I(R7+8);
 R3=I(R7+12);
 R4=I(R7+16);
 R5=I(R7+20);
 R7=R7+24;
 D(R6-80)=RR0;




 R7=R7-8;
 RR3=D(R6-80);
 D(R7)=RR3;
 R7=R7-8;
 RR3=D(R6-88);
 D(R7)=RR3;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1+RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 26: RR0=D(R0);
 D(R6+8)=RR0;
 L 27:L 19:
 RR0=D(R6+8);
 R7=R6;
 R5=I(R6);
 GT(R5);
L 0: R6=R7;

 R7=R7-8;
 D(R7)=5.000000;

 R7=R7-8;
 D(R7)=0.000000;

 R7=R7-24;
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

 R7=R7-8;
 RR0=D(R6-8);
 D(R7)=RR0;
 R7=R7-4;
 I(R7)=R6;
 R5=28;
 R7=R7-4;
 I(R7)=R5;
 R6=R7;
 GT(1000);
L 28: R6=I(R7+4);

 R7=R7+8;
 RR1=D(R7);
 RR2=D(R7+8);
 RR3=D(R7+16);
 R7=R7+24;
 R0=I(R7);
 R1=I(R7+4);
 R2=I(R7+8);
 R3=I(R7+12);
 R4=I(R7+16);
 R5=I(R7+20);
 R7=R7+24;
 D(R6-16)=RR0;
 STAT(4)
  STR(0x11fcd, "resultado: ");
 CODE(4)
L 29: R1=0x11fcd;
 R2=0;
 R0=30;
 GT(-12);
L 30: STAT(5)
 STR(0x11fc9, "%f\n");
 CODE(5)
L 31: R1=0x11fc9;
 RR2=D(R6-16);
 R0=32;
 GT(-13);
L 32: STAT(6)
  STR(0x11fc4, "\n");
 CODE(6)
L 33: R1=0x11fc4;
 R2=0;
 R0=34;
 GT(-12);
L 34:GT(-2);
END
