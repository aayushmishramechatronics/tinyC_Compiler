a.out: lex.yy.o y.tab.o compiler_translator.o compiler_target_translator.o
	g++ lex.yy.o y.tab.o compiler_translator.o compiler_target_translator.o -lfl

compiler_target_translator.o: compiler_target_translator.cxx compiler_translator.h
	g++ -c -g compiler_target_translator.cxx
compiler_translator.o: compiler_translator.h compiler_translator.cxx
	g++ -c -g compiler_translator.cxx
lex.yy.o: 	lex.yy.c
	g++ -c -g lex.yy.c
y.tab.o: 	y.tab.c
	g++ -c -g y.tab.c
lex.yy.c: 	compiler_lexer.l y.tab.h compiler_translator.h
	flex compiler_lexer.l
y.tab.c: 	compiler_rules_actions.y
	yacc -dtv compiler_rules_actions.y
y.tab.h: 	compiler_rules_actions.y compiler_translator.h
	yacc -dtv compiler_rules_actions.y

clean:
	rm lex.yy.c y.tab.h y.tab.c lex.yy.o y.tab.o a.out y.output compiler_translator.o compiler_target_translator.o