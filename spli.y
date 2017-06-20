%{
#include "spli.h"
%}


%token	VAL_TRUE VAL_FALSE
%token	OP CP
%token	OPR_NOT OPR_AND OPR_OR OPR_IM OPR_EQ
%token	P Q R S T
%token	EOL

%%



list: 
    | list exp {printf("%d\n",$2);}
    ;


exp: factor3	{$$ = $1;}
   | exp OPR_EQ factor3	{$$ = EQ($1, $3);}
   ;

factor3: factor2	{$$ = $1;}
       | factor3 OPR_IM factor2	{$$ = IM($1, $3);}
       ;

factor2: factor1	{$$ = $1;}
       | factor2 OPR_OR factor1	{$$ = OR($1, $3);}
       ;

factor1: term	{$$ = $1;}
       | factor1 OPR_AND term	{$$ = AND($1, $3);}
       ;

term: VAL_TRUE	{$$ = 1;}
	| VAL_FALSE	{$$ = 0;}
	| OPR_NOT term	{$$ = $2 == 1 ? 0 : 1;}
	| OP exp CP	{$$ = $2;}
	;

%%

