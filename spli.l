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
	if(!has_added)
	{
		add_prop_element(yytext);
	}
	else
	{
		//得到命题的真值，传递给yylval
		yylval = get_prop_val(yytext);

		//判断是否有相同命题元素，若否则打印元素真值
		if(has_same_prop_element(yytext))
		{
			//如果命题状态处于UNUSED，则打印元素真值，并将命题状态置为USED，表示已输出过该命题的真值
			if(get_prop_status(yytext) == UNUSED)
			{
				printf("\t%d", yylval);
				set_prop_status(yytext, USED);
			}
		}
		else
		{
			printf("\t%d", yylval);	
		}
			
	}
	
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
	exit(1);
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
