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

class REAL_Asignation:Asignation{
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