//
//  ASTNodes.hpp
//  ASTNodes
//
//  Created by Laura del Pino Díaz on 10/4/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//
#pragma once
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class Node{
public:
    Node(){};
    virtual void roam() = 0;
    virtual bool searchByHeight( string* id, int currentDepth, int maxDepth) = 0;
    virtual string generateCode(string head) = 0;

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
    
    string generateCode(string head){
        return head;
    }
};


class VECTOR_Asignation: public Node{
    bool declaration;
    std::string* identification;
    std::vector<double>* value;
    int limit;
    
    
public:
    VECTOR_Asignation(bool d, std::string* id, std::vector<double> v,int lim){
        this->declaration = d;
        this->identification = id;
        this->value = &v;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
    }
    
    void roam(){
        printf("Terminal node. Asignation Tipe VECTOR ELEMENT to variable. Identifiers: %s and %s.\n", identification->c_str(), value->c_str());
    };
    
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        if(currentDepth > maxDepth) return false;
        if(this->identification->compare(*id) != 0  ) return false;
        else return true;
    }
    
    string generateCode(string head){
        return head;
    }
};


////////////////MATH EXPRESSIONS

template <class Data>
class Math_Term : public Node {
    Data value;
public:
    
    Math_Term(Data d){
        this->value = d;
    }
    void roam(){
         printf("Terminal node. Mathematical Terminal. \n");
    };
    
    bool searchByHeight( string* id, int currentDepth, int maxDepth) {
        return false;
    }
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
    }
};

class Output_Expression: public Node{
    bool searchForVariable; //if not the expression will be evaluated and the result will be printed
    std::string* str;
public:
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
    }
};


////////////////////////DECLARATION
class Declaration : public Node {
    bool real; //for true is an real otherwise is a vector
    std::string* identification;
public:
    Declaration(std::string* id,bool r){
        this->identification = id;
        this->real = r;
    }
    
    bool isReal(){
        return this->real;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
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
            printf("SearchByHeight: flow control %d th son\n",i);
            if(block[i]->searchByHeight(id, currentDepth+1, maxDepth)) return true;
        }
        return returnable;
    }
    
    string generateCode(string head){
        return head;
    }
};

/*class NewBlock : public Node{
    int depth;
public:
    NewBlock(int d){
        this->depth = d;
    };
    void roam(){
        printf("Separator node. New block Current depth %d\n", this->depth);
    };
};


class ResumeBlock: public Node{
    int depth;
public:
    ResumeBlock(int d){
        this->depth = d;
    };
    int getDepth(){ return this->depth;};
    void roam(){
        printf("Separator node. Resume Previous block. Current depth %d\n",this->depth);
    };
};*/


class FunctionDefinition: public Node{
    std::string* id;
    bool returnSthg;
    std::vector<Node*> params;
    std::vector<Node*> lines;
    Node* returnNode;
    
public:
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
    
    string generateCode(string head){
        return head;
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
    
    string generateCode(string head){
        return head;
    }
};

