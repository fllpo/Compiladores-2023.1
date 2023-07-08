%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <tuple>
#include <vector>

#define YYSTYPE atributos

#define COERCAO(s1, s3, e1, e3) 				\
	struct atributos e1, e3;					\
	tie(e1,e3) = coercao_tipo(s1,s3)

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
tuple<bool, int> testa_simbolo(string); // Testa se a variável está na tabela (se já foi declarada)
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
string declaracoes = "";
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
	cout << "\n" << "#include <iostream>\n#include <string.h>\n#include <stdio.h>\n\nint main(void)\n{" << declaracoes + $5.traducao << "\n\treturn 0;\n}" << endl;
};

bloco: blocofuncao '{' comandos '}'
{	
	declaracoes = declaracoes+ traducao_declaracao();
	$$.traducao = "\t\n" + $1.traducao + "\n" + $3.traducao;
	T_debug.push_back(T_simbolo[bloco_qtd]);
	bloco_qtd--;
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
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($1.label);
	if ((!teste))
	{
		string var = geraVariavelTemporaria();
		$$.traducao = $3.traducao + "\t" + var + " = " + $3.label + ";\n";
		adicionaTabela($1.label,$3.tipo, $3.valor, var);
	}
	else
	{
		$1.tipo = tipo_simbolo($1.label);
		//cout << bloc<<endl;
		if($1.tipo == $3.tipo)
		{
			$$.traducao = $3.traducao + "\t" + T_simbolo[bloc][$1.label].nome_temp; + " = " + $3.label + ";\n";
		}
		else if($3.tipo == "bool")
		{
			yyerror("Variável esperava tipo " + $1.tipo + ", mas recebeu tipo " + $3.tipo);
		}
		else if($1.tipo == "float") // Regra para coerção float
		{
			if($3.tipo == "int") // Regra para coerção int
			{
				$$.traducao = $3.traducao + "\t" + T_simbolo[bloc][$1.label].nome_temp; + " = (float) " + $3.label + ";\n";
			}
			else if($3.tipo == "char") // Regra para coerção char
			{
				yyerror("Variável esperava tipo " + $1.tipo + ", mas recebeu tipo " + $3.tipo);
			}
		}
		else if($1.tipo == "int") // Regra para coerção int
		{
			if($3.tipo == "float") // Regra para coerção float
			{
				$$.traducao = $3.traducao + "\t" + T_simbolo[bloc][$1.label].nome_temp; + " = (int) " + $3.label + ";\n";
			}
			else if($3.tipo == "char") // Regra para coerção de char
			{
				$$.traducao = $3.traducao + "\t" + T_simbolo[bloc][$1.label].nome_temp; + " = (int) " + $3.label + ";\n";
			}
		}else{
			yyerror("Variável esperava tipo " + $1.tipo + ", mas recebeu tipo " + $3.tipo);
		}
		//T_simbolo[bloc][$1.label.valor = T_simbolo[bloc][$3.label].valor;
	}
}
| IF '(' expressao ')' bloco
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	$$.traducao = $3.traducao + "\t" + neg + " = !" + $3.label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t" + $5.traducao + "\n\t" + lbl +":\n"; //Fazer gerador de label
	
	if($3.valor=="true") adicionaTabela(neg, $3.tipo, "false", neg);
	else adicionaTabela(neg, $3.tipo, "true", neg);
	
}
| IF '(' expressao ')' bloco ELSE bloco
{
	string neg = geraVariavelTemporaria();
	string lbl = geraLabel();
	string els = geraLabel();
	string saida = geraLabel();
	$$.traducao = $3.traducao + "\t" + neg + " = !" + $3.label + ";\n\n\tif(" + neg + ") " + "goto " + lbl + ";\n\n\t"+ lbl + ":" + $5.traducao + "\n\tgoto " + saida + ";" + "\n\n\t"+ els + ":" + $7.traducao + "\n\tgoto " + saida + ";" + "\n\n\t" + saida + ":" + "\n\n"; //Fazer gerador de label

	if($3.valor=="true") adicionaTabela(neg, $3.tipo, "false", neg);
	else adicionaTabela(neg, $3.tipo, "true", neg);
}
| WHILE '(' expressao ')' bloco //FIXME
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = "\n\t" + lbl +":\n\n"+ $3.traducao + "\t" + var + " = " + $3.label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";"+ $5.traducao + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n\n";
	
	adicionaTabela(var, $3.tipo, T_simbolo[bloco_qtd][$3.label].valor, var);

}
| DO bloco WHILE '(' expressao ')' ';' //FIXME
{
	string var = geraVariavelTemporaria();
	string lbl = geraLabel();
	string saida = geraLabel();
	$$.traducao = "\t" + lbl + ":" +$2.traducao + "\n" + $5.traducao + "\t" + var + " = " + $5.label + "\t" + "\n\n\tif(" + var + ") " + "goto " + saida +";" + "\n\n\tgoto " + lbl +";\n\n\t" + saida + ":\n\n";
	
	adicionaTabela(var, $5.tipo, T_simbolo[bloco_qtd][$5.label].valor, var);

}
| FOR '(' ';' expressao ';' ')' bloco //TODO
{
	//$$.traducao = $3.traducao + "\n\tfor(" + $3.label + ")" + "\n\t{\n";
}
|	TIPO_INT ID ';'
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
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
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
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
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
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
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($2.label);
	if ((!teste) || bloc != bloco_qtd)
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
	'(' TIPO_INT ')' expressao
{
	$$.valor = to_string(stoi($4.valor));

	$$.label = geraVariavelTemporaria();
	$$.traducao = $4.traducao + "\t" + $$.label + " = (int)" + $4.label + ";\n";
	adicionaTabela($$.label, "int", $$.valor, $$.label);
	$$.tipo = "int";
}
|	'(' TIPO_FLOAT ')' expressao
{
	$$.valor = to_string(stof($4.valor));

	$$.label = geraVariavelTemporaria();
	$$.traducao = $4.traducao + "\t" + $$.label + " = (float)" + $4.label + ";\n";
	adicionaTabela($$.label, "float", $$.valor, $$.label);
	$$.tipo = "float";
}
|	aritmetica
{
	$$.traducao = $1.traducao;
	$$.label = $1.label;
	$$.tipo = $1.tipo;
	$$.valor = $1.valor;
}
;

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
	adicionaTabela($$.label, $2.tipo, "N/A", $$.label);

	$$.traducao = $2.traducao + "\t" + $$.label + " = " + $2.label + ";\n";
	$$.tipo = $2.tipo;
	$$.valor = $2.valor;
}
|	SUBTRAI aritmetica
{
	$$.label = geraVariavelTemporaria();
	adicionaTabela($$.label, $2.tipo, "N/A", $$.label);

	$$.traducao = $2.traducao + "\t" + $$.label + " = " + "-" + " " + $2.label + ";\n";
	$$.tipo = $2.tipo;
	$$.valor = "-" + $2.valor;
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
	adicionaTabela($$.label, "int", $1.traducao, $$.label);
}
|	REAL
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
	$$.tipo = "float";
	$$.valor = $1.traducao;
	adicionaTabela($$.label, "float" ,$1.traducao, $$.label);
}
|	CHAR
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + $1.traducao + " ;\n";
	$$.tipo = "char";
	$$.valor = $1.traducao;
	adicionaTabela($$.label, "char" ,$1.traducao, $$.label);
}
|	STRING
{
	//Para fazer
}
| 	ID
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo($1.label);
	if (!teste)
	{
		yyerror("Variável não declarada!");
	}else
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
	adicionaTabela($$.label, "bool", "true", $$.label);
}
| 	FALSO
{
	$$.label = geraVariavelTemporaria();
	$$.traducao = "\t" + $$.label + " = " + "0" + ";\n";
	$$.tipo = "bool";
	$$.valor = "false";
	adicionaTabela($$.label, "bool", "false", $$.label);
}
|	'(' expressao ')'
{
	$$.traducao = $2.traducao;
	$$.label = $2.label;
	$$.tipo = $2.tipo;
	$$.valor = $2.valor;
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
		adicionaTabela(temp, s1.tipo, s1.valor + operador + s3.valor, temp);
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
					adicionaTabela(temp, "bool", "true", temp);
				}
				else
				{
					adicionaTabela(temp, "bool", "false", temp);
				}
			}
			else if (operador == "!=")
			{
				if(s1.valor != s3.valor)
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
	if (s1.tipo == "float" || s1.tipo == "int" || s1.tipo == "char")
	{
		if(operador == "==")
		{
			if(s1.valor == s3.valor)
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}

		else if (operador == "!=")
		{
			if(s1.valor != s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">")
		{
			if(s1.valor > s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<")
		{
			if(s1.valor < s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "<=")
		{
			if(s1.valor <= s3.valor)
			{	
				adicionaTabela(temp, "bool", "true", temp);
			}
			else adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == ">=")
		{
			if(s1.valor >= s3.valor)
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
	string traducao = s1.traducao + s3.traducao + "\t" + temp + " = " + s1.label + " " + operador + " " + s3.label + ";\n";

	if(s1.tipo == "bool")
	{
		if((operador == "&&" || operador == "||") && (s1.valor == "true" && s3.valor == "true")){
			adicionaTabela(temp, "bool", "true", temp);
		}
		else if(operador == "&&" && (s1.valor == "false" || s3.valor == "false")){

			adicionaTabela(temp, "bool", "false", temp);
		}
		else if(operador == "||"){
			if((s1.valor == "false" && s3.valor == "true") || (s1.valor == "true" && s3.valor == "false"))
			{
				adicionaTabela(temp, "bool", "true", temp);
			}
			else if (s1.valor == "false" && s3.valor == "false"){
				adicionaTabela(temp, "bool", "false", temp);
			}
		}else
		{
			traducao = s1.traducao + "\t" + temp + " = " + operador + " " + s1.label + ";\n";
			if(s3.valor == "true")
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

	if(operador == "+"|| operador == "-" || operador == "*" || operador == "/")
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
			adicionaTabela(novo.label, "float", to_string(stof(s3.valor)), novo.label);
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
			adicionaTabela(novo.label, "float", to_string(stof(s1.valor)), novo.label);
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
			adicionaTabela(novo.label, "int", (s3.valor), novo.label);
			get<1>(expr) = novo;
		}
	}else if(tipo3 == "int") // Regra para coerção int
	{
		if(tipo1 == "char") // Regra para coerção char
		{
			novo.traducao = s1.traducao + + "\t" + novo.label + " = (int)" + s1.label + ";\n";;
			adicionaTabela(novo.label, "int", (s3.valor), novo.label);
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

void adicionaTabela(string nome, string tipo, string valor, string novo_nome)
{
	bool teste;
	int bloc;
	tie(teste, bloc) = testa_simbolo(nome);
	if (!teste)
	{
		simbolo novo;
		novo.tipo = tipo;
		novo.nome_temp = novo_nome;
		novo.valor = valor;
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