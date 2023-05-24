%{
#include <iostream>
#include <string>
#include <sstream>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
};

struct
{
	string nome;
	string tipo_dado;
	string token;
	int num_linha;
	int tamanho;
	string valor;
	string escopo;
} tabela_simbolos[30];

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria();
void adicionaTabela(string,string);
void imprimeTabela();

int tmp_qnt=0;
int cont_tabela=0;

%}

%token MAIN ID NUM REAL TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_STRING ATRIBUI SOMA SUBTRAI MULTIPLICA DIVIDE FIM ERROR

%start S

%left SOMA SUBTRAI
%right MULTIPLICA DIVIDE

%%

S :	TIPO_INT MAIN '(' ')' bloco
{
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{\n" << $5.traducao << "\n\treturn 0;\n}" << endl; 
};

bloco : 	'{' comandos '}'	{$$.traducao = $2.traducao;};

comandos : 	comando comandos 	{$$.traducao = $1.traducao + $2.traducao;} | {$$.traducao = "";};

comando : 	expressao ';';	
 
expressao : expressao SOMA expressao
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
}
|	expressao SUBTRAI expressao
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
}
|	expressao MULTIPLICA expressao
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
}
| 	expressao DIVIDE expressao
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = $1.traducao + $3.traducao + "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
}
|	NUM
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.traducao + ";\n";
}
|	REAL
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.traducao + ";\n";
}
| 	ID
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
}
| 	ID ATRIBUI expressao
{
	$$.traducao = $3.traducao + "\tint " + $1.label +";\n\t" + $1.label + " = " + $3.label + ";\n";
	adicionaTabela($1.label, "ID");
};

%%

#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + std::to_string(tmp_qnt++);
}

void adicionaTabela(string nome, string token)
{
	tabela_simbolos[cont_tabela].nome = nome;
	tabela_simbolos[cont_tabela].token = token;

	cont_tabela++;
}

void imprimeTabela()
{
	cout << "\n\tTABELA DE SíMBOLOS\n\nSÍMBOLO\t\tTOKEN\n----------------------------------\n";
	for(int i=0; i<cont_tabela; i++) {
		cout << tabela_simbolos[i].nome << "\t\t" << tabela_simbolos[i].token<<"\n";
	}
	cout << "----------------------------------\n";
}

int main(int argc, char* argv[])
{	
	yyparse();
	imprimeTabela();
	
	return 0;
}

void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}				
