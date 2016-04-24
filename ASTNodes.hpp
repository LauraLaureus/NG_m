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

class Node{};

class Asignation:public Node{};

class REAL_Asignation: public Asignation{
    bool declaration;
    std::string* identification;
    double value;
    
public:
    REAL_Asignation(bool d, std::string* id, double v){
        this->declaration = d;
        this->identification = id;
        this->value = v;
    };
};


class VECTOR_Asignation: public Asignation{
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
};


class ELEM_VECTOR_Asignation: public Asignation{
    std::string* identification;
    int position;
    double value;
    
public:
    ELEM_VECTOR_Asignation (std::string* id,int pos, double v){
        this->identification = id;
        this->position = pos;
        this->value = v;
    }
};

class VAR2VAR_Asignation: public Asignation{
    std::string* var1;
    std::string* var2;

public:
    VAR2VAR_Asignation (std::string* id,std::string* id2){
        this->var1 = id;
        this->var2 = id2;
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
};
class Expression : public Node{};

class Math_Expression: public Expression{
    Node term1;
    Node term2;
    int op;

public:
    Math_Expression(Node t1, int o, Node t2){
        this->term1 = t1;
        this->term2 = t2;
        this->op = o;
    }

};

class Output_Expression: public Expression{
    bool searchForVariable; //if not the expression will be evaluated and the result will be printed
    std::string* str;
public:
    Output_Expression(bool var, std::string* string){
        this->searchForVariable = var;
        this->str = string;
    }
};

class BreakNode : public Node{
public:
    BreakNode(){};
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
    
};


/////////////////////////FUNCTION CALL
class FunctionCall: public Node{
    std::string* identification;
    std::vector<Node>*  params;
public:
    FunctionCall(std::string* id, std::vector<Node> parm){
        this->identification = id;
        this->params = &parm;
    }
};


////////////////////////RETURN CALL
class ReturnNode: public Node{
    Node* return_value;
public:
    ReturnNode(Node* r){
        this->return_value = r;
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
};


class AsignationInput : public Node{
};


class FlowControl : public Node {
    bool loop;
    Node* expression;
    std::vector<Node> block;
    
public:
    FlowControl(bool l, Node* exp, std::vector<Node> bl){
        this->loop = l;
        this->expression = exp;
        this->block = bl;
    }
};

class FunctionDefinition: public Node{
    std::string* id;
    bool returnSthg;
    std::vector<Node>* params;
    std::vector<Node>* lines;
    Node* returnNode;
    
public:
    FunctionDefinition(std::string* i,std::vector<Node> p,std::vector<Node> l,bool ret,Node* thing){
        this->id = i;
        this->returnSthg = ret;
        this->params = &p;
        this->lines = &l;
        this->returnNode = thing;
    }
    
    FunctionDefinition(std::string* i,std::vector<Node> p,std::vector<Node> l){
        this->id = i;
        this->returnSthg = false;
        this->params = &p;
        this->lines = &l;
        this->returnNode = nullptr;
    }
    
    FunctionDefinition(std::string* i,std::vector<Node> l){
        this->id = i;
        this->returnSthg = false;
        this->params = nullptr;
        this->lines = &l;
        this->returnNode = nullptr;
    }
};

class GlobalVar: public Node{
    Node* declaration;
public:
    GlobalVar(Node* declar){
        this->declaration = declar;
    }
};
