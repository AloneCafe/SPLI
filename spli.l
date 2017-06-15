%{
	#include "spli.tab.h"
%}


%%
"("	{return OP;}
")"	{return CP;}
"¬"	{return OPR_NOT;}
"∧"	{return OPR_AND;}
"∨"	{return OPR_OR;}
"→"	{return OPR_IM;}
"↔"	{return OPR_EQ;}
"p"	{return P;}
"q"	{return Q;}
"r"	{return R;}
"s"	{return S;}
"t"	{return T;}
1	{yylval = 1; return VAL_TRUE;}
0	{yylval = 0; return VAL_FALSE;}
\n	{return EOL;}
[ \t]	{}
.	{printf("Illegal character: %c\n", *yytext);}

%%

void yyerror(char *s)
{
	fprintf(stderr, "Error: %s\n", s);
}

int yywrap()
{
	return -1;
}
