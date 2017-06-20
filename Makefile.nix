all:
	bison -d splic.y
	flex splic.l
	gcc -o splic lex.yy.c splic.tab.c splic.c -lfl

clean:
	rm -f lex.yy.c splic.tab.c splic.tab.h splic
