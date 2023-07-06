%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include <vector>

#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label;
	string traducao;
	string tipo;
};

struct simbolo
{
	string nome_temp;
	string tipo;
	string token;
	string valor;
	string escopo;
};

int yylex(void);
void yyerror(string);

string geraVariavelTemporaria(); // Gera um nome de variável temporária
string geraLabel();
string trad_aritmetica(struct atributos, string, struct atributos, string);
string trad_relacional(struct atributos, string, struct atributos, string);
string trad_if(struct atributos, string, struct atributos, string);
string trad_logico(struct atributos, string, struct atributos, string);
string traducao_expressao(struct atributos, string, struct atributos, string); // Função que retorna a tradução de uma expressao (aritmetica(float - int))
void adicionaTabela(string, string, string, string); // adiciona um símbolo na tabela, com seu tipo, valor e nome_temp
tuple<struct atributos, struct atributos> coercao_tipo(struct atributos, struct atributos);
bool testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
string tipo_simbolo(string); // Retorna o tipo do símbolo caso esse esteja na tabela
string traducao_declaracao(); // Retorna a tradução de todas as declarações do código intermediário, no topo de seu bloco_qtd
void imprimeTabela(); // Imprime a tabela de símbolos

vector<map<string, simbolo>> T_simbolo; // Mapa, identificado pelo nome da variável
vector<map<string, simbolo>> T_debug;

int tmp_qnt = 0;
int num_linha = 1;
int bloco_qtd = -1;
int bloco_qtd_debug = -1;
int label_qnt=0;

%}

%token MAIN ID NUM REAL CHAR STRING FIM ERROR
%token TIPO_INT TIPO_FLOAT TIPO_CHAR TIPO_BOOL TIPO_STRING
%token ATRIBUI SOMA SUBTRAI MULTIPLICA DIVIDE 
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE E_LOGICO OU_LOGICO VERDADEIRO FALSO NEGAR
%token IF ELSE WHILE DO FOR

%start S

%left SOMA SUBTRAI
%right MULTIPLICA DIVIDE
%right '('')' E_LOGICO OU_LOGICO

%%

S: TIPO_INT MAIN '(' ')' bloco
{
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{" << $5.traducao << "\n\treturn 0;\n}" << endl;
};

bloco: blocofuncao '{' comandos '}'
{	
	$$.traducao = "\t\n" + $1.traducao + traducao_declaracao() + "\n" + $3.traducao;
	bloco_qtd--;
	T_debug.push_back(T_simbolo[bloco_qtd+1]);
	T_simbolo.pop_back();
};

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
	$$.traducao = $1.traducao + "\t}\n";
}
|	expressao ';'
{
	$$.traducao = "";
}
|	ID ATRIBUI expressao ';'
{
	if(!(testa_simbolo($1.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = $3.traducao + "\t" + var + " = " + T_simbolo[bloco_qtd][$3.label].nome_temp + ";\n";
		adicionaTabela($1.label, T_simbolo[bloco_qtd][$3.label].tipo, T_simbolo[bloco_qtd][$3.label].valor, var); 
	}
	else
	{
		if(T_simbolo[bloco_qtd][$1.label].tipo == T_simbolo[bloco_qtd][$3.label].tipo)
		{
			$$.traducao = $3.traducao + "\t" + T_simbolo[bloco_qtd][$1.label].nome_temp + " = " + T_simbolo[bloco_qtd][$3.label].nome_temp + ";\n";
		}
		else if(T_simbolo[bloco_qtd][$3.label].tipo == "bool")
		{
			yyerror("Variável esperava tipo " + T_simbolo[bloco_qtd][$1.label].tipo + ", mas recebeu tipo " + T_simbolo[bloco_qtd][$3.label].tipo);
		}
		else if(T_simbolo[bloco_qtd][$1.label].tipo == "float") // Regra para coerção float
		{
			if(T_simbolo[bloco_qtd][$3.label].tipo == "int") // Regra para coerção int
			{
				$$.traducao = $3.traducao + "\t" + T_simbolo[bloco_qtd][$1.label].nome_temp + " = (float) " + T_simbolo[bloco_qtd][$3.label].nome_temp + ";\n";
			}
			else if(T_simbolo[bloco_qtd][$3.label].tipo == "char") // Regra para coerção char
			{
				yyerror("Variável esperava tipo " + T_simbolo[bloco_qtd][$1.label].tipo + ", mas recebeu tipo " + T_simbolo[bloco_qtd][$3.label].tipo);
			}
		}
		else if(T_simbolo[bloco_qtd][$1.label].tipo == "int") // Regra para coerção int
		{
			if(T_simbolo[bloco_qtd][$3.label].tipo == "float") // Regra para coerção float
			{
				$$.traducao = $3.traducao + "\t" + T_simbolo[bloco_qtd][$1.label].nome_temp + " = (int) " + T_simbolo[bloco_qtd][$3.label].nome_temp + ";\n";
			}
			else if(T_simbolo[bloco_qtd][$3.label].tipo == "char") // Regra para coerção de char
			{
				$$.traducao = $3.traducao + "\t" + T_simbolo[bloco_qtd][$1.label].nome_temp + " = (int) " + T_simbolo[bloco_qtd][$3.label].nome_temp + ";\n";
			}
		}else{
			yyerror("Variável esperava tipo " + T_simbolo[bloco_qtd][$1.label].tipo + ", mas recebeu tipo " + T_simbolo[bloco_qtd][$3.label].tipo);
		}
		T_simbolo[bloco_qtd][$1.label].valor = T_simbolo[bloco_qtd][$3.label].valor;
	}
}
| IF '(' expressao ')' bloco
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = $3.traducao + "\t" + neg + " = !" + $3.label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + "; else goto "+saida+";\n\n\t" + lbl + ":" + $5.traducao + "\n\t" + saida +":\n"; //Fazer gerador de label
	
	if(T_simbolo[bloco_qtd][$3.label].valor=="true"){
		adicionaTabela(neg, T_simbolo[bloco_qtd][$3.label].tipo, "false", neg);
	}
	else adicionaTabela(neg, T_simbolo[bloco_qtd][$3.label].tipo, "true", neg);
	
}
| IF '(' expressao ')' bloco ELSE bloco //TODO
{
	$$.traducao = "";
}
| WHILE '(' expressao ')' bloco //TODO
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	$$.traducao = $3.traducao + "\t" + neg + " = !" + $3.label + "\n\n\t" + lbl + ":\n\n\tif(" + neg + ") " + "goto " + lbl +";"+ $5.traducao + "\n\tgoto" + lbl +" label de loop\n\tLabel gerada:" + "\n";
}
| DO bloco WHILE '(' expressao ')' bloco //TODO
{
	$$.traducao = "";
}
| FOR '(' ';' expressao ';' ')' bloco //TODO
{
	$$.traducao = $3.traducao + "\n\tfor(" + $3.label + ")" + "\n\t{\n";
}
|	TIPO_INT ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "";
		adicionaTabela($2.label, "int", "N/A", var);
		
	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO_FLOAT ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "";
		adicionaTabela($2.label, "float", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO_BOOL ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "";
		adicionaTabela($2.label, "bool", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
|	TIPO_CHAR ID ';'
{
	if (!(testa_simbolo($2.label)))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = "";
		adicionaTabela($2.label, "char", "N/A", var);
	}else{
		yyerror("Variável já declarada!");
	}
}
;

expressao:
// 	Operadores lógicos
	expressao E_LOGICO relacao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "&&", $3, $$.label);
}
|	expressao OU_LOGICO relacao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "||", $3, $$.label);
}
|	relacao
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
};
relacao:
//	Operadores relacionais
	aritmetica IGUAL aritmetica
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "==", $3, $$.label);
}
|	aritmetica DIFERENTE aritmetica
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "!=", $3, $$.label);
}
//	Operadores relacionais
|	aritmetica MAIOR aritmetica
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, ">", $3, $$.label);
}
|	aritmetica MENOR aritmetica
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "<", $3, $$.label);
}
|	aritmetica MAIOR_IGUAL aritmetica
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, ">=", $3, $$.label);
}
|	aritmetica MENOR_IGUAL aritmetica
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($1, "<=", $3, $$.label);
}
|	NEGAR relacao
{
	$$.label = geraVariavelTemporaria();
	
	$$.traducao = traducao_expressao($2, "!", $2, $$.label);
}
|	converte
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
};
converte:
// Conversão explicita
	'(' TIPO_INT ')' expressao
{
	string conversao = to_string(stoi(T_simbolo[bloco_qtd][$4.label].valor));

	$$.label = geraVariavelTemporaria();
	$$.traducao = $4.traducao + "\t" + $$.label + " = (int)" + $4.label + ";\n";
	adicionaTabela($$.label, "int", conversao, $$.label);
}
|	'(' TIPO_FLOAT ')' expressao
{
	string conversao = to_string(stof(T_simbolo[bloco_qtd][$4.label].valor));

	$$.label = geraVariavelTemporaria();
	$$.traducao = $4.traducao + "\t" + $$.label + " = (float)" + $4.label + ";\n";
	adicionaTabela($$.label, "float", conversao, $$.label);
}
|	aritmetica
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
}
;

aritmetica:
// 	Operadores matemáticos
	fator
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
}
|	aritmetica SOMA aritmetica
{
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "+", $3, $$.label);
}
|	aritmetica SUBTRAI aritmetica
{
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "-", $3, $$.label);
}
|	aritmetica MULTIPLICA aritmetica
{
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "*", $3, $$.label);
}
| 	aritmetica DIVIDE aritmetica
{
	if(stof(T_simbolo[bloco_qtd][$3.label].valor)==0) yyerror("Divisão por zero");
	
	$$.label = geraVariavelTemporaria();

	$$.traducao = traducao_expressao($1, "/", $3, $$.label);
}
|	SOMA aritmetica
{
	$$.label = geraVariavelTemporaria();
	adicionaTabela($$.label, tipo_simbolo($2.label), "N/A", $$.label);

	$$.traducao = $2.traducao + "\t" + $$.label + " = " + T_simbolo[bloco_qtd][$2.label].nome_temp + ";\n";
}
|	SUBTRAI aritmetica
{
	$$.label = geraVariavelTemporaria();
	adicionaTabela($$.label, tipo_simbolo($2.label), "N/A", $$.label);

	$$.traducao = $2.traducao + "\t" + $$.label + " = " + "-" + " " + T_simbolo[bloco_qtd][$2.label].nome_temp + ";\n";
}
;
fator:

// Simbolos terminais
	NUM
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
|	CHAR
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + " ;\n";
	adicionaTabela($$.label, "char" ,$1.traducao, $$.label);
}
|	STRING
{
	//Para fazer
}
| 	ID
{
	if(!(testa_simbolo($1.label)))
	{
		yyerror("Variável não declarada!");
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
}
|	'(' expressao ')'
{
	$$.traducao = $2.traducao;
	$$.label = $2.label;
};

%%

#include "lex.yy.c"

int yyparse();

string geraVariavelTemporaria()
{
	return "TMP_" + to_string(tmp_qnt++);
}

string geraLabel()
{
	return "L" + to_string(label_qnt++);
}

string trad_aritmetica(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = "";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		yyerror("Tipo bool não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if(T_simbolo[bloco_qtd][s1.label].tipo == "char")
	{
		yyerror("Tipo char não suporta operações aritméticas ( + - * / )"); // termina a função
	}

	if((T_simbolo[bloco_qtd][s1.label].tipo == "float" || T_simbolo[bloco_qtd][s1.label].tipo == "int"))
	{
		traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + " " + operador + " " + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n";
		adicionaTabela(temp, T_simbolo[bloco_qtd][s1.label].tipo, T_simbolo[bloco_qtd][s1.label].valor + operador + T_simbolo[bloco_qtd][s3.label].valor, temp);
	}

	return traducao;
}

string trad_relacional(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + " " + operador + " " + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		if (operador == "<" || operador == ">" || operador == "<=" || operador == ">=")
		{
			yyerror("Tipo não suporta operações relacionais (<, >, >=, <=)"); // termina a função
		}
		else
		{
			if(operador == "==")
			{
				if(T_simbolo[bloco_qtd][s1.label].valor == T_simbolo[bloco_qtd][s3.label].valor)
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp);
				}
			}
			else if (operador == "!=")
			{
				if(T_simbolo[bloco_qtd][s1.label].valor != T_simbolo[bloco_qtd][s3.label].valor)
				{
					adicionaTabela(temp, "bool", "true", temp);
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp);
				}
			}	
		}

	}
	
// tipos numéricos e char
	if (T_simbolo[bloco_qtd][s1.label].tipo == "float" || T_simbolo[bloco_qtd][s1.label].tipo == "int" || T_simbolo[bloco_qtd][s1.label].tipo == "char")
	{
		if(operador == "==")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor == T_simbolo[bloco_qtd][s3.label].valor)
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}

		else if (operador == "!=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor != T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor > T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor < T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor <= T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">=")
		{
			if(T_simbolo[bloco_qtd][s1.label].valor >= T_simbolo[bloco_qtd][s3.label].valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
	}

	return traducao;
}

string trad_logico(struct atributos s1, string operador, struct atributos s3, string temp)
{
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + T_simbolo[bloco_qtd][s1.label].nome_temp + " " + operador + " " + T_simbolo[bloco_qtd][s3.label].nome_temp + ";\n";

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool")
	{
		if((operador == "&&" || operador == "||") && (T_simbolo[bloco_qtd][s1.label].valor == "true" && T_simbolo[bloco_qtd][s3.label].valor == "true")){
			adicionaTabela(temp, "bool", "true", temp);
		}
		else if(operador == "&&" && (T_simbolo[bloco_qtd][s1.label].valor == "false" || T_simbolo[bloco_qtd][s3.label].valor == "false")){

			adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "||"){
			if((T_simbolo[bloco_qtd][s1.label].valor == "false" && T_simbolo[bloco_qtd][s3.label].valor == "true") || (T_simbolo[bloco_qtd][s1.label].valor == "true" && T_simbolo[bloco_qtd][s3.label].valor == "false"))
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else if (T_simbolo[bloco_qtd][s1.label].valor == "false" && T_simbolo[bloco_qtd][s3.label].valor == "false"){
				adicionaTabela(temp, "bool", "false", temp);
			}
		}else
		{
			traducao = s1.traducao + "\t" + temp + " = " + operador + " " + T_simbolo[bloco_qtd][s1.label].nome_temp + ";\n";
			if(T_simbolo[bloco_qtd][s3.label].valor == "true")
			{
				adicionaTabela(temp, "bool", "false", temp);
			}
			else 
			{
				adicionaTabela(temp, "bool", "true", temp);
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
	struct atributos e1, e3;
	tie(e1,e3) = coercao_tipo(s1,s3);

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/")
	{
		return trad_aritmetica(e1, operador, e3, temp);
	}
	if(operador == "&&"|| operador == "||" || operador == "!")
	{
		return trad_logico(e1, operador, e3, temp);
	}
	if(operador == ">" || operador == "<" || operador == ">=" || operador == "<=" || operador == "==" || operador == "!=")
	{
		return trad_relacional(e1, operador, e3, temp);
	}
	return traducao;
}

tuple<struct atributos, struct atributos> coercao_tipo(struct atributos s1, struct atributos s3)
{
	tuple <struct atributos, struct atributos> expr(s1,s3);
	if(T_simbolo[bloco_qtd][s1.label].tipo == T_simbolo[bloco_qtd][s3.label].tipo)
		return expr;

	if(T_simbolo[bloco_qtd][s1.label].tipo == "bool" || T_simbolo[bloco_qtd][s3.label].tipo == "bool")
		yyerror("Tipo booleano não suporta coerção");
	
	struct atributos novo;
	novo.traducao = "";
	novo.label = geraVariavelTemporaria();
	
	if(T_simbolo[bloco_qtd][s1.label].tipo == "float") // Regra para coerção float
	{
		if(T_simbolo[bloco_qtd][s3.label].tipo == "int") // Regra para coerção int
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (float)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(T_simbolo[bloco_qtd][s3.label].valor)), novo.label);
			get<1>(expr) = novo;
		}
		else if(T_simbolo[bloco_qtd][s3.label].tipo == "char") // Regra para coerção char
		{
			yyerror("Expressão não definida para os tipos float e char");
		}
	}
	else if(T_simbolo[bloco_qtd][s3.label].tipo == "float") // Regra para coerção float
	{
		if(T_simbolo[bloco_qtd][s1.label].tipo == "int") // Regra para coerção int
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (float)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "float", to_string(stof(T_simbolo[bloco_qtd][s1.label].valor)), novo.label);
			get<0>(expr) = novo;
		}
		else if(T_simbolo[bloco_qtd][s1.label].tipo == "char") // Regra para coerção de char
		{
			yyerror("Expressão não definida para os tipos char e float");
		}
	}
	else if(T_simbolo[bloco_qtd][s1.label].tipo == "int") // Regra para coerção int
	{
		if(T_simbolo[bloco_qtd][s3.label].tipo == "char") // Regra para coerção char
		{
			novo.traducao = s3.traducao + + "\t" + novo.label + " = (int)" + s3.label + ";\n";;
			adicionaTabela(novo.label, "int", (T_simbolo[bloco_qtd][s3.label].valor), novo.label);
			get<1>(expr) = novo;
		}
	}else if(T_simbolo[bloco_qtd][s3.label].tipo == "int") // Regra para coerção int
	{
		if(T_simbolo[bloco_qtd][s1.label].tipo == "char") // Regra para coerção char
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (int)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "int", (T_simbolo[bloco_qtd][s3.label].valor), novo.label);
			get<0>(expr) = novo;
		}
	}

	return expr;
}

//retorna True se o símbolo está na tabela e False caso o contrario
bool testa_simbolo(string nome)
{
	for(int i=bloco_qtd;i>=0;i--)
		return T_simbolo[bloco_qtd].count(nome)==1;
	return false;
}

void adicionaTabela(string nome, string tipo, string valor, string novo_nome)
{
	if (!(testa_simbolo(nome)))
	{
		simbolo novo;
		novo.tipo = tipo;
		novo.nome_temp = novo_nome;
		novo.valor = valor;
		T_simbolo[bloco_qtd][nome] = novo;
		
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
	return T_simbolo[bloco_qtd][nome].tipo;
}

string traducao_declaracao()
{
	string traducao = "";
	for(auto const& [key, val]: T_simbolo[bloco_qtd]) {
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
	for (int i = 0; i <= bloco_qtd_debug; i++)
	{
		cout << "\n\n\t\tTABELA DE SíMBOLOS | BLOCO " << i <<"\n\nSÍMBOLO\t\tTIPO\tATRIBUIÇÃO\tNOME\n-------------------------------------------------------------\n";
		for(auto const& [key, val]: T_debug[i]) {
			cout << key << "\t\t" + val.tipo << "\t" + val.valor << "\t\t" + val.nome_temp<<"\n";
		}
		cout << "-------------------------------------------------------------\n";
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