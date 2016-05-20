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
L 0: R7=R7-40;
        R0 = 0;
        R1 = 1;
L 1: R2 = 4 * R0;
        I(R2+R7) = R1;
        R0 = R0 + 1;
        R1 = R1 * R0;
        IF (R0 < 10) GT(1);
        GT(-1);
        GT(-2);
END
