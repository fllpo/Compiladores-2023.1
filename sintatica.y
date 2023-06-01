%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
};

struct
{
	string nome_temp;
	string tipo;
	string token;
	int num_linha;
	int tamanho;
	string valor;
	string escopo;
} typedef simbolo;

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria();
void adicionaTabela(string, string, string);
bool testa_simbolo(string); // Testa se a variavel esta na tabela (se ja foi declarada)
string tipo_simbolo(string nome); // Retorna o tipo do simbolo caso esse esteja na tabela 
void imprimeTabela();

std::map<std::string, simbolo> T_simbolo; // Mapa, identificado pelo nome da variavel

int tmp_qnt=0;

%}

%token MAIN ID NUM REAL TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_STRING ATRIBUI SOMA SUBTRAI MULTIPLICA DIVIDE FIM ERROR

%start S

%left SOMA SUBTRAI
%right MULTIPLICA DIVIDE

%%

S: TIPO_INT MAIN '(' ')' bloco		{cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{\n" << $5.traducao << "\n\treturn 0;\n}" << endl;};

bloco: '{' comandos '}'
{
	
	$$.traducao = "\tDECLARACOES DE VARIAVEIS AQUI;\n"+$2.traducao;
}
;

comandos: comando comandos 			
{
	$$.traducao = $1.traducao + $2.traducao;
} 
| 
{
	$$.traducao = "";
}
;

comando: expressao ';';
|	ID ATRIBUI expressao ';'
{
	$$.traducao = $3.traducao + "\t" + T_simbolo[$3.label].tipo +" "+ $1.label +";\n\t" + $1.label + " = " + $3.label + ";\n";
	adicionaTabela($1.label,T_simbolo[$3.label].tipo, $3.label);
}
|	TIPO_INT ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "\tint " + var + ";\n";
		adicionaTabela($2.label, "int", "N/A");
	}
}
|	TIPO_FLOAT ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "\tfloat " + var + ";\n";
		adicionaTabela($2.label, "float", "N/A");
	}
}
;

expressao:
// Operadores matematicos
expressao SOMA expressao
{
	$$.label = geraVariavelTemporaria();

	if (T_simbolo[$1.label].tipo == T_simbolo[$3.label].tipo)
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " + " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$1.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " + (float)" + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$3.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$3.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = (float)" + $1.label + " + " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$3.label].tipo, "N/A");
	}
}
|	expressao SUBTRAI expressao
{
	$$.label = geraVariavelTemporaria();

	if (T_simbolo[$1.label].tipo == T_simbolo[$3.label].tipo)
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " - " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$1.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " - (float)" + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$3.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$3.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = (float)" + $1.label + " - " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$3.label].tipo, "N/A");
	}
}
|	expressao MULTIPLICA expressao
{
	$$.label = geraVariavelTemporaria();

	if (T_simbolo[$1.label].tipo == T_simbolo[$3.label].tipo)
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " * " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$1.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " * (float)" + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$3.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$3.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = (float)" + $1.label + " * " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$3.label].tipo, "N/A");
	}
}
| 	expressao DIVIDE expressao
{
	$$.label = geraVariavelTemporaria();

	if(T_simbolo[$3.label].valor=="0"||T_simbolo[$3.label].valor=="0.0") yyerror("ERRO: Divisao por zero");

	if (T_simbolo[$1.label].tipo == T_simbolo[$3.label].tipo)
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " / " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$1.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$1.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = " + $1.label + " / (float)" + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$1.label].tipo, "N/A");
	}
	else if(T_simbolo[$3.label].tipo == "float")
	{
		$$.traducao = $1.traducao + $3.traducao + "\t" + T_simbolo[$3.label].tipo + " " + $$.label + ";\n\t" + $$.label + " = (float)" + $1.label + " / " + $3.label + ";\n";
		adicionaTabela($$.label, T_simbolo[$3.label].tipo, "N/A");
	}
}
// Conversao explicita
/*|	"(" TIPO_INT ")" expressao
{

}
|	"(" TIPO_FLOAT ")" expressao
{

}
*/
// Simbolos terminais
|	NUM
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\tint " + $$.label + ";\n\t" + $$.label + " = " + $1.traducao + ";\n";
	adicionaTabela($$.label, "int", $1.traducao);
}
|	REAL
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\tfloat " + $$.label + ";\n\t" + $$.label + " = " + $1.traducao + ";\n";
	adicionaTabela($$.label, "float" ,$1.traducao);
}
| 	ID
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";

};

%%

#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + std::to_string(tmp_qnt++);
}

//retorna True se o simbolo esta na tabela e False caso o contrario
bool testa_simbolo(string nome)
{
	return (T_simbolo.count(nome)==1);
}

void adicionaTabela(string nome, string tipo, string valor)
{
	simbolo novo;
	novo.tipo = tipo;
	//novo.nome_temp = novo_nome;
	novo.valor = valor;
	T_simbolo[nome] = novo;
}

// se o simbolo não estiver na tabela retorna mensagem de erro, caso contrário retorna o tipo do simbolo  
string tipo_simbolo(string nome)
{
	if (!(testa_simbolo(nome)))
	{
		yyerror("Variavel nao declarada!");
	}
	return T_simbolo[nome].tipo;
}

void imprimeTabela()
{
	cout << "\n\tTABELA DE SíMBOLOS\n\nSÍMBOLO\t\tTIPO\t\tVALOR\n------------------------------------------------------\n";
	for(auto const& [key, val]: T_simbolo) {
		cout << key << "\t\t" << val.tipo << "\t\t" << val.valor<<"\n";
	}
	cout << "------------------------------------------------------\n";
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