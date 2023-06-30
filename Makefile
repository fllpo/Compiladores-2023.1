all:	
		clear
		lex lexica.l
<<<<<<< HEAD
		yacc -d sintatica.y -Wcounterexamples
		g++ -o glf y.tab.c -ll
	  	./glf < programa.lingua
=======
		yacc -d sintatica.y
		g++ -o glf y.tab.c -ll -std=c++17
	  	./glf < programa.lingua
>>>>>>> 3500ee7 (sla)
