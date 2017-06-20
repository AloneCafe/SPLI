all:
	bison -d spli.y
	flex spli.l
	gcc -o spli lex.yy.c spli.tab.c spli.c prop.c -lfl

clean:
	rm -f lex.yy.c spli.tab.c spli.tab.h spli
