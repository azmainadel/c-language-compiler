%{
    #include<iostream>
    #include<cstdlib>
    #include<cstring>
    #include<cmath>
    #include <sstream>
    #include "1405075.h"
    #define YYSTYPE SymbolInfo*

    using namespace std;

    namespace patch
    {
        template < typename T > std::string to_string( const T& n )
        {
            std::ostringstream stm ;
            stm << n ;
            return stm.str() ;
        }
    }

    int yyparse(void);
    int yylex(void);
    extern FILE *yyin;

    extern int line_count;
    extern int error_count;
    extern SymbolTable *table;
    string type;
    string rtype;
    FILE *logo;
    FILE *error;

    vector<string>list;
    vector<string>name;

    int labelCount=0;
    int tempCount=0;

    char *newLabel(){
        char *lb= new char[4];
        strcpy(lb,"L");
        char b[3];
        sprintf(b,"%d", labelCount);
        labelCount++;
        strcat(lb,b);
        return lb;
    }

    char *newTemp(){
        char *t= new char[4];
        strcpy(t,"t");
        char b[3];
        sprintf(b,"%d", tempCount);
        tempCount++;
        strcat(t,b);
        return t;
    }

    void yyerror(string s){
        fprintf(error,"\nError at Line %d : %s\n", line_count, s.c_str());
    }


    %}

    %token CONST_INT CONST_FLOAT CONST_CHAR ID INCOP DECOP MULOP ADDOP RELOP LOGICOP ASSIGNOP LPAREN RPAREN RTHIRD LTHIRD LCURL RCURL COMMA SEMICOLON NOT IF ELSE FOR WHILE DO INT CHAR FLOAT DOUBLE VOID RETURN PRINTLN CONTINUE

    %error-verbose

    %left '+' '-'
    %left '*' '/'

    %nonassoc LOWER_THAN_ELSE
    %nonassoc ELSE


    %%

    start : program
    {

    }
    ;

    program : program unit
    {
        fprintf(logo,"\nLine no %d : program : program unit\n",line_count);
    }
    |
    unit
    {
        fprintf(logo,"\nLine no %d : program : unit\n",line_count);
    }
    ;

    unit : var_declaration
    {
        fprintf(logo,"\nLine no %d : unit : var_declaration\n",line_count);
    }
    |
    func_declaration
    {
        fprintf(logo,"\nLine no %d : unit : func_declaration\n",line_count);
    }
    |
    func_definition
    {
        fprintf(logo,"\nLine no %d : unit : func_definition\n",line_count);
    }
    ;

    func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
    {
        fprintf(logo,"\nLine no %d : func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n%s\n", line_count, $2->getName().c_str());
        $2->var_type = $1->getType();
        $2->a_size = 0;

        if (table->Insert($2)){
            SymbolInfo *sp = table->Lookup($2->getName());
            if (sp->var_type == "INT") sp->ival = 10;
            else if (sp->var_type == "FLOAT") sp->fval = 10.0;
            for (int i = 0; i < list.size(); i++){
                sp->param_list.push_back(list[i]);
                sp->param_name.push_back(name[i]);
            }
            list.clear();
            name.clear();
        }
        else {
            yyerror("Multiple declaration of "+$2->getName());
            error_count++;
        }
    }
    ;

    func_definition : type_specifier ID LPAREN parameter_list RPAREN {
        int flag = 0;
        SymbolInfo *sp = table->Lookup($2->getName());
        if (sp){
            table->EnterScope(table->len);
            if (sp->param_list.size() == list.size()){
                for (int i = 0; i < list.size(); i++){
                    if (sp->param_list[i] != list[i]){
                        string s = patch::to_string(i+1);
                        yyerror(s+"th parameter mismatch in function "+sp->getName());
                        error_count++;
                        flag = 1;
                        break;
                    }
                }
            }
            else {
                yyerror("Number of parameters mismatch");
                error_count++;
                flag = 1;
            }
            list.clear();
            name.clear();
        }

        else{
            $2->var_type = $1->getType();
            $2->a_size = 0;
            table->Insert($2);
            sp = table->Lookup($2->getName());
            table->EnterScope(table->len);
            if (sp->var_type == "INT") sp->ival = 10;
            else if (sp->var_type == "FLOAT") sp->fval = 10.0;
            else sp->ival = 0;
            for (int i = 0; i < list.size(); i++){
                sp->param_list.push_back(list[i]);
                sp->param_name.push_back(name[i]);
            }
            list.clear();
            name.clear();
        }
        if (flag == 0){
            for (int i = 0; i < sp->param_list.size(); i++){
                SymbolInfo *sp1 = new SymbolInfo();
                sp1->setName(sp->param_name[i]);
                sp1->setType("ID");
                sp1->var_type = sp->param_list[i];
                if (sp->getName() != ""){
                    if (table->Insert(sp1) == false){
                        yyerror("Multiple definition of"+sp->getName());
                        error_count++;
                    }
                }
            }
        }
        rtype = sp->var_type;
    }
    compound_statement
    {
        fprintf(logo,"\nLine no %d : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n%s\n",line_count, $2->getName().c_str());

    }
    ;
    parameter_list  : parameters {
        fprintf(logo,"\nLine no %d : parameter_list  : parameters\n",line_count);
    }
    | {
        fprintf(logo,"\nLine no %d : parameter_list  :\n",line_count);
    }
    ;

    parameters  : parameters COMMA type_specifier ID {
        fprintf(logo,"\nLine no %d : parameters : parameters COMMA type_specifier ID\n%s\n",line_count,$4->getName().c_str());
        if (type != "VOID"){
            list.push_back(type);
            name.push_back($4->getName());
        }
        else {
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
    | parameters COMMA type_specifier {
        fprintf(logo,"\nLine no %d : parameters  : parameters COMMA type_specifier\n",line_count);
        if (type != "VOID"){
            list.push_back(type);
            name.push_back("");
        }
        else {
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
    | type_specifier ID {
        fprintf(logo,"\nLine no %d : parameters  : type_specifier ID\n%s\n",line_count,$2->getName().c_str());

        if (type != "VOID"){
            list.push_back(type);
            name.push_back($2->getName());
        }
        else {
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
    | type_specifier {
        fprintf(logo,"\nLine no %d : parameters  : type_specifier\n",line_count);

        if (type != "VOID"){
            list.push_back(type);
            name.push_back("");
        }
        else {
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
    ;

    compound_statement : LCURL statements RCURL {
        fprintf(logo,"\nLine no %d : compound_statement : LCURL statements RCURL\n",line_count);
        table->ExitScope();
    }
    | LCURL RCURL {
        fprintf(logo,"\nLine no %d : compound_statement : LCURL RCURL\n",line_count);
        table->ExitScope();
    }
    ;

    var_declaration : type_specifier declaration_list SEMICOLON {
        fprintf(logo,"\nLine no %d : var_declaration : type_specifier declaration_list SEMICOLON\n",line_count);
        /*cout<<"CHECK"<<$2->symbol<<endl;*/
        $$=$2;
    }
    ;

    type_specifier	: INT {
        fprintf(logo,"\nLine no %d : type_specifier : INT\n",line_count);
        type = "INT";
        $$ = new SymbolInfo();
        $$->setType("INT");
    }
    | FLOAT {
        fprintf(logo,"\nLine no %d : type_specifier : FLOAT\n",line_count);
        type = "FLOAT";
        $$ = new SymbolInfo();
        $$->setType("FLOAT");
    }
    | VOID {
        fprintf(logo,"\nLine no %d : type_specifier : VOID\n",line_count);
        type = "VOID";
        $$ = new SymbolInfo();
        $$->setType("VOID");
    }
    ;

    declaration_list : declaration_list COMMA ID {
        fprintf(logo,"\nLine no %d : declaration_list : declaration_list COMMA ID\n%s\n",line_count,$3->getName().c_str());
        if (type != "VOID"){
            $3->var_type = type;
            if (table->Insert($3) == false){
                yyerror("Multiple Declaration of " + $3->getName());
                error_count++;
            }
        }
        else{
            yyerror("Variable can not be of void type");
            error_count++;
        }
    }
    | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD {
        fprintf(logo,"\nLine no %d : declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n%s\n",line_count,$3->getName().c_str());
        if (table->LookupCurr($3->getName()) != NULL) {
            yyerror("Multiple Declaration of " + $3->getName()); 					error_count++;
        }
        else if ($5->var_type == "FLOAT")  {
            yyerror("Array index must be of 'int' type");
            error_count++;
        }
        else if($5->ival < 1) {yyerror("Invalid array size"); error_count++; 	}
        else {
            if (type != "VOID"){
                $3->var_type = type;
                $3->a_size = $5->ival;
                table->Insert($3);
                SymbolInfo *sp = table->Lookup($3->getName());
                sp->arr = new SymbolInfo[$5->ival];
                sp->a_size = $5->ival;
                for (int i = 0; i < $5->ival; i++){
                    if (type == "INT") sp->arr[i].ival = -1;
                    else sp->arr[i].fval = -1.0;
                    sp->arr[i].var_type = type;
                    sp->arr[i].setType("ID");
                }
            }
            else{ yyerror("Variable can not be of void type"); error_count++;}
        }
    }
    | ID {
        fprintf(logo,"\nLine no %d : declaration_list : ID\n%s\n",line_count,$1->getName().c_str());
        if (type != "VOID"){
            $1->var_type = type;
            if (table->Insert($1) == false){
                yyerror("Multiple Declaration of " + $1->getName());
                error_count++;
            }
        }
        else{
            yyerror("Variable can not be of void type");
            error_count++;
        }
        $$ = $1;
    }
    | ID LTHIRD CONST_INT RTHIRD {
        fprintf(logo,"\nLine no %d : declaration_list : ID LTHIRD CONST_INT RTHIRD\n%s\n",line_count,$1->getName().c_str());
        if (table->LookupCurr($1->getName()) != NULL) {
            yyerror("Multiple Declaration of " + $1->getName());
            error_count++;
        }
        else if ($3->var_type == "FLOAT"){
            yyerror("Array index must be of 'int' type");
            error_count++;
        }
        else if($3->ival < 1) {
            yyerror("Invalid array size");
            error_count++;
        }
        else {
            if (type != "VOID"){
                $1->var_type = type;
                $1->a_size = $3->ival;
                table->Insert($1);
                SymbolInfo *sp = table->Lookup($1->getName());
                sp->arr = new SymbolInfo[$3->ival];
                sp->a_size = $3->ival;
                for (int i = 0; i < $3->ival; i++){
                    if (type == "INT") sp->arr[i].ival = -1;
                    else sp->arr[i].fval = -1.0;
                    sp->arr[i].var_type = type;
                    sp->arr[i].setType("ID");
                }
            }
            else{
                yyerror("Variable can not be of void type");
                error_count++;}
            }
        }
        ;

        statements : statement {
            fprintf(logo,"\nLine no %d : statements : statement\n",line_count);
        }
        | statements statement {
            fprintf(logo,"\nLine no %d : statements : statements statement\n",line_count);
        }
        ;

        statement : var_declaration {
            fprintf(logo,"\nLine no %d : statement : var_declaration\n",line_count);
            $$=$1;
        }
        | expression_statement {
            fprintf(logo,"\nLine no %d : statement : expression_statement\n",line_count);
        }
        | {table->EnterScope(table->len);} compound_statement {
            fprintf(logo,"\nLine no %d : statement : compound_statement\n",line_count);
        }
        | FOR LPAREN expression_statement expression_statement expression RPAREN statement
        {
            fprintf(logo,"\nLine no %d : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n",line_count);
        }
        | IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
            fprintf(logo,"\nLine no %d : statement : IF LPAREN expression RPAREN statement\n",line_count);
        }
        | IF LPAREN expression RPAREN statement ELSE statement {
            fprintf(logo,"\nLine no %d : statement : IF LPAREN expression RPAREN statement ELSE statement\n",line_count);
        }
        | WHILE LPAREN expression RPAREN statement {
            fprintf(logo,"\nLine no %d : statement : WHILE LPAREN expression RPAREN statement\n",line_count);
        }
        | PRINTLN LPAREN ID RPAREN SEMICOLON {
            fprintf(logo,"\nLine no %d : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n%s\n",line_count,$3->getName().c_str());
            SymbolInfo *sp = table->Lookup($3->getName());
            if (sp == NULL) {
                yyerror($3->getName() + " was not declared in this scope" );
                error_count++;}
            }
            | RETURN expression SEMICOLON {
                fprintf(logo,"\nLine no %d : statement : RETURN expression SEMICOLON\n",line_count);
                if (rtype != $2->var_type){
                    yyerror("Return type does not match");
                    error_count++;
                }
            }
            | RETURN SEMICOLON error {fprintf(logo,"\nLine no %d : statement : RETURN SEMICOLON error\n",line_count);}
            ;

            expression_statement 	: SEMICOLON {
                fprintf(logo,"\nLine no %d : expression_statement : SEMICOLON\n",line_count);
            }
            | expression SEMICOLON {
                fprintf(logo,"\nLine no %d : expression_statement : SEMICOLON\n",line_count);
                $$ = $1;
            }
            ;

            variable : ID 	{
                fprintf(logo,"\nLine no %d : variable : ID\n%s\n",line_count,$1->getName().c_str());
                SymbolInfo* sp = table->Lookup($1->getName().c_str());

                if (sp != NULL) $$ = $1;
                else{
                    $$ = NULL;
                    yyerror("Undeclared Variable "+$1->getName());
                    error_count++;
                }
            }
            | ID LTHIRD expression RTHIRD  {
                fprintf(logo,"\nLine no %d : variable : ID LTHIRD expression RTHIRD\n%s\n",line_count,$1->getName().c_str());
                SymbolInfo* sp = table->Lookup($1->getName().c_str());
                //$$ = NULL;
                if(sp == NULL){
                    yyerror("Undeclared Variable "+$1->getName());
                    error_count++;
                }
                else if(sp->a_size == -1){
                    yyerror("Index on non-array");
                    error_count++;
                }
                else if($3->var_type == "FLOAT"){
                    yyerror("Array index must be of 'int' type");
                    error_count++;
                }
                else if($3->ival < 0 || $3->ival >= sp->a_size){
                    yyerror("Array index out of bound");
                    error_count++;
                }
                else $$ = &(sp->arr[$3->ival]);
            }
            ;

            expression : logic_expression {
                fprintf(logo,"\nLine no %d : expression : logic_expression\n",line_count);
                $$ = $1;
            }
            | variable ASSIGNOP logic_expression {
                fprintf(logo,"\nLine no %d : expression : variable ASSIGNOP logic_expression\n",line_count);
                if ($1){
                    if ($1->var_type != $3->var_type){
                        yyerror("Type mismatch");
                        error_count++;
                    }
                    else if ($1->a_size == 0){
                        yyerror($1->getName()+" is not a variable");
                        error_count++;
                    }
                    else if ($1->a_size > 0 ){
                        yyerror("No index on array"); error_count++;
                    }
                    else if ($1->getName() == "" && $3->var_type == "INT"){
                        $1->ival = $3->ival;
                    }
                    else if ($1->getName() == "" && $3->var_type == "FLOAT"){
                        $1->fval = $3->fval;
                    }
                    else if ($1->var_type == "INT" && $3->var_type == "INT"){
                        $1->ival = $3->ival;
                    }
                    else if ($1->var_type == "FLOAT" && $3->var_type == "FLOAT"){
                        $1->fval = $3->fval;
                    }
                    $$ = $1;
                }
                cout<<"-----------------------------------"<<endl;
                table->PrintAllScopeTable();
                cout<<"-----------------------------------"<<endl;

                $$->code += "MOV AX, " + $3->symbol + " \n";
                $$->code += "MOV " + $1->symbol+", AX\n";

                /*cout<<$$->code<<" "<<$1->symbol<<"  "<<$3->symbol<<endl;*/
            }
            ;

            logic_expression : rel_expression {
                fprintf(logo,"\nLine no %d : logic_expression : rel_expression\n",line_count);
                $$ = $1;
            }
            | rel_expression LOGICOP rel_expression {
                fprintf(logo,"\nLine no %d : logic_expression : rel_expression LOGICOP rel_expression\n",line_count);
                $$ = new SymbolInfo();
                $$->var_type = "INT";
                if ($1->var_type == "INT" && $3->var_type == "INT"){
                    if ($2->getName() == "&&") $$->ival = $1->ival && $3->ival;
                    else $$->ival = $1->ival || $3->ival;
                }
                else if ($1->var_type == "FLOAT" && $3->var_type == "INT"){
                    if ($2->getName() == "&&") $$->ival = $1->fval && $3->ival;
                    else $$->ival = $1->fval || $3->ival;
                }
                else if ($1->var_type == "INT" && $3->var_type == "FLOAT"){
                    if ($2->getName() == "&&") $$->ival = $1->ival && $3->fval;
                    else $$->ival = $1->ival || $3->fval;
                }
                else{
                    if ($2->getName() == "&&") $$->ival = $1->fval && $3->fval;
                    else $$->ival = $1->fval || $3->fval;
                }
            }
            ;

            rel_expression	: simple_expression {
                fprintf(logo,"\nLine no %d : rel_expression : simple_expression\n",line_count);
                $$ = $1;
            }
            | simple_expression RELOP simple_expression {
                fprintf(logo,"\nLine no %d : rel_expression : simple_expression RELOP simple_expression\n",line_count);
                $$ = new SymbolInfo();
                $$->setType($1->getType());
                $$->var_type = "INT";

                if ($1->var_type == "INT" && $3->var_type == "INT"){
                    if ($2->getName() == "<") $$->ival = $1->ival < $3->ival;
                    else if ($2->getName() == ">") $$->ival = $1->ival > $3->ival;
                    else if ($2->getName() == ">=") $$->ival = $1->ival >= $3->ival;
                    else if ($2->getName() == "<=") $$->ival = $1->ival <= $3->ival;
                    else if ($2->getName() == "==") $$->ival = $1->ival == $3->ival;
                    else $$->ival = $1->ival != $3->ival;
                }
                else if ($1->var_type == "FLOAT" && $3->var_type == "INT"){
                    if ($2->getName() == "<") $$->ival = $1->fval < $3->ival;
                    else if ($2->getName() == ">") $$->ival = $1->fval > $3->ival;
                    else if ($2->getName() == ">=") $$->ival = $1->fval >= $3->ival;
                    else if ($2->getName() == "<=") $$->ival = $1->fval <= $3->ival;
                    else if ($2->getName() == "==") $$->ival = $1->fval == $3->ival;
                    else $$->ival = $1->fval != $3->ival;
                }
                else if ($1->var_type == "INT" && $3->var_type == "FLOAT"){
                    if ($2->getName() == "<") $$->ival = $1->ival < $3->fval;
                    else if ($2->getName() == ">") $$->ival = $1->ival > $3->fval;
                    else if ($2->getName() == ">=") $$->ival = $1->ival >= $3->fval;
                    else if ($2->getName() == "<=") $$->ival = $1->ival <= $3->fval;
                    else if ($2->getName() == "==") $$->ival = $1->ival == $3->fval;
                    else $$->ival = $1->ival != $3->fval;
                }
                else{
                    if ($2->getName() == "<") $$->ival = $1->fval < $3->fval;
                    else if ($2->getName() == ">") $$->ival = $1->fval > $3->fval;
                    else if ($2->getName() == ">=") $$->ival = $1->fval >= $3->fval;
                    else if ($2->getName() == "<=") $$->ival = $1->fval <= $3->fval;
                    else if ($2->getName() == "==") $$->ival = $1->fval == $3->fval;
                    else $$->ival = $1->fval != $3->fval;
                }
            }
            ;

            simple_expression : term {
                fprintf(logo,"\nLine no %d : simple_expression : term\n",line_count);
                $$ = $1;
            }
            | simple_expression ADDOP term {
                fprintf(logo,"\nLine no %d : simple_expression : simple_expression ADDOP term\n",line_count);
                $$ = new SymbolInfo();
                $$->setType($1->getType());
                if ($1->var_type == "FLOAT" || $3->var_type == "FLOAT"){	  					$$->var_type = "FLOAT";
                if ($1->var_type != "FLOAT" && $2->getName() == "+")
                $$->fval = $1->ival + $3->fval;
                else if ($2->var_type != "FLOAT" && $2->getName() == "+")
                $$->fval = $1->fval + $3->ival;
                else if ($1->var_type != "FLOAT" && $2->getName() == "-")
                $$->fval = $1->ival - $3->fval;
                else if ($2->var_type != "FLOAT" && $2->getName() == "-")
                $$->fval = $1->fval - $3->ival;
            }
            else {
                $$->var_type = "INT";
                if ($2->getName() == "+")
                $$->ival = $1->ival + $3->ival;
                else $$->ival = $1->ival - $3->ival;
            }

        }
        ;

        term :	unary_expression {
            fprintf(logo,"\nLine no %d : term : unary_expression\n",line_count);
            $$ = $1;
        }
        |  term MULOP unary_expression {
            fprintf(logo,"\nLine no %d : term MULOP unary_expression\n",line_count);
            $$ = new SymbolInfo();
            if ($2->getName() == "%"){
                if ($1->var_type == "FLOAT" || $3->var_type == "FLOAT"){
                    yyerror("Non-Integer operand on modulus operator");
                    error_count++;
                }
                else
                $$->ival = $1->ival % $3->ival;
            }
            else {
                if ($1->var_type == "FLOAT" || $3->var_type == "FLOAT"){
                $$->var_type = "FLOAT";

                if ($1->var_type != "FLOAT" && $2->getName() == "*")
                $$->fval = $1->ival * $3->fval;
                else if ($2->var_type != "FLOAT" && $2->getName() == "*")
                $$->fval = $1->fval * $3->ival;
                else if ($1->var_type != "FLOAT" && $2->getName() == "/")
                $$->fval = $1->ival / $3->fval;
                else if ($2->var_type != "FLOAT" && $2->getName() == "/")
                $$->fval = $1->fval / $3->ival;
            }
            else {
                $$->var_type = "INT";
                if ($2->getName() == "*")
                $$->ival = $1->ival * $3->ival;
                else $$->ival = $1->ival / $3->ival;
            }
        }
    }
    ;

    unary_expression : ADDOP unary_expression  {
        fprintf(logo,"\nLine no %d : unary_expression : ADDOP unary_expression\n",line_count);
        $$ = new SymbolInfo();
        $$->setType($2->getType());
        $$->var_type = $2->var_type;
        if ($1->getName() == "+"){
            $$->ival = $2->ival;
            $$->fval = $2->fval;
        }
        else{
            $$->ival = -$2->ival;
            $$->fval = -$2->fval;
        }
    }
    | NOT unary_expression  {
        fprintf(logo,"\nLine no %d : unary_expression : NOT unary_expression\n",line_count);
        $$ = new SymbolInfo();
        $$->setType($2->getType());
        $$->var_type = "INT";
        if ($2->var_type == "INT") $$->ival = !($2->ival);
        else if ($2->var_type == "FLOAT") $$->ival = !($2->fval);
    }
    | factor {
        fprintf(logo,"\nLine no %d : unary_expression : factor\n",line_count);
        $$ = $1;
    }
    ;

    factor	: variable {
        fprintf(logo,"\nLine no %d : factor : variable\n",line_count);
        $$ = $1;
        cout<<$$->symbol<<"CHECK FACTOR"<<endl;
    }
    | ID LPAREN argument_list RPAREN {
        SymbolInfo *sp = table->Lookup($1->getName());
        if (sp == NULL) {yyerror("Undeclared Function "+$1->getName()); error_count++;}
        else{
            fprintf(logo,"\nLine no %d : factor : ID LPAREN argument_list RPAREN\n%s\n",line_count,$1->getName().c_str());
            if (sp->a_size != 0){
                yyerror(sp->getName()+" is not a function");
                error_count++;
            }
            else if (sp->param_list.size() == list.size()){
                for (int i = 0; i < sp->param_list.size(); i++){
                    if (sp->param_list[i] != list[i]){
                        string s = patch::to_string(i+1);
                        yyerror(s+"th argument mismatch in function"+sp->getName());
                        error_count++;
                        break;
                    }
                }
            }
            else {
                yyerror("Number of arguments mismatch");
                error_count++;
            }
        }
        list.clear();
    }
    | LPAREN expression RPAREN {
        fprintf(logo,"\nLine no %d : factor : LPAREN expression RPAREN\n",line_count); $$ = $2;}
        | CONST_INT {
            fprintf(logo,"\nLine no %d : factor : CONST_INT\n%s\n",line_count,$1->getName().c_str()); $$ = $1;
        }
        | CONST_FLOAT {
            fprintf(logo,"\nLine no %d : factor : CONST_FLOAT\n%s\n",line_count,$1->getName().c_str()); $$ = $1;
        }
        | CONST_CHAR {;}
        | variable INCOP{
            SymbolInfo *sp = table->Lookup($1->getName());
            if (sp){
                if ($1->var_type == "INT"){
                    $1->ival++;
                    sp->ival = $1->ival;
                }
                else if ($1->var_type == "FLOAT"){
                    $1->fval++;
                    sp->fval = $1->fval;
                }
            }
            else yyerror("");
            $$ = $1;
            fprintf(logo,"\nLine no %d : factor : variable INCOP\n",line_count);

            $$->code += "INC " + $1->symbol + " \n";
        }
        | variable DECOP{
            SymbolInfo *sp = table->Lookup($1->getName());
            if (sp){
                if ($1->var_type == "INT"){
                    $1->ival--;
                    sp->ival = $1->ival;
                }
                else if ($1->var_type == "FLOAT"){
                    $1->fval--;
                    sp->fval = $1->fval;
                }
            }
            else yyerror("");
            $$ = $1;
            fprintf(logo,"\nLine no %d : factor : variable DECOP\n",line_count);

            $$->code += "DEC " + $1->symbol + " \n";
        }
        ;

        argument_list : arguments {
            fprintf(logo,"\nLine no %d : argument_list : arguments\n",line_count);
        }
        | {
            fprintf(logo,"\nLine no %d : argument_list : \n",line_count);
        }
        ;
        arguments     : arguments COMMA logic_expression {
            fprintf(logo,"\nLine no %d : arguments : arguments COMMA logic_expression\n",line_count);
            list.push_back($3->var_type);
        }
        | logic_expression {
            fprintf(logo,"\nLine no %d : arguments : logic_expression\n",line_count);
            list.push_back($1->var_type);
        }
        ;


        %%
        int main(int argc,char *argv[])
        {
            FILE *fp;
            if((fp=fopen(argv[1],"r"))==NULL)
            {
                printf("Cannot Open Input File.\n");
                exit(1);
            }
            logo = fopen("log.txt","w");
            error = fopen("error.txt","w");

            yyin=fp;
            yyparse();
            fprintf(logo,"\nTotal Lines: %d\n",line_count-1);
            fprintf(logo,"\nTotal Errors: %d\n",error_count);
            fclose(fp);
            fclose(logo);
            fclose(error);
            return 0;
        }
