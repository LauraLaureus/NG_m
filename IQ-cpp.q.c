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
 R3=R2;


 L 11: IF(!R3) GT(12);
 RR0=D(R1);
 D(R6+8)=RR0;
 R3=R2;


 GT(11);
 L 12:L 9:


L 13: R7=R7-8;
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
L 14:
IF(!RR1) GT(15);





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
L 16: RR0=D(R0);
 D(R6+8)=RR0;
 R3=R2;


 L 17: IF(!R3) GT(18);
 RR0=D(R1);
 D(R6+8)=RR0;
 R3=R2;


 GT(17);
 L 18:L 15:


L 19: R7=R7-8;
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
L 20:
IF(!RR1) GT(21);


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
L 22: RR0=D(R0);
 D(R6+-80)=RR0;
 R3=R2;


 L 23: IF(!R3) GT(24);
 RR0=D(R1);
 D(R6-80)=RR0;
 R3=R2;


 GT(23);
 L 24:



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
L 25: RR0=D(R0);
 D(R6+-88)=RR0;
 R3=R2;


 L 26: IF(!R3) GT(27);
 RR0=D(R1);
 D(R6-88)=RR0;
 R3=R2;


 GT(26);
 L 27:
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
 D(R6+8)=RR0;




 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 R7=R7-8;
 RR3=D(R6-88);
 D(R7)=RR3;
 RR2=D(R7);
 RR1=D(R7+8);
 RR1=RR1+RR2;
 R7=R7-8;
 D(R7)=RR1;
 R0=R7;
L 29: RR0=D(R0);
 D(R6+8)=RR0;
 R3=R2;


 L 30: IF(!R3) GT(31);
 RR0=D(R1);
 D(R6+8)=RR0;
 R3=R2;


 GT(30);
 L 31:L 21:
 RR0=D(R6+8);
 R7=R6;
 R5=I(R6);
 GT(R5);
L 0: R6=R7;

 R7=R7-8;
 D(R7)=2.000000;

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
 R5=32;
 R7=R7-4;
 I(R7)=R5;
 R6=R7;
 GT(1000);
L 32: R6=I(R7+4);

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
L 33: R1=0x11fcd;
 R2=0;
 R0=34;
 GT(-12);
L 34: STAT(5)
 STR(0x11fc9, "%f\n");
 CODE(5)
L 35: R1=0x11fc9;
 RR2=D(R6-16);
 R0=36;
 GT(-13);
L 36: STAT(6)
  STR(0x11fc4, "\n");
 CODE(6)
L 37: R1=0x11fc4;
 R2=0;
 R0=38;
 GT(-12);
L 38:GT(-2);
END
