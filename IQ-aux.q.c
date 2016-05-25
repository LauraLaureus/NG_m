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
 DAT(0x11ff0,D,2.000000);
 DAT(0x11fe8,D,3.000000);
 DAT(0x11fe0,D,4.000000);
 CODE(1)
L 1: STAT(2)
 DAT(0x11fd0,D,2.000000);
 DAT(0x11fc8,D,3.000000);
 DAT(0x11fc0,D,4.000000);
 CODE(2)
L 2: R6=R7;
 R7=R7-24;
 RR3=D(0x11fe0);
 D(R7+16)=RR3;
 RR3=D(0x11fd8);
 D(R7+8)=RR3;
 RR3=D(0x11fd0);
 D(R7+0)=RR3;
 R7=R7-24;
 RR3=D(0x11fc0);
 D(R7+16)=RR3;
 RR3=D(0x11fb8);
 D(R7+8)=RR3;
 RR3=D(0x11fb0);
 D(R7+0)=RR3;
 R5=R6-R7;
 R5=R5/8;
 R5=R5%2;
 R0=-2;
 IF(!R5) GT(-10);
 R4=R6-R7;
 R4=R4/2;
 R5=R7;
 R3=R6-R4;
L 3:IF(!R3) GT(4);
 RR1=D(R4);
 RR2=D(R5);
 RR0=RR1*RR2;
 D(R5)=RR0;
 R5=R5+8;
 R4=R4+8;
 R3=R6-R4;
 GT(3);
L 4:GT(-2);
END
