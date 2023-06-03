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

string geraVariavelTemporaria(); // Gera um nome de variável temporária
string aritmetica(struct atributos, string, struct atributos, string);
string relacional(struct atributos, string, struct atributos, string); // WIP - falta implementar
string logico(struct atributos, string, struct atributos, string);
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retorna a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string); // adiciona um símbolo na tabela, com seu tipo, valor e nome_temp
bool testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
string tipo_simbolo(string); // Retorna o tipo do símbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a tradução de todas as declarações do código intermediário, no topo de seu bloco
void imprimeTabela(); // Imprime a tabela de símbolos

std::map<std::string, simbolo> T_simbolo; // Mapa, identificado pelo nome da variável

int tmp_qnt = 0;
int num_linha = 1;

%}

%token MAIN ID NUM REAL FIM ERROR
%token TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_BOOL TIPO_STRING
%token ATRIBUI SOMA SUBTRAI MULTIPLICA DIVIDE 
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE E_LOGICO OU_LOGICO VERDADEIRO FALSO NEGAR

%start S

%left SOMA SUBTRAI
%right MULTIPLICA DIVIDE

%%

S: TIPO_INT MAIN '(' ')' bloco
{
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{" << $5.traducao << "\n\treturn 0;\n}" << endl;
};

bloco: '{' comandos '}'
{	
	$$.traducao = "\t\n" + traducao_declaracao() + "\n" + $2.traducao;
};

comandos: comando comandos 			
{
	$$.traducao = $1.traducao + $2.traducao;
} 
| 
{
	$$.traducao = "";
};

comando: expressao ';';
|	ID ATRIBUI expressao ';'
{
	string var = geraVariavelTemporaria();
	$$.traducao = $3.traducao + "\t" + var + " = " + T_simbolo[$3.label].nome_temp + ";\n";
	adicionaTabela($1.label, T_simbolo[$3.label].tipo, T_simbolo[$3.label].valor, var);
	
};
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
|	TIPO_BOOL ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "\tbool " + var + ";\n";
		adicionaTabela($2.label, "bool", "N/A");
	}
}
*/

expressao:
// 	Operadores matemáticos
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
	if(std::stof(T_simbolo[$3.label].valor)==0) yyerror("Divisão por zero");
	
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "/", $3, $$.label);
}
//	Operadores relacionais
|	expressao MAIOR expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, ">", $3, $$.label);
}
|	expressao MENOR expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "<", $3, $$.label);
}
|	expressao MAIOR_IGUAL expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, ">=", $3, $$.label);
}
|	expressao MENOR_IGUAL expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "<=", $3, $$.label);
}
|	expressao IGUAL expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "==", $3, $$.label);
}
|	expressao DIFERENTE expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "!=", $3, $$.label);
}
// 	Operadores lógicos
|	expressao E_LOGICO expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "&&", $3, $$.label);
}
|	expressao OU_LOGICO expressao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "||", $3, $$.label);
}
/* WIP
| NEGAR expressao
{
	$$.label = geraVariavelTemporaria();

	$$.traducao == "";
}*/
// Conversão explicita
|	'(' TIPO_INT ')' expressao
{
	string conversao = std::to_string(stoi(T_simbolo[$4.label].valor));

	$$.label = geraVariavelTemporaria();
	
	$$.traducao = $1.traducao + $3.traducao + "\t" + $4.label + " = " + T_simbolo[$4.label].valor + ";\n\t" + $$.label + " = (int)" + $4.label + ";\n";
	
	adicionaTabela($$.label, "int", conversao, $$.label);
}
|	'(' TIPO_FLOAT ')' expressao
{
	string conversao = std::to_string(stof(T_simbolo[$4.label].valor));

	$$.label = geraVariavelTemporaria();
	$$.traducao = $1.traducao + $3.traducao + "\t" + $4.label + " = " + T_simbolo[$4.label].valor + ";\n\t" + $$.label + " = (float)" + $4.label + ";\n";
	adicionaTabela($$.label, "int", conversao, $$.label);
}
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
	if(!(testa_simbolo($1.label)))
	{
		$$.label = geraVariavelTemporaria();
		$$.traducao = "\t" + $$.label + " = " + $1.label + ";\n";
	}else
	{
		$$.traducao = "";
	}
}
| 	VERDADEIRO
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + "1" + ";\n";
	adicionaTabela($$.label, "bool", "true", $$.label);
}
| 	FALSO
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
	adicionaTabela($$.label, "bool", "false", $$.label);
};

%%

#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + std::to_string(tmp_qnt++);
}

string aritmetica(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(T_simbolo[s1.label].tipo == "bool" || T_simbolo[s3.label].tipo == "bool")
	{
		yyerror("Tipo booleano não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if((T_simbolo[s1.label].tipo == T_simbolo[s3.label].tipo) && (T_simbolo[s1.label].tipo == "float" || T_simbolo[s1.label].tipo == "int"))
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
		adicionaTabela(temp, T_simbolo[s1.label].tipo, T_simbolo[s1.label].valor + operador + T_simbolo[s3.label].valor, temp);
	}
	else if((T_simbolo[s1.label].tipo != T_simbolo[s3.label].tipo) && T_simbolo[s1.label].tipo == "float")
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " (float)" + T_simbolo[s3.label].nome_temp + ";\n";
		adicionaTabela(temp, T_simbolo[s1.label].tipo, T_simbolo[s1.label].valor + operador + T_simbolo[s3.label].valor , temp);
	}
	else if((T_simbolo[s1.label].tipo != T_simbolo[s3.label].tipo) && T_simbolo[s3.label].tipo == "float")
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = (float)" + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
		adicionaTabela(temp, T_simbolo[s3.label].tipo, T_simbolo[s1.label].valor + operador + T_simbolo[s3.label].valor, temp);
	}

	return traducao;
}

string relacional(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(T_simbolo[s1.label].tipo == "bool" || T_simbolo[s3.label].tipo == "bool")
	{
		if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=")
			yyerror("Tipo não suporta operações relacionais (<, >, >=, <=)"); // termina a função
	}
	
	if(T_simbolo[s1.label].tipo != "bool" && T_simbolo[s3.label].tipo != "bool") // tipos numéricos
	{
		if(operador == "==")
		{
			if (T_simbolo[s1.label].tipo == T_simbolo[s3.label].tipo)
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				
				if(T_simbolo[s1.label].valor == T_simbolo[s3.label].valor)
				{
					adicionaTabela(temp, T_simbolo[s1.label].tipo, "true", temp);
				}
				else adicionaTabela(temp, T_simbolo[s1.label].tipo, "false", temp);
			}
			else if(T_simbolo[s1.label].tipo == "int" && T_simbolo[s3.label].tipo == "float")
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = (float)" + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				
				if(std::stof(T_simbolo[s1.label].valor) == std::stof(T_simbolo[s3.label].valor))
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else adicionaTabela(temp, "bool", "false", temp);
			}
			else if(T_simbolo[s1.label].tipo == "float" && T_simbolo[s3.label].tipo == "int")
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " (float)" + T_simbolo[s3.label].nome_temp + ";\n";
			
				if(std::stof(T_simbolo[s1.label].valor) == std::stof(T_simbolo[s3.label].valor))
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else adicionaTabela(temp, "bool", "false", temp);
			}
		}

		else if (operador == "!=")
		{
			if(T_simbolo[s1.label].valor != T_simbolo[s3.label].valor)
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "true", temp);
			}
			else 
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "false", temp);
			}
			if(T_simbolo[s1.label].tipo == "int" && T_simbolo[s3.label].tipo == "float")
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = (float)" + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				
				if(std::stof(T_simbolo[s1.label].valor) != std::stof(T_simbolo[s3.label].valor))
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else adicionaTabela(temp, "bool", "false", temp);
			}
			else if(T_simbolo[s1.label].tipo == "float" && T_simbolo[s3.label].tipo == "int")
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " (float)" + T_simbolo[s3.label].nome_temp + ";\n";
			
				if(std::stof(T_simbolo[s1.label].valor) != std::stof(T_simbolo[s3.label].valor))
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else adicionaTabela(temp, "bool", "false", temp);
			}
		}	
	}


	else if(T_simbolo[s1.label].tipo == "bool" && T_simbolo[s3.label].tipo == "bool")
	{
		if(operador == "==")
		{
			if(T_simbolo[s1.label].valor == T_simbolo[s3.label].valor)
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "true", temp);
			}
			else
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "false", temp);
			}
		}
		else if (operador == "!=")
		{
			if(T_simbolo[s1.label].valor != T_simbolo[s3.label].valor)
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "true", temp);
			}
			else
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "false", temp);
			}
		}	
	}
	return traducao;
}

string logico(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(T_simbolo[s1.label].tipo == "bool" && T_simbolo[s3.label].tipo == "bool")
	{
		if((operador == "&&" || operador == "||") && (T_simbolo[s1.label].valor == "true" && T_simbolo[s3.label].valor == "true")){
			traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
			adicionaTabela(temp, "bool", "true", temp);
		}
		else if(operador == "&&" && (T_simbolo[s1.label].valor == "false" || T_simbolo[s3.label].valor == "false")){
			traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
			adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "||"){
			if((T_simbolo[s1.label].valor == "false" && T_simbolo[s3.label].valor == "true") || (T_simbolo[s1.label].valor == "true" && T_simbolo[s3.label].valor == "false"))
			{
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "true", temp);
			}
			else if (T_simbolo[s1.label].valor == "false" && T_simbolo[s3.label].valor == "false"){
				traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[s1.label].nome_temp + " " + operador + " " + T_simbolo[s3.label].nome_temp + ";\n";
				adicionaTabela(temp, "bool", "false", temp);
			}
		}
	}

	return traducao;
}

string traducao_expressao(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/")
	{
		return aritmetica(s1, operador, s3, temp);
	}
	if(operador == "&&"|| operador == "||")
	{
		return logico(s1, operador, s3, temp);
	}
	if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=")
	{
		return relacional(s1, operador, s3, temp);
	}
	return traducao;
}

//retorna True se o símbolo está na tabela e False caso o contrario
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
		// TODO: adicionar conversão e casos de erro
	}
}

// se o simbolo não estiver na tabela retorna mensagem de erro, caso contrário retorna o tipo do simbolo  
string tipo_simbolo(string nome)
{
	if (!(testa_simbolo(nome)))
	{
		yyerror("Variável não declarada");
	}
	//cout << T_simbolo[nome].tipo << endl;
	return T_simbolo[nome].tipo;
}

string traducao_declaracao()
{
	string traducao = "";
	for(auto const& [key, val]: T_simbolo) {
		if(val.tipo=="bool")
		{
			traducao = traducao + "\t"+ "int" + " " + val.nome_temp + ";\n";
			continue;
		}
		traducao = traducao + "\t"+ val.tipo + " " + val.nome_temp + ";\n";
	}
	return traducao;
}

void imprimeTabela()
{
	cout << "\n\n\t\tTABELA DE SíMBOLOS\n\nSÍMBOLO\t\tTIPO\tATRIBUIÇÃO\tNOME\n-------------------------------------------------------------\n";
	for(auto const& [key, val]: T_simbolo) {
		cout << key << "\t\t" + val.tipo << "\t" + val.valor << "\t\t" + val.nome_temp<<"\n";
	}
	cout << "-------------------------------------------------------------\n";
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