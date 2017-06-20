%{
	#include "spli.tab.h"
	#include "prop.h"
%}

%%

"("	{return OP;}
")"	{return CP;}
(N|n)(O|o)(T|t)	{return OPR_NOT;}
(A|a)(N|n)(D|d)	{return OPR_AND;}
(O|o)(R|r)	{return OPR_OR;}
"->"	{return OPR_IM;}
"<->"	{return OPR_EQ;}
[A-Za-z_]+[A-Za-z_0-9]*	{
	if(has_added == 0)
	{
		add_prop_element(yytext);
	}
	
	yylval = get_prop_val(yytext);
	
	return PROP;
}
1	{yylval = 1; return VAL_TRUE;}
0	{yylval = 0; return VAL_FALSE;}
\n	{return EOL;}
[ \t]	{}
.	{fprintf(stderr, "Illegal character: %c\n", *yytext);}

%%

//重写yyerror函数
void yyerror(char *s)
{
	fprintf(stderr, "Error: %s\n", s);
	exit(1);
}

//重写yywrap函数，使之返回-1
int yywrap()
{
	return -1;
}
