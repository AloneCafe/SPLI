#include "prop.h"

//创建/初始化命题表，返回对应的指针
PropTable *create_prop_table(uint16_t size)
{
    int i;
    //内存分配
	PropTable *p = (PropTable *)malloc(sizeof(PropTable) * size);
    //依次初始化每个元素的索引标记和初始真值
    for(i = 0; i < size; i++)
    {
        p[i].ip = 0;
        p[i].val = 1;
    }
    //初始化命题数（置0）
    prop_num = 0;
	return p;
}

//创建/初始化结果表，返回对应的指针
ResultTable *create_result_table(uint16_t size)
{
    int i;
    //内存分配
	ResultTable *p = (ResultTable *)malloc(sizeof(ResultTable) * size);
    //依次初始化每个结果元素的初始真值
    for(i = 0; i < size; i++)
    {
        p[i].result = 0;
    }
    //初始化结果数（置0）
    result_num = 0;
	return p;
}

void add_prop_element(char name[PROP_NAME_SIZE])
{
    int i;
    
    //检测是否有命题名字重复，重复则把当前命题的序数加到对应的索引列表中
    for(i = 0; i < prop_num; i++)
    {
        if(strcmp(P[i].name, name) == 0)
        {
            P[i].index[P[i].ip++] = prop_num;
            return;
        }
    }

    //若不重复，则添加到新索引中
    strcpy(P[prop_num].name, name);
    P[prop_num].index[P[prop_num].ip++] = prop_num;
    //命题个数+1
    prop_num++;
    
}

//添加真值运算结果到结果表
void add_result_element(_Bool result)
{
    //结果个数+1
    T[result_num++].result = result;
}

//打印真值表标题，result_text指结果列头部的标题文本
void print_table_title(char *result_text)
{
    int i;
    for(i = 0; i < prop_num; i++)
    {
        printf("\t%s", P[i].name);
    }
    printf("\t|\t%s\n", result_text);
}

//打印真值表身，result_index指打印的结果表中元素的位置
void print_table_body(int result_index)
{
    int i;
    for(i = 0; i < prop_num; i++)
    {
        printf("\t%d", P[i].val);
    }
    printf("\t|\t%d\n", T[result_index].result);
}

//从命题表指定名字的元素中得到真值，参数是命题元素的名字
_Bool get_prop_val(char name[PROP_NAME_SIZE])
{
    int i;
    for(i = 0; i < prop_num; i++)
    {
        if(strcmp(P[i].name, name) == 0)
        {
            return P[i].val;
        }
    }

}

//自编的pow(2, n)运算函数
uint64_t pow2(int num)
{
    uint64_t i, result = 1;
    if(num == 0)
    {
        return 1;
    }
    for(i = 0; i < num; i++)
    {
        result *= 2;
    }
    return result;
}

//Step by step地改变命题表中元素的真值，用于遍历
void step_prop_val()
{
    int i, bin = 0;
    //把命题序列合并转化为十进制，以进行递减运算
    for(i = 0; i < prop_num; i++)
    {
        bin += P[prop_num - i - 1].val * pow2(i);
    }
    //递减运算
    bin--;
    //运算完成，将十进制数分解成二进制，放入命题序列的各元素中
    for(i = 0; i < prop_num; i++)
    {
        P[prop_num - i - 1].val = bin % 2;
        bin /= 2;
    }

}

//调试输出
void debug_print()
{
    int i;
    printf("PropTable: prop_num=%d\n", prop_num);
    for(i = 0; i < prop_num; i++)
    {
        printf("[%d]->name=%s\tip=%d\tval=%d\n", i, P[i].name, P[i].ip, P[i].val);
    }
}
