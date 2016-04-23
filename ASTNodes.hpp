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