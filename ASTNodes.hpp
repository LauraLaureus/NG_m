//
//  ASTNodes.hpp
//  ASTNodes
//
//  Created by Laura del Pino Díaz on 10/4/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//


#pragma once
#include <stdio.h>
#include <sstream>
#include "data_type.h"
#include "global.h"
#include <math.h>



using namespace std;

extern int label;
extern int relativePositionToR6;

/////////////////NODESS

class Node{
public:
    Node(){};
    virtual void roam() = 0;
    virtual bool searchByHeight( string* id, int currentDepth, int maxDepth) = 0;
    virtual string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts) = 0;

    
    
    std::string mallocR7(int requestedSpace){
        relativePositionToR6 -= requestedSpace;
        return "\tR7=R7-" + std::to_string(requestedSpace) + ";\n";
    }
    
    std::string freeR7(int freeSpace){
        relativePositionToR6 += freeSpace;
        return "\tR7=R7+" + std::to_string(freeSpace) + ";\n";
    }

};

class REAL_Asignation: public Node{
    bool asignation;
    std::string* identification;
    double value;
    
public:
    REAL_Asignation(bool d, std::string* id, double v){
        this->asignation = d;
        this->identification = id;
        this->value = v;
    };
    
    void roam(){
        printf("This is a asignation: %d ; This is the identification: %s ; This is the value %F\n",
               this->asignation,
               this->identification->c_str(),
               this->value
               );
    }
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0) return false;
        else return true;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts ){
        std::string result;
        
    
        result += "//Real asignation\n";
        int mem_dir;
        if (ts->getRecord(*identification)->isGlobal()) {
            mem_dir = ts->getRecord(*identification)->getAddress();
            
            stringstream mem_pos_conversor;
            mem_pos_conversor << std::hex << mem_dir;
            result += "\tDAT(0x" + mem_pos_conversor.str() + ",D," + std::to_string(this->value) +");\n";
            
        }else{

            //relativePositionToR6 -= sizeof(double);
            
            //printf(("asignated relative position to " + (*identification) + " is %d\n").c_str(),(relativePositionToR6));
            
            
            result += mallocR7(8);
            ts->getRecord(*identification)->setAddress(relativePositionToR6);
            result += "\tD(R7)=" + std::to_string(this->value) + ";\n";
        }
        
        
        return result;
    }
};


class VECTOR_Asignation: public Node{
    bool declaration;
    std::string* identification;
    std::vector<double> value;
    int limit;
    
    
public:
    VECTOR_Asignation(bool d, std::string* id, std::vector<double> v,int lim){
        this->declaration = d;
        this->identification = id;
        this->value = v;
        this->limit = lim;
    };
    void roam(){
        printf("Terminal node. Asignation Type VECTOR. Identifier: %s\n", identification->c_str());
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0) return false;
        else return true;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        std::string result;
        *staticLabel += 1; //calculate label position.
        
        result += "\tSTAT(" +  std::to_string(*staticLabel) + ")\n";
        
        stringstream mem_pos_conversor;
        
        int mem_dir;
        if (ts->getRecord(*identification)->isGlobal()) {
            mem_dir = ts->getRecord(*identification)->getAddress();
        }else{
            *staticMem -= sizeof(double);
            ts->getRecord(*identification)->setAddress(*staticMem);
            mem_dir = *staticMem;
        }
        
        for (int i = this->value.size()-1; i >-1 ; i--) {
            mem_dir -= sizeof(double);
            mem_pos_conversor << std::hex << (mem_dir);
            result += "\tDAT(0x" + mem_pos_conversor.str() + ",D," + std::to_string(this->value[i]) +");\n";
            mem_pos_conversor.str("");
        }
        
        
        ts->getRecord(*identification)->setAddress(mem_dir);
        ts->getRecord(*identification)->setArrayOfDoublesValue(value);
        
        *staticMem = mem_dir;
        
        *codeLabel += 1;
        result += "\tCODE(" + std::to_string(*codeLabel) +")\n";
        
        label +=1;
        result+= "L " + std::to_string((label)) + ":";

        
        return result;
    }
};


class ELEM_VECTOR_Asignation: public Node{
    std::string* identification;
    int position;
    double value;
    
public:
    ELEM_VECTOR_Asignation (std::string* id,int pos, double v){
        this->identification = id;
        this->position = pos;
        this->value = v;
    }
    void roam(){
        printf("Terminal node. Asignation Tipe VECTOR element. Identifier: %s\n", identification->c_str());
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0) return false;
        else return true;
    }
    
    string generateCode( int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        SymbolTableRecord* r = ts->getRecord(*identification);
        
        if(r->getType() != DataTypeVector){
           printf("Intento de acceder a un subíndice en un tipo de dato que no es un vector\n");
           exit(-2);
        }
        
        if(this->position >= r->vectorSize() ){
            printf("Intento de acceder a un subíndice fuera de los límites del vector\n");
            exit(-2);
        }
        
        int mem_pos = r->getAddress() + position*sizeof(double);
        stringstream mem_pos_conversor;
        mem_pos_conversor << std::hex << mem_pos;
        result += "D(0x" + mem_pos_conversor.str() + ")=" + std::to_string(value) + ";\n";
        
        return result;
    }
};

class VAR2VAR_Asignation: public Node{
    std::string* var1;
    std::string* var2;

public:
    VAR2VAR_Asignation (std::string* id,std::string* id2){
        this->var1 = id;
        this->var2 = id2;
    }
    void roam(){
         printf("Terminal node. Asignation Tipe variable to variable. Identifiers: %s and %s\n", var1->c_str(),var2->c_str());
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->var1->compare(*id) != 0  ) return false;
        else return true;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        stringstream mem_pos_conversor;
        
        if((*ts)[*var1].getType() == (*ts)[*var2].getType()){
            
            if((*ts)[*var1].getType() == real){
                
                mem_pos_conversor << std::hex << (*ts)[*var2].getAddress();
                result += "\tRR1=D(0x"+mem_pos_conversor.str() + ");\n";
                mem_pos_conversor.str("");
                mem_pos_conversor << std::hex << (*ts)[*var1].getAddress();
                result += "\tD(0x" +mem_pos_conversor.str() + ")=RR1;\n";
            }
            else{
                float min = fmin((*ts)[*var1].vectorSize(),(*ts)[*var2].vectorSize());
                mem_pos_conversor << std::hex << (*ts)[*var2].getAddress();
                result += "\tRR1=D(0x" + mem_pos_conversor.str() + ");\n";
                
                for(int i = 0; i < min; i++){
                    mem_pos_conversor.str("");
                    mem_pos_conversor << std::hex << (*ts)[*var1].getAddress() + i*sizeof(double);
                    result += "\tD(0x" + mem_pos_conversor.str() + ")=RR1;\n";
                    
                    mem_pos_conversor.str("");
                    mem_pos_conversor << std::hex << (*ts)[*var2].getAddress() + i*sizeof(double);
                    result += "\tRR1=D(0x" + mem_pos_conversor.str() + ");\n";
                }
            }
        }else{
            
            if((*ts)[*var1].getType() == real){
                mem_pos_conversor << std::hex << (*ts)[*var2].getAddress()+((*ts)[*var2].vectorSize()-1)*sizeof(double);
                result += "\tRR1=D(0x"+mem_pos_conversor.str() + ");\n";
                mem_pos_conversor.str("");
                mem_pos_conversor << std::hex << (*ts)[*var1].getAddress();
                result += "\tD(0x" +mem_pos_conversor.str() + ")=RR1;\n";
            }
            
            else{
                
                mem_pos_conversor << std::hex << (*ts)[*var2].getAddress();
                result += "\tRR1=D(0x" + mem_pos_conversor.str() + ");\n";
                
                for(int i = 0; i < (*ts)[*var1].vectorSize() ; i++){
                    mem_pos_conversor.str("");
                    mem_pos_conversor << std::hex << (*ts)[*var1].getAddress() + i*sizeof(double);
                    result += "\tD(0x" + mem_pos_conversor.str() + ")=RR1;\n";
                }
            }
        
        }
        
        return result;
    }
};


class ELEM_VECTOR2VAR_Asignation: public Node{
    std::string* identification;
    int position;
    std::string* value; //destiny variable
    std::string* var_pos;
    
public:
    ELEM_VECTOR2VAR_Asignation (std::string* id,int pos, std::string* v){
        this->identification = id;
        this->position = pos;
        this->value = v;
    }
    
    ELEM_VECTOR2VAR_Asignation (std::string* id,std::string* pos, std::string* v){
        this->identification = id;
        this->var_pos = pos;
        this->value = v;
        this->position = -1;
    }
    
    void roam(){
        printf("Terminal node. Asignation Tipe VECTOR ELEMENT to variable. Identifiers: %s and %s.\n", identification->c_str(), value->c_str());
    };
    
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0  ) return false;
        else return true;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        stringstream mem_pos_conversor;
        if(position >-1){
            int memPos = (*ts)[*identification].getAddress()+((*ts)[*identification].vectorSize()-1-position)*sizeof(double);
            mem_pos_conversor << std::hex << memPos;
            result += "\tRR0=D(0x" + mem_pos_conversor.str() + ");\n";
            
            mem_pos_conversor.str("");
            mem_pos_conversor << std::hex << (*ts)[*value].getAddress();
            result +="\tD(0x" + mem_pos_conversor.str() +")=RR0;";
        }
        else{
            int memPos = (*ts)[*var_pos].getAddress();
            mem_pos_conversor << std::hex << memPos;
            result += "\tRR0=D(0x" + mem_pos_conversor.str() + ");\n"; //se obtiene el valor de la variable
            (label) += 1;
            result +="\tR0=" + std::to_string(label) + ";\n"; //se indica a donde volver
            result += "\tGT(cast_);\n";
            result +="L " + std::to_string(label) + ":" ;
            
            
            mem_pos_conversor.str("");
            memPos = (*ts)[*identification].getAddress()+((*ts)[*identification].vectorSize()+1)*sizeof(double);
            mem_pos_conversor << std::hex << memPos;
            result += "\tR2=0x" + mem_pos_conversor.str() + ";\n";
            result += "\tR1=R1*"+ std::to_string(sizeof(double)) +";\n";
            result += "\tR1=R1+"+ std::to_string(sizeof(double)) +";\n";
            result += "\tRR0=D(R2-R1);\n";
            
            mem_pos_conversor.str("");
            mem_pos_conversor << std::hex << (*ts)[*value].getAddress();
            result +="\tD(0x" + mem_pos_conversor.str() +")=RR0;";
        }
        return result;
    }
};


////////////////MATH EXPRESSIONS

template <class Data>
class Math_Term : public Node {
    Data value_d;
public:
    
    Math_Term(Data d){
        this->value_d = d;
    }
    void roam(){
         printf("Terminal node. Mathematical Terminal. \n");
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    string generateCode( int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        result += toStack(value_d,codeLabel,staticLabel,staticMem,ts);
        
        return result;
    }
    
    string toStack(double d, int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;

        result +="n";
        result += mallocR7(sizeof(double));
        result += "\tRR1="+ std::to_string(d) + ";\n";
        result += "\tD(R7)=RR1;\n";
        
        return result;
    }
    
    string toStack(string d,int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        

        int dir = (*ts)[d].getAddress();
        stringstream mem_pos_conversor;
        if((*ts)[d].getType() == real){
                result +="n";
            
                result += mallocR7(sizeof(double));
                if (dir >= 0 ){
                    result += "\tRR3=D(R6+"+std::to_string(dir)+");\n";
                }else{
                    result += "\tRR3=D(R6"+std::to_string(dir)+");\n";
                    
                }
            
                result += "\tD(R7)=RR3;\n";
        }else{
                result +="v";
            
                int length = (*ts)[d].vectorSize();
                int dir_endPoint = dir + length*sizeof(double); //primer elemento
                result += mallocR7(sizeof(double));
                int stack_position;
            for (int i = 0; i < length; i++) {
                stack_position = (length-i-1)*sizeof(double);
                
                mem_pos_conversor <<std::hex << dir;
                
                result +="\tRR3=D(0x" +mem_pos_conversor.str()+");\n";
                result += "\tD(R7+" +std::to_string(stack_position)+")=RR3;\n";
                
                mem_pos_conversor.str("");
                dir -=sizeof(double);
            }
        }
        
        
        return result;
    }
    
    std::string toReturnRegister(SymbolTable* ts){
        return toRR0(value_d,ts);
    }
    
    std::string toRR0(double d,SymbolTable* ts){
        return "\tRR0=" + std::to_string(d) +";\n";
    }
    
    std::string toRR0(std::string d,SymbolTable* ts){
        
        int dir = ts->getRecord(d)->getAddress();
        
        if(dir < 0){
            return "\tRR0=D(R6" + std::to_string(dir) + ");\n";
        }else{
            return "\tRR0=D(R6+" + std::to_string(dir) + ");\n";
        }
    }
};



class Math_Expression: public Node{
    Node* term1;
    Node* term2;
    int op;

public:
    Math_Expression(Node* t1, int o, Node* t2){
        this->term1 = t1;
        this->term2 = t2;
        this->op = o;
    }
    void roam(){
        printf("Start of mathematical expression....\n");
        term1->roam();
        term2->roam();
        printf("End of mathematical expression....\n");
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;

        string result1  = term1->generateCode(codeLabel,staticLabel,staticMem,ts);
        string result2  = term2->generateCode(codeLabel,staticLabel,staticMem,ts);
        
        char type_t1, type_t2;
        type_t1 = result1.at(0);
        type_t2 = result2.at(0);
        
        result1 = result1.substr(1);
        result2 = result2.substr(1);
        
        result += result1;
        result += result2;
        
        //DO this when n & n
        if(type_t1 == type_t2 && type_t1 == 'n'){
            
            result += "\tRR2=D(R7);\n";
            result += "\tRR1=D(R7+" + std::to_string(sizeof(double)) + ");\n";
            
            switch (op) {
                case '+':
                    result += "\tRR1=RR1+RR2;\n";
                    break;
                case '-':
                    result += "\tRR1=RR1-RR2;\n";
                    break;
                    
                case '*':
                    result += "\tRR1=RR1*RR2;\n";
                    break;
                    
                case '/':
                    result += "\tRR1=RR1/RR2;\n";
                    break;
                case '=':
                    result += "\tRR1=RR1==RR2;\n";
                    break;
                case '~':
                    result += "\tRR1=RR1!=RR2;\n";
                    break;
                case '>':
                    result += "\tRR1=RR1>RR2;\n";
                    break;
                case '<':
                    result += "\tRR1=RR1<RR2;\n";
                    break;
                case 'Z':
                    result += "\tRR1=RR1>=RR2;\n";
                    break;
                case 'z':
                    result += "\tRR1=RR1<=RR2;\n";
                    break;
                    //Operaciones lógicas no admitidas para los reales.
            }
            
            result += freeR7(sizeof(double));
            //relativePositionToR6 -= sizeof(double);
            result += "\tD(R7)=RR1;\n";
            result += "\tR0=R7;\n";
            
        }else if(type_t1 == type_t2 && type_t1 == 'v'){
        
            
            result += "\tR5=R6-R7;\n";
            result += "\tR5=R5/8;\n";
            result += "\tR5=R5%2;\n";
            result += "\tR0=-2;\n";
            result += "\tIF(!R5) GT(exit_);\n";
            result += "\tR4=R6-R7;\n";
            result += "\tR4=R4/2;\n";
            result += "\tR5=R7;\n";
            result += "\tR3=R6-R4;\n";
            (label) +=1;
            int n_l = (label);
            result += "L " + std::to_string((label)) + ":";
            (label) +=1;
            result += "IF(!R3) GT(" + std::to_string((label)) +");\n";
            result += "\tRR1=D(R4);\n";
            result += "\tRR2=D(R5);\n"; //da 8.
            switch (op) {
                case '+':
                    result += "\tRR1=RR1+RR2;\n";
                    break;
                case '-':
                    result += "\tRR1=RR1-RR2;\n";
                    break;
                    
                case '*':
                    result += "\tRR1=RR1*RR2;\n";
                    break;
                    
                case '/':
                    result += "\tRR1=RR1/RR2;\n";
                    break;
                case '=':
                    result += "\tRR1=RR1==RR2;\n";
                    break;
                case '~':
                    result += "\tRR1=RR1!=RR2;\n";
                    break;
                case '>':
                    result += "\tRR1=RR1>RR2;\n";
                    break;
                case '<':
                    result += "\tRR1=RR1<RR2;\n";
                    break;
                case 'Z':
                    result += "\tRR1=RR1>=RR2;\n";
                    break;
                case 'z':
                    result += "\tRR1=RR1<=RR2;\n";
                    break;
                    //Operaciones lógicas no admitidas para los reales.
            }
            result += "\tD(R5)=RR1;\n";
            result += "\tR5=R5+8;\n";
            result += "\tR4=R4+8;\n";
            result += "\tR3=R6-R4;\n";
            result += "\tGT("+std::to_string(n_l)+");\n";
            result += "\tR0=-1;\n";
            result += "\tR1=R7;\n";
            result += "\tR2=R6-R7;\n";
            result += "\tR2=R2/8;\n";
            
        }else{
            
        
            if(type_t1 == 'n'){ // el real estará en el fondo de la pila
                result += "\tR5=R6-" +std::to_string(sizeof(double)) +";\n";
                result += "\tRR1=D(R5);\n";
                result += "\tR5=R5-"+ std::to_string(sizeof(double)) +";\n";
                result += "\tR0=R5;\n";
                result += "\tR1=R7;\n";
                
            }else{ // el real estará en la cima de la pila
                result +=  "\tR5=R7-"+ std::to_string(sizeof(double)) +";\n";
                result += "\tRR1=D(R5);\n";
                result +=  "\tR5=R6-"+ std::to_string(sizeof(double)) +";\n";
                result += "\tR0=R7;\n";
                result += "\tR1=R7+8;\n";
            }
            
            result +=  "\tR3=R5+8;\n";
            result +=  "\tR4=R7-R3;\n";
            
            (label) +=1;
            int n_l = (label);
            result += "L " + std::to_string((label)) + ":";
            (label) +=1;
            result += "IF(!R4) GT(" + std::to_string((label)) +");\n";
            result += "\tRR2=D(R5);\n";
            switch (op) {
                case '+':
                    result += "\tRR1=RR1+RR2;\n";
                    break;
                case '-':
                    result += "\tRR1=RR1-RR2;\n";
                    break;
                    
                case '*':
                    result += "\tRR1=RR1*RR2;\n";
                    break;
                    
                case '/':
                    result += "\tRR1=RR1/RR2;\n";
                    break;
                case '=':
                    result += "\tRR1=RR1==RR2;\n";
                    break;
                case '~':
                    result += "\tRR1=RR1!=RR2;\n";
                    break;
                case '>':
                    result += "\tRR1=RR1>RR2;\n";
                    break;
                case '<':
                    result += "\tRR1=RR1<RR2;\n";
                    break;
                case 'Z':
                    result += "\tRR1=RR1>=RR2;\n";
                    break;
                case 'z':
                    result += "\tRR1=RR1<=RR2;\n";
                    break;
                    //Operaciones lógicas no admitidas para los reales.
            }
            result += "\tR5=R5-"+ std::to_string(sizeof(double)) +";\n";
            result +=  "\tR3=R5+8;\n";
            result +=  "\tR4=R7-R3;\n";
            result += "\tGT("+std::to_string(n_l)+");\n";
            result += "\tR2=R6-R7;\n";
            result += "\tR2=R2/8;\n";
            result += "\tR2=R2-1;\n";
        
        }
        (label) += 1;
        result += "L " + std::to_string((label)) + ":";
        
        //Limpiar la pila. NO SE LIMPIA LA PILA para mantener en la pila el vector resultado. R0 indica donde comienza el entero  R1 indica donde comienza el vector. R2 indica el número de elementos.

        
        
        return result;
    }
};

class Output_Expression: public Node{
   
public:
    bool searchForVariable; //if not the expression will be evaluated and the result will be printed
    std::string* str;
    
    Output_Expression(bool var, std::string* string){
        this->searchForVariable = var;
        this->str = string;
    }
    void roam(){
        printf("Terminal node. Output Terminal. \n");
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    string generateCode( int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        std::string result;
        if(!searchForVariable){
            result = genCodeForString(codeLabel, staticLabel,staticMem,ts);
        }else{
            
            if (ts->getRecord(*str)->getType() == real) {
                result = genCodeForReal(codeLabel, staticLabel,staticMem,ts);
            }else{
                result = genCodeForVector(codeLabel, staticLabel,staticMem,ts);
            }
        }
        
        return result;
    }
    
private:
    string genCodeForString( int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        
        std::string result;
        *staticLabel += 1; //calculate label position.
        stringstream label_str_conversor;
        label_str_conversor << *staticLabel;
        
        result += "\tSTAT("+label_str_conversor.str()+")\n";
        

        //For string
        *staticMem -= ((*str).size()+1); //calculate mem position.
        stringstream mem_str_conversor;
        mem_str_conversor << std::hex << *staticMem;
        string str_memPos = mem_str_conversor.str();
        
        
        result += "\t\tSTR(0x" + str_memPos + ", "+ *(this->str) +");\n";
        
        
        stringstream code_label_conv;
        (*codeLabel) +=1;
        code_label_conv << (*codeLabel);
        result += "\tCODE(" + code_label_conv.str() + ")\n";
        
        
        stringstream label_converter;
        (label) += 1;
        label_converter << (label);
        result += "L " + label_converter.str() + ":";
        
        result += "\tR1=0x"+ str_memPos + ";\n";
        result += "\tR2=0;\n";
        (label) += 1;
        result += "\tR0=" + std::to_string((label))+";\n";//TODO modify this with the return label.
        
        
        result+= "\tGT(putf_);\n";
        
        result+= "L " + std::to_string((label)) + ":";
        return result;
    }
    
    string genCodeForReal(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        
        std::string result;
        *staticLabel += 1; //calculate label position.
        stringstream label_str_conversor;
        label_str_conversor << *staticLabel;
        
        result += "\tSTAT("+label_str_conversor.str()+")\n";
        
        string formatStr = "%f\n";
        
        *staticMem -= ((formatStr).size()+1); //calculate mem position.
        stringstream mem_str_conversor;
        mem_str_conversor << std::hex << *staticMem;
        string fstr_memPos = "0x" + mem_str_conversor.str();
        result += "\tSTR("+fstr_memPos+", \"%f\\n\");\n";
        
        
        *codeLabel +=1;
        stringstream code_label_conv;
        code_label_conv << (*codeLabel);
        result += "\tCODE(" + code_label_conv.str() + ")\n";
        
        
        label +=1;
        result += "L " + std::to_string((label)) + ":";
        
        result += "\tR1="+ fstr_memPos + ";\n";
        
        if(ts->getRecord((*str))->getAddress() < 0){
            result += "\tRR2=D(R6" + std::to_string(ts->getRecord((*str))->getAddress()) + ");\n";
        }else{
            result += "\tRR2=D(R6+" + std::to_string(ts->getRecord((*str))->getAddress()) + ");\n";
        }
        
        (label) += 1;
        result += "\tR0=" + std::to_string((label))+";\n";
        
        
        result+= "\tGT(putd_);\n";
        
        result+= "L " + std::to_string((label)) + ":";
        
        return result;
    }
    
    string genCodeForVector(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        std::string result;
        *staticLabel += 1; //calculate label position.
        stringstream label_str_conversor;
        label_str_conversor << *staticLabel;
        
        result += "\tSTAT("+label_str_conversor.str()+")\n";
        
        string formatStr = "%f\n";
        
        *staticMem -= ((formatStr).size()+1); //calculate mem position.
        stringstream mem_str_conversor;
        mem_str_conversor << std::hex << *staticMem;
        string fstr_memPos = "0x" + mem_str_conversor.str();
        result += "\tSTR("+fstr_memPos+", \"%f\\n\");\n";
        
        *codeLabel +=1;
        stringstream code_label_conv;
        code_label_conv << (*codeLabel);
        result += "\tCODE(" + code_label_conv.str() + ")\n";
        
        result += "\tR1="+ fstr_memPos + ";\n";
        
       
        stringstream double_memPos;
        
        for(int i= 0; i < ts->getRecord(*str)->vectorSize(); i++){
        
            (label) += 1;
            
            double_memPos << std::hex << ts->getRecord((*str))->getAddress() + i*sizeof(double);
            result += "\tRR2=D(0x"+double_memPos.str()+");\n";
            result += "\tR0=" + std::to_string((label)) + ";\n";
            result += "\tGT(putd_);\n";
            result += "L " + std::to_string(label) + ":";
            
            double_memPos.str("");
        }
        return result;
    }
};

class BreakNode : public Node{
public:
    BreakNode(){};
    void roam(){
        printf("Terminal node. Break Terminal. \n");
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
       
        //return "\tGT(" + std::to_string((*relativePositionToR6)) + ");\n";
        return "";
    }
};


/////////////////////ASIGNATION AN EXPRESSION

class Expression2Var : public Node{ //Cambiar la herencia a Node?
    std::string* identification;
    int position;
    Node* expression;
    
public:
    Expression2Var(std::string* id, Node* n){
        this->identification = id;
        this->expression = n;
        this->position = -1;
    }
    
    Expression2Var(std::string* id,int p, Node* n){
        this->identification = id;
        this->expression = n;
        this->position = p;
    }
    void roam(){
        printf("Asignation of an expression. Identifier: %s ", identification->c_str());
        expression->roam();
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0  ) return false;
        else return true;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        result += "\n//asignation an expression to a variable\n";
        result += "\n//generate the expression code\n";
        result += expression->generateCode(codeLabel,staticLabel,staticMem,ts);
        //R0 tiene la dirección del real
        //R1 tiene la direccion del vector
        //R2 tiene el número de elementos
        
        stringstream mem_pos_conversor;
        
        int memPos = (*ts)[*identification].getAddress();
        printf(("direction of " + (*identification) + " is %d\n").c_str(), memPos);
        
        if((*ts)[*identification].getType() == real){
            result+="\tRR0=D(R0);\n";
            
            if(memPos >= 0){
                result += "\tD(R6+" +std::to_string(memPos)+")=RR0;\n";
            }
            else{
                result += "\tD(R6+" +std::to_string(memPos)+")=RR0;\n";
            }
        }
        
        result += freeR7(8);
        //result += "\tR3=R2;\n";
        (label) += 1;
        int n_l = (label);
        /*(label) += 1;
        result += "\n//check if the asignation has finished because it was a real or the vector has ended.\n";
        result += "\tL " + std::to_string(n_l) + ": IF(!R2) GT(" + std::to_string((label)) +");\n"; //mientras R3 no llegue a 0.
        result += "\tRR0=D(R1);\n";
        if(memPos >= 0){
            result += "\tD(R6+" +std::to_string(memPos)+")=RR0;\n";
        }
        else{
            result += "\tD(R6" +std::to_string(memPos)+")=RR0;\n";
        }
        
        //result += "\tR3=R2;\n";
        memPos += 8;
        mem_pos_conversor.str("");
        result += "\n//continue in loop while asignation of every vector element wasn't done.\n";
        result += "\tGT(" + std::to_string(n_l) + ");\n";*/
        result += "\tL " + std::to_string((label)) + ":";
        
        return result;
    }
};


////////////////////////DECLARATION
class Declaration : public Node {
    bool real_type; //for true is an real otherwise is a vector
    std::string* identification;
public:
    Declaration(std::string* id,bool r){
        this->identification = id;
        this->real_type = r;
    }
    
    bool isReal(){
        return this->real_type;
    }
    
    std::string* getIdentification(){
        return this->identification;
    }
    
    void roam(){
        printf("Terminal node. Declaration. Is it a REAL? %d. Identification: %s\n",real,identification->c_str());
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0  ) return false;
        else return true;
    }
    
    //Las declaraciones dejan su valor en la cima de la pila, si lo tienen.
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
       
        
        
            stringstream mem_pos_conversor;
            if((*ts)[*identification].getType() == real){
                
               
                result += mallocR7(sizeof(double));
                
                
                int dir =(*ts)[*identification].getAddress();
                printf(" Dirección de la variable que se carga en la pil %d\n",dir);
                if (dir >= 0){
    
                    result += "\tRR0=D(R6+" + std::to_string(dir) +");\n";
                }
                else{
                    result += "\tRR0=D(R6" + std::to_string(dir) +");\n";
                }
                
                result += "\tD(R7)=RR0;\n";
                
            }else{
                //OJo posiciones relativas quitar el hexadecimal
                for (int i = (*ts)[*identification].vectorSize()-1; i > -1; i--) {
                    result += mallocR7(sizeof(double));
                    mem_pos_conversor <<std::hex << (*ts)[*identification].getAddress();
                    result += "\tRR0=D(" + mem_pos_conversor.str() +"\n";
                    result += "\tD(R7)=RR0;\n";
                    mem_pos_conversor.str("");
                }
            
            }
        //}
        
        return result;
    }
    
    
    void load(SymbolTable* ts,int* pos ){
        SymbolTableRecord r = *new SymbolTableRecord(false,real,-1,nullptr);
        r.setAddress((*pos));
        printf(("Carga: "+(*identification) +" en %d\n").c_str() ,(*pos));
        ts->insertRecord( *identification, r);
    }
};


/////////////////////////FUNCTION CALL
class FunctionCall: public Node{
    std::string* identification;
    std::vector<Node*>  params;
public:
    FunctionCall(std::string* id, std::vector<Node*> parm){
        this->identification = id;
        this->params = parm;
    }
    void roam(){
        printf("Non terminal node. Function call node. Calling params nodes: \n");
        for (int i = 0; i < params.size(); i++) {
            params[i]->roam();
        }
        printf("End of Params nodes.... Start of content nodes: \n");
        
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    std::string getIdentification(){
        return *(this->identification);
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        //Guarda todos los registros enteros
        
        result +="//Generate code of function call\n";
        result += mallocR7(sizeof(int)*6);
        //relativePositionToR6 -= sizeof(int)*6;
        result +="\tI(R7)=R0;\n";
        result +="\tI(R7+4)=R1;\n";
        result +="\tI(R7+8)=R2;\n";
        result +="\tI(R7+12)=R3;\n";
        result +="\tI(R7+16)=R4;\n";
        result +="\tI(R7+20)=R5;\n";
        
        
        //Guarda todos los registros en coma flotante
        result += mallocR7(sizeof(double)*3);
        //relativePositionToR6 -= sizeof(double)*3;
        //result += "\tR7=R7-24;\n";
        result +="\tD(R7)=RR1;\n";
        result +="\tD(R7+8)=RR2;\n";
        result +="\tD(R7+16)=RR3;\n";
        
        //Nota: no se guarda RR0 porque es en donde esperamos recibir el parámetro. :P
        
        result += "//Load params into stack\n";
        for (int i = 0; i < params.size(); i++) {
            Declaration* n = dynamic_cast<Declaration*>(params[i]);
            result += n->generateCode(codeLabel,staticLabel,staticMem,ts);
        }
        
        
        result += mallocR7(sizeof(int));
        //relativePositionToR6 -= sizeof(int);
        result += "\tI(R7)=R6;\n"; // se guarda la base de la pila
        
        
        (label) += 1;
        result += "\tR5=" + std::to_string((label)) + ";\n"; // se carga la etiqueta de retorno.
        result += mallocR7(sizeof(int));
        result += "\tI(R7)=R5;\n"; // se guarda la etiqueta de retorno en la pila
        
        result +="\tR6=R7;\n";//se modifica la base de la pila
        
        int func_label = (*ts)[*identification].getAddress();
        result += "\tGT(" + std::to_string(func_label) + ");\n"; //Nos movemos a la funcion
        
        
        result += "L " + std::to_string(label) + ":";
        result += "\tR6=I(R7+4);\n //Return from function call\n";
        result += freeR7(sizeof(int)*2);
        
        
        result += "\tRR1=D(R7);\n";
        result += "\tRR2=D(R7+8);\n";
        result += "\tRR3=D(R7+16);\n";
        result += freeR7(sizeof(double)*3);
        
        result += "\tR0=I(R7);\n";
        result += "\tR1=I(R7+4);\n";
        result += "\tR2=I(R7+8);\n";
        result += "\tR3=I(R7+12);\n";
        result += "\tR4=I(R7+16);\n";
        result += "\tR5=I(R7+20);\n";
        
        result += freeR7(sizeof(int)*6);
        
        return result;
    }
};


////////////////////////RETURN CALL
class ReturnNode: public Node{
    Node* return_value;
public:
    ReturnNode(Node* r){
        this->return_value = r;
    }
    void roam(){
        printf("Non Terminal node. Return statement.\n ");
        return_value->roam();
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        if(Math_Term<double>* n = dynamic_cast<Math_Term<double>* >(return_value)){
            result += n->toReturnRegister(ts);
        }
        
        if(Math_Term<std::string>* n = dynamic_cast<Math_Term<std::string>* >(return_value)){
            result += n->toReturnRegister(ts);
        }
        
        return result;
    }
};



class AsignationFunctionCall : public Node {
    std::string* identification;
    Node* expression;
    
    
public:
    AsignationFunctionCall(std::string* id, Node* n){
        this->identification = id;
        this->expression = n;
    }
    
    
    void roam(){
        printf("Non Terminal node. Storing a function return into a variable. Variable: %s \n", identification->c_str());
        expression->roam();
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0  ) return false;
        else return true;
    }
    
    std::string getFunctionIdentification(){
        
        if(FunctionCall* n = dynamic_cast<FunctionCall*>(this->expression)){
            return n->getIdentification();
        }
        return *new std::string;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        result += expression->generateCode(codeLabel,staticLabel,staticMem,ts);
        
        if((*ts)[*identification].getAddress() < 0)
            result += "\tD(R6" + std::to_string((*ts)[*identification].getAddress()) + ")=RR0;\n";
        else
            result += "\tD(R6+" + std::to_string((*ts)[*identification].getAddress()) + ")=RR0;\n";
        
        return result;
    }
};


class AsignationInput : public Node{
public:
    void roam(){
        printf("Terminal node asign input to variable");
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        //NO implementado.
        return "";
    }
};


class FlowControl : public Node {
    bool loop;
    Node* expression;
    std::vector<Node*> block;
    
public:
    FlowControl(bool l, Node* exp, std::vector<Node*> bl){
        this->loop = l;
        this->expression = exp;
        this->block = bl;
    };
    void roam(){
        printf("-------Non terminal node. FlowControl structure.-----\n Is it a loop? %d\n", loop);
        for (int i = 0; i < block.size(); i++) {
            printf("%d\n", i);
            block[i]->roam();
        }
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        bool returnable = false;
        for (int i = 0; i< block.size(); i++) {
            //printf("SearchByHeight: flow control %d th son\n",i);
            if(block[i]->searchByHeight(id, currentDepth+1, maxDepth)) return true;
        }
        return returnable;
    }
    
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
    
        result += "//Flow control start\n";
        result += "//Execute flow control expression\n";
        (label) += 1;
        int n_l = label;
        result += "L " + std::to_string(n_l) + ":";
        result += expression->generateCode(codeLabel,staticLabel,staticMem,ts);
        result += freeR7(8);
        
        
        (label) +=1;
        int e_l =(label);
        
        result += "//check flow control expression\n";
        result += "IF(!RR1) GT(" + std::to_string((e_l)) + ");\n";
        result += "//Flow control BLOCK start\n";
        
        
        int save = relativePositionToR6;
        int ll = label;
        for (int i = 0; i < block.size(); i++) {
            result += block[i]->generateCode(codeLabel,staticLabel,staticMem,ts);
        }
        relativePositionToR6 = save;
        
        if(loop){
            result += "//Reevaluate expresion and jump for loop only\n";
            result += expression->generateCode(codeLabel,staticLabel,staticMem,ts);
            result += freeR7(8);
            result += "\tGT(" + std::to_string(n_l) + ");\n";
            
        }
        result += "L " + std::to_string(e_l) + ":";
        result += "//Flow control end\n";
        return result;
    }
};


class FunctionDefinition: public Node{
    
    bool returnSthg;
    std::vector<Node*> params;
    std::vector<Node*> lines;
    Node* returnNode;
    
public:
    
    std::string* id;
    
    FunctionDefinition(std::string* i,std::vector<Node*> p,std::vector<Node*> l,bool ret,Node* thing){
        this->id = i;
        this->returnSthg = ret;
        this->params = p;
        this->lines = l;
        this->returnNode = thing;
    }
    
    FunctionDefinition(std::string* i,std::vector<Node*> p,std::vector<Node*> l){
        this->id = i;
        this->returnSthg = false;
        this->params = p;
        this->lines = l;
        this->returnNode = nullptr;
    }
    
    FunctionDefinition(std::string* i,std::vector<Node*> l){
        this->id = i;
        this->returnSthg = false;
        this->params = *new std::vector<Node*>();
        this->lines = l;
        this->returnNode = nullptr;
    }
    void roam(){
        printf("-----Not terminal node. Function definition.-----\n Next nodes are the Params \n");
        if(params.size() != 0){
            for (int i = 0; i < params.size(); i++) {
                params[i]->roam();
            }
        }
        printf("----End of params.-----\nStarting content\n");
        for (int i = 0; i < lines.size(); i++) {
            lines[i]->roam();
        }
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        bool returnable = false;
        for (int i = 0; i< lines.size(); i++) {
            returnable = returnable || lines[i]->searchByHeight(id, currentDepth+1, maxDepth);
        }
        return returnable;
    }
    
    string generateCode( int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        string result;
        
        SymbolTable duplicated_ts = ts->getACopyWithOutInit();
        duplicated_ts.printState();
        int pos = 0; //posición relativa
        for (int i = params.size()-1; i > -1; i--) {
            Declaration* d = dynamic_cast<Declaration*>(params[i]);
            if(d->isReal()){
                pos += 8;
                d->load(&duplicated_ts, &pos );
            }
            else{
                int v_pos = ts->getRecord(*(d->getIdentification()))->getAddress();
                 d->load(&duplicated_ts, &v_pos );
            }
            
        }
        duplicated_ts.printState();

        
        relativePositionToR6 = 0;

        
        for (int i = 0; i < lines.size(); i++) {
            result += lines[i]->generateCode(codeLabel,staticLabel,staticMem,&duplicated_ts);
            printf ("relative Position before calling the code node %d : %d\n" ,i,relativePositionToR6);
        }
        duplicated_ts.printState();
        
        if(returnNode != nullptr){
            result += returnNode->generateCode(codeLabel,staticLabel,staticMem,&duplicated_ts);

        }
        result += "\tR7=R6;\n";
        relativePositionToR6 = 0;
        result += "\tR5=I(R6); //Load label to jump \n";
        result += "\tGT(R5);\n";
        
        
        
        return result;
    }
};

class GlobalVar: public Node{
    Node* declaration;
public:
    GlobalVar(Node* declar){
        this->declaration = declar;
    }
    
    bool isReal(){
        return true;
    }
    
    void roam(){
        printf("------Global var declaration----\n");
        declaration->roam();
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        return this->declaration->searchByHeight(id, currentDepth,maxDepth);
    }
    
    //No genera código
    string generateCode(int* codeLabel, int* staticLabel,int* staticMem,SymbolTable* ts){
        return "";
    }
};

