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

string geraVariavelTemporaria(); // Gera um nome de variário temp
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retona a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string); // adiciona um simbolo na tabela, com seu tipo, valor e nome_temp
bool testa_simbolo(string); // Testa se a variavel esta na tabela (se ja foi declarada)
string tipo_simbolo(string); // Retorna o tipo do simbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a traduçao de todas as declarações do código intermediário, no topo de seu bloco
void imprimeTabela(); // Imprime a tabela de simbolos

std::map<std::string, simbolo> T_simbolo; // Mapa, identificado pelo nome da variavel

int tmp_qnt=0;

%}

%token MAIN ID NUM REAL TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_BOOL TIPO_STRING ATRIBUI SOMA SUBTRAI MULTIPLICA DIVIDE FIM ERROR

%start S

%left SOMA SUBTRAI
%right MULTIPLICA DIVIDE

%%

S: TIPO_INT MAIN '(' ')' bloco		{cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{\n" << $5.traducao << "\n\treturn 0;\n}" << endl;};

bloco: '{' comandos '}'
{
	
	$$.traducao = "\tDECLARACOES DE VARIAVEIS AQUI:\n\n" + traducao_declaracao() + "\n" + $2.traducao;
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
	string var = geraVariavelTemporaria();
	$$.traducao = $3.traducao + "\t" + var + " = " + $3.label + ";\n";
	adicionaTabela($1.label,T_simbolo[$3.label].tipo, "N/A", var);
}
/*
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
*/
;

expressao:
// Operadores matematicos
expressao SOMA expressao
{
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "+", $3, $$.label);
}
|	expressao SUBTRAI expressao
{
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "-", $3, $$.label);
}
|	expressao MULTIPLICA expressao
{
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "*", $3, $$.label);
}
| 	expressao DIVIDE expressao
{
	$$.label = geraVariavelTemporaria();

	if(T_simbolo[$3.label].valor=="0"||T_simbolo[$3.label].valor=="0.0") yyerror("ERRO: Divisao por zero");

	$$.traducao = traducao_expressao($1, "/", $3, $$.label);
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
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
	adicionaTabela($$.label, "int", $1.traducao, $$.label);
}
|	REAL
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
	adicionaTabela($$.label, "float" ,$1.traducao, $$.label);
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

string traducao_expressao(struct atributos s1, string sinal, struct atributos s3, string temp)
{
	string traducao = "";
	if (T_simbolo[s1.label].tipo == T_simbolo[s3.label].tipo)
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " + " + s3.label + ";\n";
		adicionaTabela(temp, T_simbolo[s1.label].tipo, "N/A", temp);
	}
	else if(T_simbolo[s1.label].tipo == "float")
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " + (float)" + s3.label + ";\n";
		adicionaTabela(temp, T_simbolo[s1.label].tipo, "N/A", temp);
	}
	else if(T_simbolo[s3.label].tipo == "float")
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = (float)" + s1.label + " + " + s3.label + ";\n";
		adicionaTabela(temp, T_simbolo[s3.label].tipo, "N/A", temp);
	}
	return traducao;
}

//retorna True se o simbolo esta na tabela e False caso o contrario
bool testa_simbolo(string nome)
{
	return (T_simbolo.count(nome)==1);
}

void adicionaTabela(string nome, string tipo, string valor, string novo_nome)
{
	if (!(testa_simbolo(nome)))
	{
		simbolo novo;
		novo.tipo = tipo;
		novo.nome_temp = novo_nome;
		novo.valor = valor;
		T_simbolo[nome] = novo;
		
	}else if (tipo_simbolo(nome) != tipo)
	{
		// adicionar conversao e casos de erro
	}
}

// se o simbolo não estiver na tabela retorna mensagem de erro, caso contrário retorna o tipo do simbolo  
string tipo_simbolo(string nome)
{
	if (!(testa_simbolo(nome)))
	{
		yyerror("Variavel nao declarada!");
	}
	cout << T_simbolo[nome].tipo << endl;
	return T_simbolo[nome].tipo;
}

string traducao_declaracao()
{
	string traducao = "";
	for(auto const& [key, val]: T_simbolo) {
		traducao = traducao + "\t"+ val.tipo + " " + val.nome_temp + ";\n";
	}
	return traducao;
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