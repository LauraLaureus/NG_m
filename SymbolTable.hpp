//
//  SymbolTable.hpp
//  
//
//  Created by Laura del Pino Díaz on 30/4/16.
//
//

#pragma once
#include <iostream>
#include "data_type.h"

using namespace std;

class Node;


class SymbolTableRecord {
    bool global;
    DataType type;
    int depth;
    vector<Node*> v;
    std::vector<Node*> params;
    int address;
    std::vector<double> array_value;
    
    
public:
    
    Node* functionDefinition;
    
    SymbolTableRecord(){
        this->global = false;
        this->type = real;
        this->depth = 0;
        this->v = *new std::vector<Node*>();
        this->address = 0;
        this->array_value =  *new std::vector<double>();
    }
    
    SymbolTableRecord(bool g, DataType dt, int d,Node* v2){
        this->global = g;
        this->type = dt;
        this->depth = d;
        this->v = *new std::vector<Node*>();
        this->v.push_back(v2);
        this->address = 0;
    }
    
    SymbolTableRecord(bool g, DataType dt, int d,std::vector<Node*> v2){
        this->global = g;
        this->type = dt;
        this->depth = d;
        this->v = v;
        this->address = 0;
        this->array_value =  *new std::vector<double>();
    }
    
    SymbolTableRecord(bool g, DataType dt, int d,std::vector<Node*> v2, std::vector<double> vect){
        this->global = g;
        this->type = dt;
        this->depth = d;
        this->v = v2;
        this->address = 0;
        this->array_value = vect;
    }
    
    void setArrayOfDoublesValue(std::vector<double> v){
        this->array_value = v;
    }
    
    void setFunctionDefinition(Node* n){
        this->functionDefinition = n;
    }
    
    bool isGlobal(){
        return this->global;
    }
    
    void addNode(Node* n){
        this->v.push_back(n);
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
        cout << v.size() << "|" ;
        
        if(this->type >2 && this->type < 5){
            cout << "\t" << params.size() <<"|";
        }
        
        cout <<  "addr:" <<address << "|";
        
        cout <<std::endl;
    }
    
    std::vector<Node*> getNodeStack(){
        return this->v;
    }
    
    int giveDepth(){ return this->depth;}
    
    
    void setParams(std::vector<Node*> p){
        this->params = p;
    };

    void setAddress(int a){
        this->address = a;
    }
    
    int getAddress(){
        return this->address;
    }
    
    int vectorSize(){
        return this->array_value.size();
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
    
    void insertRecord(string id, SymbolTableRecord* r);
    
    void removeRecord(string id);
    
    void saveNode(string id, Node* n);
    
    bool sameType( string id, string id2);
    
    std::vector<Node*> getNodeVector(string identifier);
    
    int exists(string identifier);
    
    void printState();
    
    void setParams(std::vector<Node*> p, std::string identifier);
    
    std::vector<std::string> getGlobalVars();
    
    SymbolTableRecord operator[](std::string id){
        return table[id];
    }
    
    /*SymbolTableRecord const operator[](std::string id){
        return table[id];
    }*/
    
    SymbolTableRecord* getRecord(std::string id){
        return &table[id];
    }

    
    bool hasOnlyInit();
    
    void setAddress(std::string, int adrss);
    
    SymbolTableRecord getInit();
    
    std::vector<SymbolTableRecord*> getNonInitFunctions();
    
    void setFunctionDefinition(std::string* id, Node* def){
        this->table[*id].setFunctionDefinition(def);
    }
    
    
    SymbolTable getACopyWithOnlyGlobals();
    
    SymbolTable getACopyWithOutInit();
};