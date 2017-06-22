%{
	#include "spli.tab.h"
	#include "prop.h"
%}

%%

"("	{
	return OP;
}

")"	{
	return CP;
}
"!"	{
	return OPR_NOT;
}

"&"	{
	return OPR_AND;
}

"|"	{
	return OPR_OR;
}

"->"	{
	return OPR_IM;
}

"<->"	{
	return OPR_EQ;
}

[A-Za-z_]+[A-Za-z_0-9]*	{
	
	//如果是第一次parsing，添加命题到命题表
	if(has_added == 0)
	{
		add_prop_element(yytext);
	}
	
	//得到命题的真值，传递给yylval
	yylval = get_prop_val(yytext);
	
	return VAL;
}

1	{
	yylval = 1;
	return VAL;
}

0	{
	yylval = 0;
	return VAL;
}

[ \t]	{

}

.	{
	fprintf(stderr, "Illegal character: %s\n", yytext);
}

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
