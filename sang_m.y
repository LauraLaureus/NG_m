%{
    #include <iostream.h>
    #include <cctype>
    #include <cstring>
    #include <vector>
    #include <stack>
    
    #include "ast.h"
    
    // Bring the standard library into the
    // global namespace
    using namespace std;
    
    // Prototypes to keep the compiler happy
    void yyerror (const char *error);
    int  yylex ();
    void clear_stack ();
    
    // Variables
    int vars ['Z'- 'A' + 1];
    
    // stack class that takes care of all the nodes that were allocated
    stack <Expression *> nodes;
    extern int yylex(void);
    %}

%token FUNC INICIO

%union {
    Expression *exp;  /* For the expressions. Since it is a pointer, no problem. */
    int       value;  /* For the lexical analyser. NUMBER tokens */
    char      ident;  /* For the lexical analyser. IDENT tokens */
}

/* Lets inform Bison about the type of each terminal and non-terminal */
//%type <exp>   inicio matExp
//%type <value> NUMBER
//%type <ident> IDENT

/* Precedence information to resolve ambiguity */
%left '+'
%left '*'

%%

inicio:
| FUNC INICIO '{' '}' {printf("Hey yu!");}
;



%%


void yyerror (const char *error)
{
    cout << error << endl;
}



// Deletes all the nodes that were allocated
void clear_stack ()
{
    while (!nodes.empty ()) {
        delete nodes.top ();
        nodes.pop ();
    }
}

int main (int argc, char** argv){
    
    if(argc > 1)
    yyin=fopen(argv[1], “rt”);
    else
    yyin=fopen(“entrada.txt”,”rt”);
    yyparse();
    return 0;
}