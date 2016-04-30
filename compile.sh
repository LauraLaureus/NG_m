#!/bin/sh

#  compile.sh
#  
#
#  Created by Laura del Pino Díaz on 16/4/16.
#

bison -d sang_m.y
flex lang_m.l
g++ -o parser -x c++ lex.yy.c sang_m.tab.c ASTNodes.cpp SymbolTable.cpp -Wno-write-strings
