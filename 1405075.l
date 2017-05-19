%{
#include<cstdio>
#include<cstdlib>
#include<string>
#include "1405075.h"
#include"y.tab.h"


using namespace std;

int line_count=1;
int error_count = 0;

extern YYSTYPE yylval;
SymbolTable *table = new SymbolTable(20);


%}

NEWLINE \n
WHITESPACE [ \t\f\r\v]+
LETTER [a-zA-Z]
IDLETTER [a-zA-Z]{+}[_]
DIGIT [0-9]
INTEGER {DIGIT}+
FLOATING_POINT ({INTEGER}*(\.{INTEGER}))|({INTEGER}*(\.{INTEGER})*("E+"|"E-"|"E"){INTEGER})
ILL_NUMBER ({INTEGER}*(\.{INTEGER})*("E+"|"E-"|"E"){INTEGER}*)(\.{INTEGER})+
TOO_DEC ({INTEGER}*(\.{INTEGER}))(\.{INTEGER})+

CHAR [ -~]{-}['\\]
STRCHAR [ -~]{-}[\"]
CHARACTER ('{CHAR}')
SP_CHAR [tvar"afb0n\\]
SPECIAL ('\\{SP_CHAR}')
MULTI_CHAR ('([ -~]{-}['])+')
UN_CHAR ('{CHAR})|('[\\]')
EM_CHAR ('')

ID {IDLETTER}({IDLETTER}|{DIGIT})*
INVALID_ID {DIGIT}({IDLETTER}|{DIGIT})*

SINGLE_COMMENT "//"([ -~]|{WHITESPACE})*$
MULTI_COMMENT "/*"([ -~]|{WHITESPACE}|{NEWLINE})*"*/"|"//"({CHAR}|[']|{WHITESPACE})*("\\"{NEWLINE}?({CHAR}|[']|{WHITESPACE})*)*
MULTICOM_ERR "/*"(([ -~]{-}[*])|{WHITESPACE}|{NEWLINE})*(([ -~]{-}[/])|{WHITESPACE}|{NEWLINE})*

STRING \"({STRCHAR}|[']|{WHITESPACE})*\"|\"({STRCHAR}|[']|{WHITESPACE})*("\\"{NEWLINE}?({STRCHAR}|[']|{WHITESPACE})*)*\"
STRING_ERR \"({STRCHAR}|{WHITESPACE})*{NEWLINE}
%%

"if"	{
			return IF;
		}

"else"	{
			return ELSE;
		}

"for"	{
			return FOR;
		}

"while"	{
			return WHILE;
		}
"do"	{
			return DO;
		}

"int"	{
			return INT;
		}

"char"	{
			return CHAR;
		}

"float"	{
			return FLOAT;
		}

"double"	{
			return DOUBLE;
		}
"void"	{
			return VOID;
		}

"return"	{
			return RETURN;
		}



"continue"	{
			return CONTINUE;
		}

"println" { return PRINTLN;
		}

{NEWLINE} { line_count++;
		}

{INTEGER} {
			SymbolInfo *s = new SymbolInfo(yytext, "CONST_INT");
			s->symbol = yytext;
			s->var_type = "INT";
			s->ival = atoi(yytext);
			yylval = s;
			return CONST_INT;
		}

{FLOATING_POINT} {
			SymbolInfo *s = new SymbolInfo(yytext, "CONST_FLOAT");
			s->symbol = yytext;
			s->var_type = "FLOAT";
			s->fval = atof(yytext);
			yylval = s;
			return CONST_FLOAT;
		}

{ILL_NUMBER} {
			error_count++;
 		}

{TOO_DEC} {
			error_count++;
 		}

{EM_CHAR} {
			error_count++;
 		}

{UN_CHAR} {
			error_count++;
 		}

{MULTI_CHAR} {
			error_count++;
 		}

{STRING} {
			int i = 1;
			string now = yytext;
			for ( ; i < now.length()-1; i++){
				if (now[i] == '\\'){
					switch(now[i+1]){
						case 't':
						i++;
						break;
						case 'n':
						i++;
						break;
						case 'a':
						i++;
						break;
						case 'f':
						i++;
						break;
						case 'v':
						i++;
						break;
						case '\\':
						i++;
						break;
						case 'b':
						i++;
						break;
						case 'r':
						i++;
						break;
						default:
						i++;
					}
					continue;
				}
			}
			/*for (i = 0; i < now.length(); i++){
				if (now[i] == '\n')
					line_count++;
			}*/
		}

{STRING_ERR} {
			error_count++;
			string now = yytext;
			int i;
			/*for (i = 0; i < now.length(); i++){
				if (now[i] == '\n')
					line_count++;
			}*/
 		}

{ID} {
			SymbolInfo *s = new SymbolInfo(yytext, "ID");
			s->symbol = yytext;
			yylval = s;

			return ID;
		}

{INVALID_ID} {
			error_count++;
 		}

{SINGLE_COMMENT} {

		}

{MULTI_COMMENT} {
			string now = yytext;
			int i;
			/*for (i = 0; i < now.length(); i++){
				if (now[i] == '\n')
					line_count++;
			}*/
		}

{MULTICOM_ERR} {
			string now = yytext;
			int i;
			error_count++;
			/*for (i = 0; i < now.length(); i++){
				if (now[i] == '\n')
					line_count++;
			}*/
 		}


"+"|"-" {
			SymbolInfo *s = new SymbolInfo(yytext, "ADDOP");
			yylval = s;
			return ADDOP;
		}

"*"|"/"|"%" {
			SymbolInfo *s = new SymbolInfo(yytext, "MULOP");
			yylval = s;
			return MULOP;
		}

"++" {
			return INCOP;
		}
"--" {
			return DECOP;
		}

"<"|"<="|">"|">="|"=="|"!=" {
			SymbolInfo *s = new SymbolInfo(yytext, "RELOP");
			yylval = s;
			return RELOP;
		}
"=" {
			return ASSIGNOP;
		}

"&&"|"||" {
			SymbolInfo *s = new SymbolInfo(yytext, "LOGICOP");
			yylval = s;
			return LOGICOP;
		}

"!" {
			return NOT;
		}

"(" {
			return LPAREN;
		}

")" {
			return RPAREN;
		}
"{" {
			return LCURL;
		}

"}" {
			return RCURL;
		}

"[" {
			return LTHIRD;
		}

"]" {
			return RTHIRD;
		}

"," {
			return COMMA;
		}

";" {
			return SEMICOLON;
		}

{WHITESPACE} {}

. 	{
			error_count++;
 		}
<<EOF>> 	{
			return 0;
			}

%%

int yywrap(void)
{
	return 1;
}
