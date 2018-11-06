#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cpu_t.h"

int unit_test()
{
	char *buf = calloc(1000, sizeof(uint8_t));
	
	// nop
	// syscall (rax == 0 => sys_exit)
	buf[0] = CMD_nop;
	buf[1] = CMD_syscall;
	
	char *text;
	//code_dasm(buf, &text, 20);
	//printf("%s\n", text);

	struct cpu_t cpu = {};
	cpu.reg[REG_rax] = SYSCALL_EXIT;	// 0
	cpu.reg[REG_rsp] = (uint64_t) (buf + 100);

	cpu_set_rip(&cpu, buf);
	cpu_set_mem(&cpu, buf, buf + 900);
	int tmp = cpu_run(&cpu);
	assert(tmp == 0);
	return 0;
}

int main()
{
	unit_test();
	return 0;
}
