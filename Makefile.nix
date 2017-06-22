CC = gcc
FLEX = flex
BISON = bison
RM = rm -f
TARGETS := spli

all: $(TARGETS)

$(TARGETS):
	$(BISON) -d spli.y
	$(FLEX) -i spli.l
	$(CC) -o bin/spli lex.yy.c spli.tab.c spli.c prop.c -lfl

debug:
	$(BISON) -d spli.y
	$(FLEX) -d -i spli.l
	$(CC) -o bin/spli lex.yy.c spli.tab.c spli.c prop.c -lfl
	
clean:
	$(RM) lex.yy.c spli.tab.c spli.tab.h bin/spli
