all:	
		clear
		lex lexica.l
		yacc -d sintatica.y -Wcounterexamples
		g++ -o glf y.tab.c -ll
	  	./glf < programa.lingua
