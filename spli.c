#include "spli.h"

int main(int argc, char **argv)
{
	if(argc > 1)
	{
		yy_switch_to_buffer(yy_scan_string(argv[1]));
		yyparse();
		return 0;
	}
	else
	{
		fprintf(stderr, "Error: no expression input!\n");
	}
	
}
