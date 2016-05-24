//
//  SymbolTable.cpp
//  
//
//  Created by Laura del Pino Díaz on 30/4/16.
//
//

#include "SymbolTable.hpp"


void SymbolTable::insertRecord( string id, SymbolTableRecord r){
    this->table[id]=r;
    this->lastIdentifierAccessed = id;
}

void SymbolTable::saveNode(string id, Node* n){
    this->table[id].addNode(n);
}

bool SymbolTable::sameType( string id, string id2){
    return this->table[id].getType() != this->table[id2].getType();
}

void SymbolTable::printState(){
    
    cout << "---------------SYMBOL TABLE STATE--------------" << endl;
    cout << "   id   |" << "  global  |" << "  tipo  |" << "  depth |" << "  vector Size " << endl;
    for(map<string,SymbolTableRecord>::iterator it =this->table.begin(); it != this->table.end(); ++it)
    {
        cout << it->first << "\t";
        it->second.printState();
    }
}

std::vector<Node*> SymbolTable::getNodeVector(string identifier){
    return this->table[identifier].getNodeStack();
}


void SymbolTable::removeRecord(string id){
    this->table.erase(id);
}

int SymbolTable::exists(string identifier){
    if(this->table.find(identifier) != table.end()){
        return this->table[identifier].giveDepth();
    }
    return -1;
}

void SymbolTable::setParams(std::vector<Node*> p, std::string identifier){
    this->table[identifier].setParams(p);
};


std::vector<std::string> SymbolTable::getGlobalVars(){

    std::vector<std::string> result;
    for(map<string,SymbolTableRecord>::iterator it =this->table.begin(); it != this->table.end(); ++it)
    {
        if(it->second.isGlobal()){
            if(it->second.getType() == real || it->second.getType() == DataTypeVector){
                result.push_back(it->first);
            }
        }
    }
    
    return result;
}

bool SymbolTable::hasOnlyInit(){
    std::vector<std::string> result;
    for(map<string,SymbolTableRecord>::iterator it =this->table.begin(); it != this->table.end(); ++it)
    {
        if(it->second.isGlobal() && it->second.getType() == initFunction) {
            result.push_back(it->first);
        }
    }
    return result.size() == 1;
}

void SymbolTable::setAddress(std::string s, int adrss){
    this->table[s].setAddress(adrss);
}



SymbolTableRecord SymbolTable::getInit(){
    
    for(map<string,SymbolTableRecord>::iterator it =this->table.begin(); it != this->table.end(); ++it)
    {
        if(it->second.isGlobal() && it->second.getType() == initFunction) {
            return it->second;
        }
    }
}



std::vector<SymbolTableRecord*> SymbolTable::getNonInitFunctions(){
    
    std:vector<SymbolTableRecord*> result;
    for(map<string,SymbolTableRecord>::iterator it =this->table.begin(); it != this->table.end(); ++it)
    {
        if(it->second.isGlobal() ) {
            if( it->second.getType() == realFunction || it->second.getType() == realFunction){
                result.push_back(&(it->second));
            }
        }
    }
    
    return result;
    
}