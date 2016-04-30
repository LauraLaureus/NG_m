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

void SymbolTable::saveNode( Node* n){
    this->table[lastIdentifierAccessed].addNode(n);
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