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
 DAT(0x11ff8,D,4.000000);
 CODE(1)
L 1: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1>RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 2:L 3:IF(!RR0) GT(4);
 STAT(2)
  STR(0x11fea, "azumbague\n");
 CODE(2)
L 5: R1=0x11fea;
 R2=0;
 R0=6;
 GT(-12);
L 6: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=1.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1-RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 7: RR0=D(R0);
 D(0x11ff8)=RR0;
 R3=R2;
 L 8: IF(!R3) GT(9);
 RR0=D(R1);
 D(0x11ff811ff8)=RR0;
 R3=R2;
 GT(8);
 L 9: R6=R7;
 R7=R7-8;
 RR3=D(0x11ff8);
 D(R7)=RR3;
 R7=R7-8;
 RR1=0.000000;
 D(R7)=RR1;
 RR2=D(R7);
 RR1=D(R7+8);
 RR0=RR1>RR2;
 R7=R7+8;
 D(R7)=RR0;
 R0=R7;
L 10: GT(3);
L 4:GT(-2);
END
