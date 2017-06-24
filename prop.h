#ifndef _PROP_H_
#define _PROP_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

//数据大小的相关宏（命题最大长度、命题名大小）Def=512
#define PROP_MAX_SIZE   512
#define PROP_NAME_SIZE  512

//命题逻辑表达式大小常量宏 Def=4096
#define EXPR_MAX_SIZE   4096

//命题表数据结构
typedef struct PropTable
{
    //命题名字
    char name[PROP_NAME_SIZE];
    //命题真值
    _Bool val;
}PropTable;

//全局命题表
PropTable *P;

//命题逻辑表达式
char expr[EXPR_MAX_SIZE];

//全局当前命题数
uint32_t prop_num;

//命题是否已全部添加到表中（flag值）
_Bool has_added;


//函数声明
PropTable *create_prop_table(uint32_t size);
void add_prop_element(char name[PROP_NAME_SIZE]);
_Bool get_prop_val(char name[PROP_NAME_SIZE]);
uint64_t pow2(uint32_t num);
_Bool step_prop_val();
void print_table_title(char *result_text);

#endif
