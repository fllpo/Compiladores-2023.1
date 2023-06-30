all:	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -std=c++17
	  	./glf < programa.lingua
