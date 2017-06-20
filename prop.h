#ifndef _PROP_TABLE_H_
#define _PROP_TABLE_H_

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

//数据大小的相关宏
#define PROP_MAX_SIZE 32
#define PROP_NAME_SIZE  32
#define PROP_INDEX_SIZE 32

typedef struct PropTable
{
    //命题名字
    char name[PROP_NAME_SIZE];
    //索引列表
    uint16_t index[PROP_INDEX_SIZE];
    //索引标记（定位列表位置）
    uint16_t ip;
    //命题真值
    _Bool val;
}PropTable;


typedef struct ResultTable
{
    //命题真值枚举序列
    _Bool val[PROP_MAX_SIZE];
    //表达式真值结果
    _Bool result;
}ResultTable;

//全局命题表
PropTable *P;

//全局真值表
ResultTable *T;

//全局当前命题数，结果数
uint16_t prop_num;
uint16_t result_num;

//命题是否已全部添加到表中（flag值）
_Bool has_added;


//函数声明
PropTable *create_prop_table(uint16_t size);
ResultTable *create_result_table(uint16_t size);
void add_prop_element(char name[PROP_NAME_SIZE]);
void add_result_element(_Bool result);
_Bool get_prop_val(char name[PROP_NAME_SIZE]);
uint64_t pow2(int num);
void step_prop_val();
void debug_print();
void print_table_title(char *result_text);
void print_table_body(int result_index);

#endif
