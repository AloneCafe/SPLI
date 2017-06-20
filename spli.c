#include "spli.h"
#include "prop.h"

int main(int argc, char **argv)
{
	//初始化命题表
	P = create_prop_table(PROP_MAX_SIZE);
	//初始化真值枚举表（最大枚举数为2的PROP_MAX_SIZE次幂）
	T = create_result_table(pow2(PROP_MAX_SIZE));

	if(argc > 1)
	{
		int i;

		//第一次parsing，添加命题到命题表（初始化命题遍历）
		has_added = 0;

		//设置词法分析器从命令行参数中读取文本输入
		yy_switch_to_buffer(yy_scan_string(argv[1]));
		//开始调用parser
		yyparse();
		//打印表标题，列头部的标题文本为命令行参数
		print_table_title(argv[1]);
		//打印第0个结果
		print_table_body(0);
		//递减以改变真值表中元素的值
		step_prop_val();

		//第一次parsing结束，已经添加命题到命题表
		has_added = 1;

		//后续的parsing，遍历命题的真值（每次parsing时，parser会计算并保存出表达式运算结果）
		for(i = 1; i < pow2(prop_num); i++)
		{
			//设置词法分析器从命令行参数中读取文本输入
			yy_switch_to_buffer(yy_scan_string(argv[1]));
			//重新调用parser
			yyparse();
			//打印第i个结果
			print_table_body(i);
			//递减以改变真值表中元素的值
			step_prop_val();
		}

		return 0;
	}
	else
	{
		//无命令行参数时报错
		fprintf(stderr, "Error: No expression input!\n");

		return 1;
	}	
}
