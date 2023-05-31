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
"string"            return TIPO_STRING;

[(){}[\];,]	        return *yytext;

"="                 return ATRIBUI;
"+"                 return SOMA;
"-"                 return SUBTRAI;
"*"                 return MULTIPLICA;
"/"                 return DIVIDE;

{NUM}               {yylval.traducao = yytext; return NUM;}
{REAL}              {yylval.traducao = yytext; return REAL;}
{ID}	        	{yylval.label = yytext; return ID;}

.	               	*yytext;

%%