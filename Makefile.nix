CC = gcc
FLEX = flex
BISON = bison
RM = rm -f
TARGETS := spli

all: $(TARGETS)

$(TARGETS):
	$(BISON) -d spli.y
	$(FLEX) spli.l
	$(CC) -o bin/spli lex.yy.c spli.tab.c spli.c prop.c

debug:
	$(BISON) -d spli.y
	$(FLEX) -d spli.l
	$(CC) -o bin/spli lex.yy.c spli.tab.c spli.c prop.c
	
clean:
	$(RM) lex.yy.c spli.tab.c spli.tab.h bin/spli
