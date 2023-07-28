%{
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <tuple>
#include <vector>

#define YYSTYPE atributos

#define COERCAO(s1, s3, e1, e3) 				\
	struct atributos e1, e3;					\
	tie(e1,e3) = coercao_tipo(s1,s3)

#define VERIFICACAO_ID(id_nome, num_bloco)													\
		bool teste;																			\
		int num_bloco;																		\
		tie(teste, num_bloco) = testa_simbolo(id_nome);										\
		if (!teste)																			\
		{																					\
			yyerror("A variável \"" + id_nome + "\" não foi declarada!");					\
		}

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
};

struct simbolo
{
	string nome_temp;
	string tipo;
	string valor;
	string tamanho;
	string categoria;
};

struct funcao
{
	string nome;
	string tipo;
	vector<simbolo> param;
};

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria(); // Gera um nome de variável temporária
string geraFuncao();
string geraLabel();
string trad_aritmetica(struct atributos, string, struct atributos, string);
string trad_relacional(struct atributos, string, struct atributos, string);
string trad_if(struct atributos, string, struct atributos, string);
string trad_logico(struct atributos, string, struct atributos, string);
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retorna a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string, string, string); // adiciona um símbolo na tabela, com seu tipo, valor e nome_temp
tuple<struct atributos, struct atributos> coercao_tipo(struct atributos, struct atributos);
tuple<bool, int> testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
string tipo_simbolo(string); // Retorna o tipo do símbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a tradução de todas as declarações do código intermediário, no topo de seu bloco_qtd
inline bool funcao_existe(string nome);
inline string tipo_funcao(string nome);
string verificaFuncao(string tipo, string nome, vector<simbolo> v);
string traducao_atribuicao(struct atributos,struct atributos, string);
void imprimeTabela(); // Imprime a tabela de símbolos

vector<map<string, simbolo>> T_simbolo; // Mapa, identificado pelo nome da variável
vector<map<string, simbolo>> T_debug;

map<string, funcao> T_funcs; // Mapa identificando funções
vector<simbolo> param;

int tmp_qnt = 0;
int num_linha = 1;
int bloco_qtd = -1;
int bloco_qtd_debug = -1;
int label_qnt = 0;
int func_qnt = 0;
string declaracoes = "";

%}

%token MAIN ID NUM REAL CHAR STRING FIM ERROR
%token TIPO
%token ATRIBUI SOMA SUBTRAI MULTIPLICA DIVIDE UNARIOMAIS UNARIOMENOS
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE E_LOGICO OU_LOGICO VERDADEIRO FALSO NEGAR
%token IF ELSE WHILE DO FOR CONTINUE BREAK SWITCH CASE DEFAULT
%token SCAN PRINT

%start S

%left SOMA SUBTRAI
%right MULTIPLICA DIVIDE
%right '('')' E_LOGICO OU_LOGICO 

%%

S: blocofuncao globais
{
	T_debug.push_back(T_simbolo[bloco_qtd]);
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n" + traducao_declaracao() + $2.traducao << endl;
};

globais: global globais
{
	$$.traducao = $1.traducao + $2.traducao;
}
|	MAIN '(' ')' bloco
{
	$$.traducao = "\n\nint main(void)\n{" + declaracoes + $4.traducao + "\n\treturn 0;\n}\n";
};

global:	declaracao
{
	$$.traducao = $1.traducao;
}
|	atribuicao
{
	$$.traducao = $1.traducao;
}
|	TIPO ID blocofuncao '(' parametros ')' '{' comandos '}'
{
	string var = geraFuncao();
	T_funcs[$2.label] = {var, $1.tipo, param};
	$$.traducao = "\n\n" + $1.tipo + " " + var + "("+ $5.traducao + ")\n{\n" + declaracoes + "\n" + $8.traducao + "\n\treturn 0;\n}\n";
	
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
	
	vector<simbolo> a;
	param = a;
	declaracoes = "";
	//cout << param.empty() << endl;
};

parametros:
	p1
{
	$$.traducao = $1.traducao;
}
|
{
	$$.traducao = "";
};

p1:
	parametro ',' parametros
{
	$$.traducao = $1.traducao + ", " + $2.traducao;
}
|	parametro
{
	$$.traducao = $1.traducao;
};

parametro:
	TIPO ID
{
	string var = geraVariavelTemporaria();
	adicionaTabela($2.label, $1.tipo, "N/A", var,"","variável");
	param.push_back(T_simbolo[bloco_qtd][$2.label]);
	$$.traducao = $1.tipo + " " + var;
};

bloco: blocofuncao '{' comandos '}'
{	
	declaracoes = declaracoes + traducao_declaracao();
	$$.traducao = "\t\n" + $3.traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
	T_simbolo.pop_back();
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

blocofuncao:	
{
	bloco_qtd++;
	bloco_qtd_debug++;
	map<string, simbolo> a;
	T_simbolo.push_back(a);
	$$.traducao = "";
}
;

comando: bloco
{	
	$$.traducao = $1.traducao + "\t\n";
}
|	expressao ';'
{
	$$.traducao = "";
}
|	atribuicao
{
	$$.traducao = $1.traducao;
}
|	SWITCH '(' expressao ')' '{' cases '}'
{

}
| IF '(' expressao ')' bloco
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	$$.traducao = $3.traducao + "\t" + neg + " = !" + $3.label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t" + $5.traducao + "\n\t" + lbl +":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	if($3.valor=="true") adicionaTabela(neg, $3.tipo, "false", neg,"","variável");
	else adicionaTabela(neg, $3.tipo, "true", neg, "", "variável");
	
}
| IF '(' expressao ')' bloco ELSE bloco
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = $3.traducao + "\t" + neg + " = !" + $3.label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\t" + $5.traducao + "\tgoto " + saida + ";\n\t" + lbl + ":\t" + $7.traducao + "\n\t" + saida + ":" + "\n";

	adicionaTabela(lbl, "label", "IN", lbl,"","jump");
	adicionaTabela(saida, "label", "OUT", saida,"","jump");
	if($3.valor=="true") adicionaTabela(neg, $3.tipo, "false", neg,"","variável");
	else adicionaTabela(neg, $3.tipo, "true", neg,"","variável");
}
| WHILE '(' expressao ')' bloco
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = "\t" + lbl +":\n\n"+ $3.traducao + "\t" + var + " = !" + $3.label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";"+ $5.traducao + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	adicionaTabela(var, $3.tipo, $3.valor, var,"","variável");

}
| DO bloco WHILE '(' expressao ')' ';'
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = "\t" + lbl + ":" +$2.traducao + "\n" + $5.traducao + "\t" + var + " = !" + $5.label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";
	
	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	adicionaTabela(var, $5.tipo, $5.valor, var,"","variável");

}
| FOR '(' fator ':' fator ')' bloco
{
	string var = geraVariavelTemporaria();
	string var2 = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = $3.traducao + $5.traducao +"\n\t" + lbl +":\n\n\t" + var + " = " + $3.label + " < " + $5.label + "\n\t" +  var2 + " = !" + var + "\t" + "\n\n\tif(" + var2 + ") " + "goto " + saida +";" + $7.traducao + "\n\t" + $3.label + " = " + $3.label + " + 1;" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n";


	adicionaTabela(lbl, "label", "IN", lbl, "", "jump");
	adicionaTabela(saida, "label", "OUT", saida, "", "jump");
	if($3.valor < $5.valor)
	{
	adicionaTabela(var, "bool", "true", var,"","variável");
	adicionaTabela(var2, "bool", "false", var2,"","variável");
	}
	else
	{
		adicionaTabela(var, "bool", "false", var,"","variável");
		adicionaTabela(var2, "bool", "true", var2,"","variável");
	}
	
}
|	SCAN '(' entradas ')' ';'
{
	$$.traducao = $3.traducao;
}
|	PRINT '(' expressoes ')' ';'
{
	$$.traducao = $3.traducao;
}
|	declaracao
{
	$$.traducao = $1.traducao;
}
| 	BREAK ';' //TODO
{
	$$.traducao = "\tgoto label\n";
}
|   CONTINUE ';' //TODO
{
	$$.traducao = "\tgoto label\n";
}
;

cases: CASE NUM ':' comando cases
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = "\n\t" + var + " = !(" + $5.valor + " == " + $2.label + ");" + "\n\tif(" + var + ")" + "\n\tgoto " + lbl + $4.traducao + "\n\tgoto " + $5.label + ";\n\t" + lbl + "\n\t" + $5.traducao +"\n";
	adicionaTabela(var, "bool", "", var,"","variável");
	$$.valor = $5.valor;
	$$.label = $5.label;
}
|	CASE NUM ':' comando
{
	
}
|	DEFAULT ':' comando
{
	$$.traducao = "";
};

atribuicao:	ID ATRIBUI expressao ';'
{
	$$.traducao = traducao_atribuicao($1,$3, "=");
}
|	ID UNARIOMAIS ';'
{
	VERIFICACAO_ID($1.label, bloc)
	$$.traducao = "\t" + T_simbolo[bloc][$1.label].nome_temp + " = " + T_simbolo[bloc][$1.label].nome_temp + " + 1;\n";
}
|	ID UNARIOMENOS ';'
{
	VERIFICACAO_ID($1.label, bloc)
	$$.traducao = "\t" + T_simbolo[bloc][$1.label].nome_temp + " = " + T_simbolo[bloc][$1.label].nome_temp + " - 1;\n";
}
|	ID SOMA ATRIBUI expressao ';'
{
	$$.traducao = traducao_atribuicao($1,$4, "+=");
}
|	ID SUBTRAI ATRIBUI expressao ';'
{
	$$.traducao = traducao_atribuicao($1,$4, "-=");
}
|	ID MULTIPLICA ATRIBUI expressao ';'
{
	$$.traducao = traducao_atribuicao($1,$4, "*=");
}
|	ID DIVIDE ATRIBUI expressao ';'
{
	$$.traducao = traducao_atribuicao($1,$4, "/=");
};

declaracao:
	TIPO ID ';'
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "";
		adicionaTabela($2.label, $1.tipo, "N/A", var,"","variável");
	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO ID '[' ID ']' ';' //OK
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			$$.traducao = "\n\t"+ var + " = malloc(" + T_simbolo[bloco_qtd][$4.label].nome_temp + " * sizeof(" + $1.tipo + "));\n\n";
			adicionaTabela($2.label, $1.tipo, "N/A", var, T_simbolo[bloco_qtd][$4.label].valor, "vetor");
	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO ID '[' ID ']' '[' ID ']' ';'
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			$$.traducao = "\n\t"+ var + " = malloc(" + T_simbolo[bloco_qtd][$4.label].nome_temp + " * " + T_simbolo[bloco_qtd][$7.label].nome_temp + " * sizeof(" + $1.tipo + "));\n\n";
			
			
			string tamanho = to_string(stoi(T_simbolo[bloco_qtd][$4.label].valor) * stoi(T_simbolo[bloco_qtd][$7.label].valor));

			adicionaTabela($2.label, $1.tipo, "N/A", var, tamanho, "vetor");


	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO ID '[' NUM ']' ';'
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);

	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			string var2 = geraVariavelTemporaria();
			$$.traducao = "\t" + var + " = " + $4.traducao +";\n\t"+ var2 + " = malloc(" + var + " * sizeof(" + $1.tipo + "));\n\n";
			
			adicionaTabela(var, "int", $4.traducao, var, "", "variável");
			adicionaTabela($2.label, $1.tipo, "N/A", var2, $4.traducao, "vetor");

	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO ID '[' NUM ']' '[' NUM ']' ';'
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);

	if ((!teste) || bloc != bloco_qtd)
	{		
			string var = geraVariavelTemporaria();
			string var2 = geraVariavelTemporaria();
			string var3 = geraVariavelTemporaria();
			$$.traducao = "\t" + var + " = " + $4.traducao +";\n\t" + var2 + " = " + $7.traducao +";\n\t"+ var3 + " = malloc(" + var + " * " + var2 +" * sizeof(" + $1.tipo + "));\n\n";
			
			adicionaTabela(var, "int", $4.traducao, var, "", "variável");
			adicionaTabela(var2, "int", $7.traducao, var2, "", "variável");

            string tamanho = to_string(stoi($4.traducao) * stoi($7.traducao));
			adicionaTabela($2.label, $1.tipo, "N/A", var3, tamanho, "vetor");

	}else{
		yyerror("Variável já declarada!");
	}
};;

entradas:
	ID ',' entradas
{
	VERIFICACAO_ID($1.label, bloc)
	$$.traducao = "\n\tcin >> " + T_simbolo[bloc][$1.label].nome_temp + ";" + $3.traducao;
}
|	ID
{
	VERIFICACAO_ID($1.label, bloc)
	$$.traducao = "\n\tcin >> " + T_simbolo[bloc][$1.label].nome_temp + ";\n";
};

expressoes:
	expressao ',' expressoes
{
	$$.traducao = $1.traducao + "\n\tcout << " + $1.label + ";\n" + $3.traducao;
}
|	expressao
{
	$$.traducao = "\n" + $1.traducao + "cout << " + $1.label + ";\n";
};

expressao:
// 	Operadores lógicos
	expressao E_LOGICO relacao
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "&&", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	expressao OU_LOGICO relacao
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "||", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	relacao
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
	$$.tipo = $1.tipo;
	$$.valor = $1.valor;
};
relacao:
//	Operadores relacionais
	aritmetica IGUAL aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "==", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	aritmetica DIFERENTE aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "!=", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
//	Operadores relacionais
|	aritmetica MAIOR aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, ">", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	aritmetica MENOR aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "<", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	aritmetica MAIOR_IGUAL aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, ">=", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	aritmetica MENOR_IGUAL aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "<=", e3, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	NEGAR relacao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($2, "!", $2, $$.label);
	$$.tipo = "bool";
	$$.valor = "";
}
|	converte
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
	$$.tipo = $1.tipo;
	$$.valor = $1.valor;
};

converte:
// Conversão explicita
	'(' TIPO ')' expressao
{
	if($2.tipo != "int" || $2.tipo != "float")
	{
		yyerror("A converção explicita para o tipo: \"" + $2.tipo + "\" não é suportada!");
	}
	if($4.tipo == "string")
	{
		yyerror("A converção explicita a partir do tipo: \"string\" não é suportada!");
	}
	$$.valor = to_string(stoi($4.valor));

	$$.label = geraVariavelTemporaria();
	$$.traducao = $4.traducao + "\t" + $$.label + " = (" + $2.tipo + ")" + $4.label + ";\n";
	adicionaTabela($$.label, $2.tipo, $$.valor, $$.label,"","variável");
	$$.tipo = $2.label;
}
|	aritmetica
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
	$$.tipo = $1.tipo;
	$$.valor = $1.valor;
};

aritmetica:
// 	Operadores matemáticos
	fator
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
	$$.tipo = $1.tipo;
	$$.valor = $1.valor;
}
|	aritmetica SOMA aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "+", e3, $$.label);
	$$.tipo = e1.tipo;
	$$.valor = "";
}
|	aritmetica SUBTRAI aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "-", e3, $$.label);
	$$.tipo = e1.tipo;
	$$.valor = "";
}
|	aritmetica MULTIPLICA aritmetica
{
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "*", e3, $$.label);
	$$.tipo = e1.tipo;
	$$.valor = "";
}
| 	aritmetica DIVIDE aritmetica
{
	if(stof($3.valor)==0) yyerror("Divisão por zero");
	
	$$.label = geraVariavelTemporaria();
	COERCAO($1, $3, e1, e3);
	$$.traducao = traducao_expressao(e1, "/", e3, $$.label);
	$$.tipo = e1.tipo;
	$$.valor = "";
}
|	SOMA aritmetica
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label + ";\n";
	$$.tipo = $2.tipo;
	$$.valor = $2.valor;

	adicionaTabela($$.label, $2.tipo, "N/A", $$.label,"","variável");
}
|	SUBTRAI aritmetica
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = $2.traducao + "\t" + $$.label + " = " + "-" + " " + $2.label + ";\n";
	$$.tipo = $2.tipo;
	$$.valor = "-" + $2.valor;

	adicionaTabela($$.label, $$.tipo, "N/A", $$.label,"","variável");
}
;

fator:
// Simbolos terminais
	NUM
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
	$$.tipo = "int";
	$$.valor = $1.traducao;
	adicionaTabela($$.label, $$.tipo, $1.traducao, $$.label, "","variável");
}
|	REAL
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
	$$.tipo = "float";
	$$.valor = $1.traducao;
	adicionaTabela($$.label, $$.tipo, $1.traducao, $$.label, "","variável");
}
|	CHAR
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + "';\n";
	$$.tipo = "char";
	$$.valor = $1.traducao;
	adicionaTabela($$.label, $$.tipo ,$$.valor, $$.label,"","variável");
}
|	STRING
{
	$$.tipo = "string";
	$$.valor = $1.traducao;
	$$.label = geraVariavelTemporaria();
	adicionaTabela($$.label, $$.tipo, $$.valor, $$.label,"","variável");
	$$.traducao = "\tstrcpy(" + $$.label + ", " + $1.traducao + ");\n\t";	
	
}	
| 	ID
{
	VERIFICACAO_ID($1.label, bloc)
	else
	{
		$$.traducao ="";
		$$.label = T_simbolo[bloc][$1.label].nome_temp;
		//cout<<tipo_simbolo($1.label)<<endl;
		$$.tipo = tipo_simbolo($1.label);
		$$.valor = T_simbolo[bloc][$1.label].valor;
	}
}
| 	VERDADEIRO
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
	$$.tipo = "bool";
	$$.valor = "true";
	adicionaTabela($$.label, "bool", "true", $$.label,"","variável");
}
| 	FALSO
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
	$$.tipo = "bool";
	$$.valor = "false";
	adicionaTabela($$.label, "bool", "false", $$.label,"","variável");
}
|	'(' expressao ')'
{
	$$.traducao = $2.traducao;
	$$.label = $2.label;
	$$.tipo = $2.tipo;
	$$.valor = $2.valor;
}
|	ID '(' expressoes ')'
{

};

%%

#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + to_string(tmp_qnt++);
}

string geraFuncao()
{
	return "FUNC_" + to_string(func_qnt++);
}

string geraLabel()
{
	return "L" + to_string(label_qnt++);
}

string trad_aritmetica(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(s1.tipo == "bool")
	{
		yyerror("Tipo bool não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if(s1.tipo == "char")
	{
		yyerror("Tipo char não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if((s1.tipo == "float" || s1.tipo == "int"))
	{	
			traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";
			adicionaTabela(temp, s1.tipo, s1.valor + operador + s3.valor, temp,"","aritmetica");
	}

	return traducao;
}

string trad_relacional(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";

	if(s1.tipo == "bool")
	{
		if (operador == "<" || operador == ">" || operador == "<=" || operador == ">=")
		{
			yyerror("Tipo não suporta operações relacionais (<, >, >=, <=)"); // termina a função
		}
		else
		{
			if(operador == "==")
			{
				if(s1.valor == s3.valor)
				{
					adicionaTabela(temp, "bool", "true", temp,"","variável");
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp,"","variável");
				}
			}
			else if (operador == "!=")
			{
				if(s1.valor != s3.valor)
				{
					adicionaTabela(temp, "bool", "true", temp,"","variável");
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp,"","variável");
				}
			}	
		}

	}
	
// tipos numéricos e char
	if (s1.tipo == "float" || s1.tipo == "int" || s1.tipo == "char")
	{
		if(operador == "==")
		{
			if(s1.valor == s3.valor)
			{
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}

		else if (operador == "!=")
		{
			if(s1.valor != s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == ">")
		{
			if(s1.valor > s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == "<")
		{
			if(s1.valor < s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == "<=")
		{
			if(s1.valor <= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == ">=")
		{
			if(s1.valor >= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
	}

	return traducao;
}

string trad_logico(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";

	if(s1.tipo == "bool")
	{
		if((operador == "&&" || operador == "||") && (s1.valor == "true" && s3.valor == "true")){
			adicionaTabela(temp, "bool", "true", temp,"","variável");
		}
		else if(operador == "&&" && (s1.valor == "false" || s3.valor == "false")){

			adicionaTabela(temp, "bool", "false", temp,"","variável");
		}
		else if(operador == "||"){
			if((s1.valor == "false" && s3.valor == "true") || (s1.valor == "true" && s3.valor == "false"))
			{
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
			else if (s1.valor == "false" && s3.valor == "false"){
				adicionaTabela(temp, "bool", "false", temp,"","variável");
			}
		}else
		{
			traducao = s1.traducao + "\t" + temp + " = " + operador + " " + s1.label + ";\n";
			if(s3.valor == "true")
			{
				adicionaTabela(temp, "bool", "false", temp,"","variável");
			}
			else 
			{
				adicionaTabela(temp, "bool", "true", temp,"","variável");
			}
		}
	}else
	{
		yyerror("Tipo não suporta as operações lógicas (||, &&, !)");
	}

	return traducao;
}

string traducao_expressao(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/"|| operador == "++")
	{
		return trad_aritmetica(s1, operador, s3, temp);
	}
	if(operador == "&&"|| operador == "||" || operador == "!")
	{
		return trad_logico(s1, operador, s3, temp);
	}
	if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=")
	{
		return trad_relacional(s1, operador, s3, temp);
	}

	return traducao;
}

tuple<struct atributos, struct atributos> coercao_tipo(struct atributos s1, struct atributos s3)
{
	tuple <struct atributos, struct atributos> expr(s1,s3);
	string tipo1 = s1.tipo;
	string tipo3 = s3.tipo;
	if(tipo1 == tipo3)
		return expr;

	if(tipo1 == "string" || tipo3 == "string")
		yyerror("Tipo string não suporta coerção");

	if(tipo1 == "bool" || tipo3 == "bool")
		yyerror("Tipo booleano não suporta coerção");
	
	struct atributos novo;
	novo.traducao = "";
	novo.label = geraVariavelTemporaria();
	
	if(tipo1 == "float") // Regra para coerção float
	{
		if(tipo3 == "int") // Regra para coerção int
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (float)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(s3.valor)), novo.label,"","variável");
			get<1>(expr) = novo;
		}
		else if(tipo3 == "char") // Regra para coerção char
		{
			yyerror("Expressão não definida para os tipos float e char");
		}
	}
	else if(tipo3 == "float") // Regra para coerção float
	{
		if(tipo1 == "int") // Regra para coerção int
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (float)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(s1.valor)), novo.label,"","variável");
			get<0>(expr) = novo;
		}
		else if(tipo1 == "char") // Regra para coerção de char
		{
			yyerror("Expressão não definida para os tipos char e float");
		}
	}
	else if(tipo1 == "int") // Regra para coerção int
	{
		if(tipo3 == "char") // Regra para coerção char
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (int)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "int", (s3.valor), novo.label,"","variável");
			get<1>(expr) = novo;
		}
	}else if(tipo3 == "int") // Regra para coerção int
	{
		if(tipo1 == "char") // Regra para coerção char
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (int)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "int", (s3.valor), novo.label,"","variável");
			get<0>(expr) = novo;
		}
	}

	return expr;
}

//retorna True se o símbolo está na tabela e False caso o contrario
tuple<bool, int> testa_simbolo(string nome)
{
	int i;
	bool r = false;
	for(i=bloco_qtd;i>=0;i--)
	{
		r = T_simbolo[i].count(nome)==1;
		if(r)
			break;
	}
	tuple<bool, int> resp(r, i);
	return resp;
}

void adicionaTabela(string nome, string tipo, string valor, string novo_nome, string tamanho, string categoria)
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(nome);
	if ((!teste) || bloc != bloco_qtd)
	{
		simbolo novo;
		novo.tipo = tipo;
		novo.nome_temp = novo_nome;
		novo.valor = valor;
		novo.tamanho = tamanho;
		novo.categoria = categoria;
		T_simbolo[bloco_qtd][nome] = novo;
	}
}

// se o simbolo não estiver na tabela retorna mensagem de erro, caso contrário retorna o tipo do simbolo  
string tipo_simbolo(string nome)
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(nome);
	if (!teste)
	{
		yyerror("Variável não declarada");
	}
	//cout << T_simbolo[nome].tipo << endl;
	return T_simbolo[bloc][nome].tipo;
}

string traducao_declaracao()
{
	string traducao = "\n";
	for(auto const& [key, val]: T_simbolo[bloco_qtd]) {
		if(val.tipo=="bool")
		{
			traducao = traducao + "\t"+ "int" + " " + val.nome_temp + ";\n";
			continue;
		}
		if(val.tipo=="string"){			
			
			traducao = traducao + "\t"+ "char *" + val.nome_temp + ";\n\t" + val.nome_temp + " = malloc("+ to_string(size(val.valor)-1)+ "*sizeof(char));\n";
			continue;
		}
		if(val.tipo=="label"){			
			continue;
		}
		
		
		traducao = traducao + "\t"+ val.tipo + " " + val.nome_temp + ";\n";
		
	}
	return traducao;
}

inline bool funcao_existe(string nome)
{
	return T_funcs.count(nome) == 1;
}

inline string tipo_funcao(string nome)
{
	return T_funcs[nome].tipo;
}

string verificaFuncao(string tipo, string nome, vector<simbolo> v)
{
	struct atributos s1, s3;
	if(funcao_existe(nome))
	{
		if(v.size()!=T_funcs[nome].param.size())
		yyerror("O número de parametros na função não é compátivel");
		for (int i; i<v.size();i++)
		{
			if(T_funcs[nome].param[i].tipo!=v[i].tipo)
			{
				struct simbolo c1 = T_funcs[nome].param[i];
				struct simbolo c2 = v[i];
				s1 = {c1.nome_temp, "", c1.tipo, c1.valor};
				s3 = {c2.nome_temp, "", c2.tipo, c2.valor};
				COERCAO(s1, s3, e1, e3);
				yyerror("A função esperava " + T_funcs[nome].param[i].tipo + ", mas recebeu " + v[i].tipo + " na posição " + to_string(i) + ".");
			}
		}
	}else
	{
		yyerror("Função \"" + nome + "\" não definida!");
	}
	return "";
}

string aval_sinal_attr(string nome1,string nome2, string sinal, string coercao)
{
	int s;
	s = (sinal == "=")? 0: ((sinal == "+=")? 1: ((sinal == "-=")? 2: ((sinal == "*=")? 3: ((sinal == "/=")? 4: -1))));
	switch(s)
	{
		case 0: return coercao + nome2;
		case 1:	return nome1 + " + " + coercao + nome2;
		case 2: return nome1 + " - " + coercao + nome2;
		case 3:	return nome1 + " * " + coercao + nome2;
		case 4:	return nome1 + " / " + coercao + nome2;
	}
	return "";
}

string traducao_atribuicao(struct atributos s1, struct atributos s3, string sinal)
{
	bool teste;
	string traducao;
	int bloc;
	tie(teste, bloc) = testa_simbolo(s1.label);

	if ((!teste))
	{
		if(sinal != "=")
			yyerror("A variável " + s1.label + " não está inicializada.");
		if(s3.tipo =="string")
		{
			string var = geraVariavelTemporaria();
			traducao = s3.traducao + "\tstcpy(" + var + ", " + s3.label + ");\n";
			adicionaTabela(s1.label,s3.tipo, s3.valor, var,"","variável");
		}
		else 
		{
			string var = geraVariavelTemporaria();
			traducao = s3.traducao + "\t" + var + " = " + s3.label + ";\n";
			adicionaTabela(s1.label,s3.tipo, s3.valor, var,"","variável");
		}
	}
	else
	{
		s1.tipo = tipo_simbolo(s1.label);
		//cout << bloc<<endl;
		if(s1.tipo == s3.tipo)
		{
			if(s1.tipo == "string")
			{
				if(sinal != "=")
					yyerror("string não suporta esse tipo de atribuição: " + sinal + ".");
				traducao = s3.traducao+"\n";
			}
			else
			{
				traducao = s3.traducao + "\t" + T_simbolo[bloc][s1.label].nome_temp + " = " + aval_sinal_attr(T_simbolo[bloc][s1.label].nome_temp, s3.label, sinal,"") + ";\n";
			}
		}
		else if(s3.tipo == "bool")
		{
			yyerror("Variável esperava tipo " + s1.tipo + ", mas recebeu tipo " + s3.tipo);
		}
		else if(s1.tipo == "float") // Regra para coerção float
		{
			if(s3.tipo == "int") // Regra para coerção int
			{
				traducao = s3.traducao + "\t" + T_simbolo[bloc][s1.label].nome_temp + " = " + aval_sinal_attr(T_simbolo[bloc][s1.label].nome_temp, s3.label, sinal, " (float) ") + ";\n";
			}
			else if(s3.tipo == "char") // Regra para coerção char
			{
				yyerror("Variável esperava tipo " + s1.tipo + ", mas recebeu tipo " + s3.tipo);
			}
		}
		else if(s1.tipo == "int") // Regra para coerção int
		{
			if(s3.tipo == "float") // Regra para coerção float
			{
				traducao = s3.traducao + "\t" + T_simbolo[bloc][s1.label].nome_temp + " = " + aval_sinal_attr(T_simbolo[bloc][s1.label].nome_temp, s3.label, sinal, " (int) ") + ";\n";
			}
			else if(s3.tipo == "char") // Regra para coerção de char
			{
				traducao = s3.traducao + "\t" + T_simbolo[bloc][s1.label].nome_temp + " = " + aval_sinal_attr(T_simbolo[bloc][s1.label].nome_temp, s3.label, sinal, " (int) ") + ";\n";
			}
		}
		else if(s3.tipo=="string")
		{
			cout<<T_simbolo[bloc][s3.label].valor;
			string var = geraVariavelTemporaria();
			traducao = s3.traducao;
			//adicionaTabela($$.label,$$.tipo, T_simbolo[bloc][$3.label].valor, var);
		}
		else{
			yyerror("Variável esperava tipo " + s1.tipo + ", mas recebeu tipo " + s3.tipo);
		}
		//T_simbolo[bloc][$1.label].valor = T_simbolo[bloc][$3.label].valor;
	}
	return traducao;
}

void imprimeTabela()
{
	for (int i = 0; i <= bloco_qtd_debug; i++)
	{
		cout << "\n\n\t\tTABELA DE SíMBOLOS | BLOCO " << i <<"\n\nSÍMBOLO\t\tTIPO\tCATEGORIA\tATRIBUIÇÃO\tTAMANHO\t\tNOME\n------------------------------------------------------------------------------\n";
		for(auto const& [key, val]: T_debug[i]) {
			
			if(val.categoria=="vetor"){
				cout << key << "\t\t" + val.tipo << "\t" + val.categoria << "\t\t" + val.valor << "\t\t" + val.tamanho << "\t\t" + val.nome_temp<<"\n";
				continue;
			}
			cout << key << "\t\t" + val.tipo << "\t" + val.categoria << "\t" + val.valor << "\t\t" + val.tamanho << "\t\t" + val.nome_temp<<"\n";

		}
		cout << "------------------------------------------------------------------------------\n";
	}
}

int main(int argc, char* argv[])
{	
	yyparse();
	imprimeTabela();
	
	return 0;
}

void yyerror(string MSG)
{
	cout << "ERRO! linha " << num_linha << " | " << MSG << endl;
	exit (0);
}				
