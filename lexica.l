%{
#include <string>
extern int num_linha;
%}

espaco              [ \t]
digito              [0-9]
letra               [A-Za-z_]

DELIM               {espaco}+
NUM                 {digito}+ 
REAL                {NUM}+("."{NUM}+)?      
CHAR                \'{letra}|{NUM}\'
STRING              \"(({letra}|{NUM})*)\"
ID                  {letra}({letra}|{NUM})*
%%

"\n"		        {} num_linha+=1;

{DELIM} 	        {}

"main"		        return MAIN;

"int"|"float"|"char"|"bool"|"string"		        {yylval.tipo = yytext; return TIPO;}

[(){}[\];,:]	    return *yytext;

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
"true"              return VERDADEIRO;
"false"             return FALSO;
"!"                 return NEGAR;

"switch"            return SWITCH;
"case"              return CASE;
"default"           return DEFAULT;
"if"                return IF;
"else"              return ELSE;
"while"             return WHILE;
"do"                return DO;
"for"               return FOR;
"continue"          return CONTINUE;
"break"             return BREAK;
"scan"              return SCAN;
"print"             return PRINT;
"++"                return UNARIOMAIS;
"--"                return UNARIOMENOS;


{NUM}               {yylval.traducao = yytext; return NUM;}
{REAL}              {yylval.traducao = yytext; return REAL;}
{CHAR}              {yylval.traducao = yytext; return CHAR;}
{STRING}            {yylval.traducao = yytext; return STRING;}
{ID}	        	{yylval.label = yytext; return ID;}

.	               	*yytext;

%%