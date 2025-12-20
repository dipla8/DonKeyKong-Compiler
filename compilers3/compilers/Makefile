all:
	bison -v -d dkk.y
	flex dkk_lexer.l
	gcc dkk.tab.c lex.yy.c hashtbl.c -o xovl
