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
L 1: STAT(2)
 DAT(0x11fe8,D,1.000000);
 DAT(0x11fe0,D,2.000000);
 DAT(0x11fd8,D,3.000000);
 CODE(2)
L 2: STAT(3)
 DAT(0x11fd0,D,2.000000);
 CODE(3)
L 3: STAT(4)
 STR(0x11fcc, "%f\n");
 CODE(4)
L 4: R1=0x11fcc;
 RR2=D(0x11fd0);
 R0=5;
 GT(-13);
L 5: RR0=D(0x11ff8);
 R0=6;
 GT(-14);
L 6: R2=0x11fe8;
 RR0=D(R2+R1);
 D(0x11fd0)=RR0; STAT(5)
 STR(0x11fc8, "%f\n");
 CODE(5)
L 7: R1=0x11fc8;
 RR2=D(0x11fd0);
 R0=8;
 GT(-13);
L 8:GT(-2);
END
