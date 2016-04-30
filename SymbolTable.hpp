//
//  SymbolTable.hpp
//  
//
//  Created by Laura del Pino Díaz on 30/4/16.
//
//

#pragma once

#include <map>
#include <vector>
#include <string>
#include "ASTNodes.hpp"
#include <iostream>

using namespace std;

enum DataType { real, DataTypeVector, initFunction, realFunction, voidFunction};

class SymbolTableRecord {
    bool global;
    DataType type;
    int depth;
    vector<Node*> vector;
    
public:
    
    SymbolTableRecord(){
        this->global = false;
        this->type = real;
        this->depth = 0;
        this->vector = *new std::vector<Node*>();
    }
    
    SymbolTableRecord(bool g, DataType dt, int d,Node* v){
        this->global = g;
        this->type = dt;
        this->depth = d;
        this->vector = *new std::vector<Node*>();
        this->vector.push_back(v);
    }
    
    SymbolTableRecord(bool g, DataType dt, int d,std::vector<Node*> v){
        this->global = g;
        this->type = dt;
        this->depth = d;
        this->vector = v;
        
    }
    
    
    void addNode(Node* n){
        this->vector.push_back(n);
    }

    
    DataType getType(){
        return this->type;
    }
    
    void setGlobal(bool b){
        this->global = b;
    }
    
    void printState(){
        
        cout <<  "|" << global << "|" << "\t";
        cout << type << "|" << "\t";
        cout << depth << "|" << "\t";
        cout << vector.size() << "|" << "\n";
    }
    
    std::vector<Node*> getNodeStack(){
        return this->vector;
    }

};



class SymbolTable {
    map<string,SymbolTableRecord> table;
    string lastIdentifierAccessed; ///Habrá que poner el *
    
public:
    
    SymbolTable(){
        this->table = *new map<string,SymbolTableRecord>();
    };
    
    void insertRecord( string id, SymbolTableRecord r);
    
    void saveNode( Node* n);
    
    bool sameType( string id, string id2);
    
    std::vector<Node*> getNodeVector(string identifier);
    
    void printState();
};