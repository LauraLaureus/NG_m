#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 1000://Flow control start
//Execute flow control expression
	R7=R7-8;
	RR3=D(R6+8);
	D(R7)=RR3;
	R7=R7-8;
	RR1=0.000000;
	D(R7)=RR1;
	RR2=D(R7);
	RR1=D(R7+8);
	RR0=RR1==RR2;
	R7=R7-8;
	D(R7)=RR0;
	R0=R7;
L 1://check flow control expression
L 2:IF(!RR0) GT(3);
//Flow control BLOCK start

//asignation an expression to a variable

//generate the expression code
	R7=R7-8;
	RR1=0.000000;
	D(R7)=RR1;
	R7=R7-8;
	RR1=0.000000;
	D(R7)=RR1;
	RR2=D(R7);
	RR1=D(R7+8);
	RR0=RR1+RR2;
	R7=R7-8;
	D(R7)=RR0;
	R0=R7;
L 4:	RR0=D(R0);
	D(R6+8)=RR0;
	R3=R2;

//check if the asignation has finished because it was a real or the vector has ended.
	L 5: IF(!R3) GT(6);
	RR0=D(R1);
	D(R6+8)=RR0;
	R3=R2;

//continue in loop while asignation of every vector element wasn't done.
	GT(5);
	L 6:L 3://Flow control end
//Flow control start
//Execute flow control expression
	R7=R7-8;
	RR3=D(R6+8);
	D(R7)=RR3;
	R7=R7-8;
	RR1=1.000000;
	D(R7)=RR1;
	RR2=D(R7);
	RR1=D(R7+8);
	RR0=RR1==RR2;
	R7=R7-8;
	D(R7)=RR0;
	R0=R7;
L 7://check flow control expression
L 8:IF(!RR0) GT(9);
//Flow control BLOCK start

//asignation an expression to a variable

//generate the expression code
	R7=R7-8;
	RR1=1.000000;
	D(R7)=RR1;
	R7=R7-8;
	RR1=0.000000;
	D(R7)=RR1;
	RR2=D(R7);
	RR1=D(R7+8);
	RR0=RR1+RR2;
	R7=R7-8;
	D(R7)=RR0;
	R0=R7;
L 10:	RR0=D(R0);
	D(R6+8)=RR0;
	R3=R2;

//check if the asignation has finished because it was a real or the vector has ended.
	L 11: IF(!R3) GT(12);
	RR0=D(R1);
	D(R6+8)=RR0;
	R3=R2;

//continue in loop while asignation of every vector element wasn't done.
	GT(11);
	L 12:L 9://Flow control end
	R7=R6;
	R5=I(R6); //Load label to jump 
	GT(R5);
L 0:	R6=R7;
//Real asignation
	R7=R7-8;
	D(R7)=0.000000;
L 13://Real asignation
	R7=R7-8;
	D(R7)=0.000000;
L 14://Generate code of function call
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
//Load params into stack
	R7=R7-8;
	RR0=D(R6-8);
	D(R7)=RR0;
	R7=R7-4;
	I(R7)=R6;
	R5=15;
	R7=R7-4;
	I(R7)=R5;
	R6=R7;
	GT(1000);
L 15:	R6=I(R7+4);
 //Return from function call
	R7=R7+8;
	RR3=D(R7);
	RR2=D(R7+8);
	RR1=D(R7+16);
	R7=R7+24;
	R0=I(R7);
	R1=I(R7+4);
	R2=I(R7+8);
	R3=I(R7+12);
	R4=I(R7+16);
	R5=I(R7+20);
	R7=R7+24;
	D(R6-16)=RR0;
	STAT(1)
	STR(0x11ffc, "%f\n");
	CODE(1)
L 16:	R1=0x11ffc;
	RR2=D(R6-16);
	R0=17;
	GT(putd_);
L 17:GT(-2);
END