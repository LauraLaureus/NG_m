#include "Q.h"
    BEGIN
	STAT(0)
	CODE(0)
L 1000:	STAT(1)
		STR(0x11fe4, "valor de n en la llamada ");
	CODE(1)
L 1:	R1=0x11fe4;
	R2=0;
	R0=2;
	GT(putf_);
L 2:	STAT(2)
	STR(0x11fe0, "%f\n");
	CODE(2)
L 3:	R1=0x11fe0;
	RR2=D(R6+8);
	R0=4;
	GT(putd_);
L 4:	STAT(3)
		STR(0x11fdb, "\n");
	CODE(3)
L 5:	R1=0x11fdb;
	R2=0;
	R0=6;
	GT(putf_);
L 6://Flow control start
//Execute flow control expression
L 7:	R7=R7-8;
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
L 8://check flow control expression
IF(!RR1) GT(9);
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
	RR1=RR1+RR2;
	R7=R7-8;
	D(R7)=RR1;
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
//Flow control start
//Execute flow control expression
L 13:	R7=R7-8;
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
L 14://check flow control expression
IF(!RR1) GT(15);
//Flow control BLOCK start

//asignation an expression to a variable

//generate the expression code
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
L 16:	RR0=D(R0);
	D(R6+8)=RR0;
	R3=R2;

//check if the asignation has finished because it was a real or the vector has ended.
	L 17: IF(!R3) GT(18);
	RR0=D(R1);
	D(R6+8)=RR0;
	R3=R2;

//continue in loop while asignation of every vector element wasn't done.
	GT(17);
	L 18:L 15://Flow control end
//Flow control start
//Execute flow control expression
L 19:	R7=R7-8;
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
L 20://check flow control expression
IF(!RR1) GT(21);
//Flow control BLOCK start
//Real asignation
	R7=R7-8;
	D(R7)=0.000000;
//Real asignation
	R7=R7-8;
	D(R7)=0.000000;

//asignation an expression to a variable

//generate the expression code
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
L 22:	RR0=D(R0);
	D(R6+-80)=RR0;
	R3=R2;

//check if the asignation has finished because it was a real or the vector has ended.
	L 23: IF(!R3) GT(24);
	RR0=D(R1);
	D(R6-80)=RR0;
	R3=R2;

//continue in loop while asignation of every vector element wasn't done.
	GT(23);
	L 24:
//asignation an expression to a variable

//generate the expression code
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
L 25:	RR0=D(R0);
	D(R6+-88)=RR0;
	R3=R2;

//check if the asignation has finished because it was a real or the vector has ended.
	L 26: IF(!R3) GT(27);
	RR0=D(R1);
	D(R6-88)=RR0;
	R3=R2;

//continue in loop while asignation of every vector element wasn't done.
	GT(26);
	L 27:
//asignation an expression to a variable

//generate the expression code
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
L 28:	RR0=D(R0);
	D(R6+8)=RR0;
	R3=R2;

//check if the asignation has finished because it was a real or the vector has ended.
	L 29: IF(!R3) GT(30);
	RR0=D(R1);
	D(R6+8)=RR0;
	R3=R2;

//continue in loop while asignation of every vector element wasn't done.
	GT(29);
	L 30:L 21://Flow control end
	RR0=D(R6+8);
	R7=R6;
	R5=I(R6); //Load label to jump 
	GT(R5);
L 0:	R6=R7;
//Real asignation
	R7=R7-8;
	D(R7)=2.000000;
//Real asignation
	R7=R7-8;
	D(R7)=0.000000;
//Generate code of function call
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
	R5=31;
	R7=R7-4;
	I(R7)=R5;
	R6=R7;
	GT(1000);
L 31:	R6=I(R7+4);
 //Return from function call
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
L 32:	R1=0x11fcd;
	R2=0;
	R0=33;
	GT(putf_);
L 33:	STAT(5)
	STR(0x11fc9, "%f\n");
	CODE(5)
L 34:	R1=0x11fc9;
	RR2=D(R6-16);
	R0=35;
	GT(putd_);
L 35:	STAT(6)
		STR(0x11fc4, "\n");
	CODE(6)
L 36:	R1=0x11fc4;
	R2=0;
	R0=37;
	GT(putf_);
L 37:GT(-2);
END