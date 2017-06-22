#ifndef _PROP_H_
#define _PROP_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

//数据大小的相关宏（命题最大数量、命题名大小，命题索引大小）Def=128
#define PROP_MAX_SIZE   128
#define PROP_NAME_SIZE  128
#define PROP_INDEX_SIZE 128

//命题逻辑表达式大小常量宏 Def=2048
#define EXPR_MAX_SIZE   2048

//命题表数据结构
typedef struct PropTable
{
    //命题名字
    char name[PROP_NAME_SIZE];
    //索引列表
    uint32_t index[PROP_INDEX_SIZE];
    //索引标记（定位列表位置）
    uint32_t ip;
    //命题真值
    int32_t val;
}PropTable;

//真值表数据结构
typedef struct TruthTable
{
    //命题真值枚举序列
    int32_t val[PROP_MAX_SIZE];
    //表达式真值结果
    int32_t result;
}TruthTable;

//全局命题表
PropTable *P;

//全局真值表
TruthTable *T;

//命题逻辑表达式
char expr[EXPR_MAX_SIZE];

//全局当前命题数，真值结果数
uint32_t prop_num;
uint32_t result_num;

//命题是否已全部添加到表中（flag值）
int32_t has_added;


//函数声明
PropTable *create_prop_table(uint32_t size);
TruthTable *create_truth_table(uint32_t size);
void add_prop_element(char name[PROP_NAME_SIZE]);
void add_truth_element(int32_t result);
int32_t get_prop_val(char name[PROP_NAME_SIZE]);
uint64_t pow2(uint32_t num);
void step_prop_val();
void debug_print();
void print_table_title(char *result_text);
void print_table_body();

#endif
