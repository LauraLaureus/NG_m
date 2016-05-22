#include "Q.h"             
BEGIN
L 0: R3=R3+5;
STAT(0)
    STR(0x10ff6,"Hola mundo\n");   // U(0x11ff6)='f' .. U(0x11fff)='\0' (10 bytes) 
CODE(0)
	R1=0x10ff6;             // pasa direccion de "fibo(%i)=" 
    	R2=0;                   // pasa i
    	R0=-2;                   // pasa direccion de retorno 
    	GT(putf_);

END
