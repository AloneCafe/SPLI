#ifndef _SPLI_H_
#define _SPLI_H_

/*
命题逻辑计算宏：
EQ(a, b)：a等价b
IM(a, b)：a蕴含b
OR(a, b)：a析取b
AND(a, b)：a合取b
NOT(a)：对a取反
*/
#define EQ(a, b)	a == b
#define IM(a, b)	!(a && !(b))
#define OR(a, b)	a || b
#define AND(a, b)	a == b == 1
#define NOT(a)      !(a)

//词法分析器缓冲区类型
typedef struct yy_buffer_state *YY_BUFFER_STATE;

//flex & bison 库函数声明
int yylex();
int yyparse();
void yyerror(char *s);
int yywrap();
YY_BUFFER_STATE yy_scan_string(char *);
int yy_flush_buffer(YY_BUFFER_STATE);
int yy_delete_buffer(YY_BUFFER_STATE);
int yy_switch_to_buffer(void *);



#endif
