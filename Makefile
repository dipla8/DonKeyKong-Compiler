all:
	flex dkk_lexer.l
	gcc lex.yy.c -o lexer
