#include <stdio.h>
#icnlude "cpu_t.h"

unit_test()
{
	// nop, syscall
	uint8_t code = "\x00\x01";
	char *text;
	cpu_dasm(code, &text);
	printf("%s\n", text);
	return 0;
}

int main()
{
	unit_test();
	return 0;
}
