#include "spli.h"
#include "prop.h"

int main(int argc, char *argv[])
{
	int i;
	//初始化命题表
	P = create_prop_table(PROP_MAX_SIZE);
	//初始化真值表（大小为2的PROP_MAX_SIZE次幂）
	T = create_result_table(pow2(PROP_MAX_SIZE));

	strcpy(expr, argv[1]);
	if(argc == 2)
	{
		//定义输入缓冲区
		YY_BUFFER_STATE bp;
		//第一次parsing，添加命题到命题表（初始化命题遍历）
		has_added = 0;
		//从字符串读取输入
		bp = yy_scan_string(expr);
		//设置词法分析器读取的缓冲区
		yy_switch_to_buffer(bp);
		//开始调用parser
		yyparse();
		//递减以改变命题表中元素的值
		step_prop_val();
		//放弃缓冲区的内容
		yy_flush_buffer(bp);
		//第一次parsing结束，已经添加命题到命题表
		has_added = 1;

		//后续的parsing，遍历命题的真值（每次parsing时，parser会计算并保存出表达式运算结果）
		for(i = 1; i < pow2(prop_num); i++)
		{
			bp = yy_scan_string(expr);
			//设置词法分析器读取的缓冲区
			yy_switch_to_buffer(bp);
			//重新调用parser
			yyparse();
			//递减以改变命题表中元素的值
			step_prop_val();
			//放弃缓冲区的内容
			yy_flush_buffer(bp);
		}

		//释放缓冲区
		yy_delete_buffer(bp);
		//打印真值表的标题，结果列头部的标题文本为命令行参数
		print_table_title(expr);
		//打印整个真值表
		print_table_body();
		return 0;
	}
	else
	{
		//无命令行参数时报错
		fprintf(stderr, "Error: Parameter is Wrong!\n");
		return 1;
	}	
	
}
