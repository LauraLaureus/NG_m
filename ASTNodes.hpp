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

class Asignation:Node{};

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
    VECTOR_Asignation(bool d, std::string* id, std::vector<double>* v,int lim){
        this->declaration = d;
        this->identification = id;
        this->value = v;
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

class Math_Expression: public Node{

}