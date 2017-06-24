#include "prop.h"

//创建/初始化命题表，返回对应的指针
PropTable *create_prop_table(uint32_t size)
{
    uint32_t i;
    //内存分配
	PropTable *p = (PropTable *)malloc(sizeof(PropTable) * size);
    //依次初始化每个元素的索引标记和初始真值
    for(i = 0; i < size; i++)
    {
        p[i].val = 1;
    }
    //初始化命题数（置0）
    prop_num = 0;
	return p;
}

void add_prop_element(char name[PROP_NAME_SIZE])
{
    uint32_t i;
    
    //检测是否有命题名字重复，重复则把当前命题的序数加到对应的索引列表中
    for(i = 0; i < prop_num; i++)
    {
        if(strcmp(P[i].name, name) == 0)
        {
            return;
        }
    }
    //若不重复，则添加到新索引中
    strcpy(P[prop_num].name, name);
    //命题个数+1
    prop_num++;
    
}

//打印真值表的标题，result_text指结果列头部的标题文本
void print_table_title(char *result_text)
{
    uint32_t i;
    for(i = 0; i < prop_num; i++)
    {
        printf(" %s", P[i].name);
    }
    printf(" | %s\n", result_text);
}

//从命题表指定名字的元素中得到真值，参数是命题元素的名字
_Bool get_prop_val(char name[PROP_NAME_SIZE])
{
    uint32_t i;
    for(i = 0; i < prop_num; i++)
    {
        if(strcmp(P[i].name, name) == 0)
        {
            return P[i].val;
        }
    }

}

//自编的pow(2, n)运算函数
uint64_t pow2(uint32_t num)
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

//Step by step地改变命题表中元素的真值，用于遍历所有可能的真值，返回1表示真值遍历完毕
_Bool step_prop_val()
{
    uint64_t i;
    //flag指示遍历状态，返回1表示真值遍历完毕，返回0表示遍历尚未完成，暂且默认置为1
    _Bool flag = 1;
    for(i = 0; i < prop_num; i++)
    {
        //如果当前位为1则将其置0，flag置为0（遍历为完毕），跳出循环
        if(P[prop_num - i - 1].val)
        {
            P[prop_num - i - 1].val = 0;
            flag = 0;
            break;
        }
        //否则当前位为0将当前位置为1，继续循环，下次循环将操作下一位的值
        else
        {
            P[prop_num - i - 1].val = 1;
        }
    }

    //返回遍历状态
    return flag;
}

/* 此函数副本已被弃用，因为uint64_t可表示的数范围有限
//Step by step地改变命题表中元素的真值，用于遍历所有可能的真值，返回1表示真值遍历完毕
_Bool step_prop_val()
{
    uint64_t i, bin = 0;

    //把命题序列合并转化为十进制，以进行递减运算
    for(i = 0; i < prop_num; i++)
    {
        bin += P[prop_num - i - 1].val * pow2(i);
    }

    bin--;
    //递减运算，如果小于0的话，说明真值遍历完毕，返回1
    if(bin )
    {
        return 1;
    }
    
    //运算完成，将十进制数分解成二进制，放入命题序列的各元素中
    for(i = 0; i < prop_num; i++)
    {
        P[prop_num - i - 1].val = bin % 2;
        bin /= 2;
    }
    
    //正常状态返回0
    return 0;

}
*/
