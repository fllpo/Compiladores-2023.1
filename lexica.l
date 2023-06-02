%{
#include <string>
%}

espaco              [ \t]
digito              [0-9]
letra               [A-Za-z_]
unario              "++"|"--"


DELIM               {espaco}+
NUM                 [-]?{digito}+ 
REAL                {NUM}+("."{NUM}+)?
CHAR                \'({letra}|{NUM})\'
ID                  {letra}({letra}|{NUM})*
%%

"\n"		        {}

{DELIM} 	        {}

"main"		        return MAIN;

"int"		        return TIPO_INT;
"float"	            return TIPO_FLOAT;
"char"	            return TIPO_CHAR;
"bool"              return TIPO_BOOL;
"string"            return TIPO_STRING;

[(){}[\];,]	        return *yytext;

"="                 return ATRIBUI;
"+"                 return SOMA;
"-"                 return SUBTRAI;
"*"                 return MULTIPLICA;
"/"                 return DIVIDE;
">"                 return MAIOR;
"<"                 return MENOR;
">="                return MAIOR_IGUAL;
"<="                return MENOR_IGUAL;
"=="                return IGUAL;
"!="                return DIFERENTE;
"&&"                return E_LOGICO;
"||"                return OU_LOGICO;
"verdadeiro"        return VERDADEIRO;
"falso"             return FALSO;


{NUM}               {yylval.traducao = yytext; return NUM;}
{REAL}              {yylval.traducao = yytext; return REAL;}
{ID}	        	{yylval.label = yytext; return ID;}

.	               	*yytext;

%%