%{
    #include "spli.h"
    #include "prop.h"
%}

//token定义列表
%token OP CP
%token VAL

%left OPR_EQ
%left OPR_IM
%left OPR_OR
%left OPR_AND
%nonassoc	OPR_NOT

%%

list: exp {
        add_truth_element($1);
    }
    ;

exp: exp OPR_EQ exp { $$ = EQ($1, $3); }
   | exp OPR_IM exp { $$ = IM($1, $3); }
   | exp OPR_OR exp { $$ = OR($1, $3); }
   | exp OPR_AND exp { $$ = AND($1, $3); }
   | OPR_NOT exp { $$ = NOT($2); }
   | OP exp CP { $$ = $2; }
   | VAL { $$ = $1; }


%%

