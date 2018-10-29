#ifndef _CPU_T_H
#define _CPU_T_H_

enum CMD_CODES {
#define DEF_CMD(name)	CMD_##name,
#include "cmd_list.h"
CMD_MAX,
#undef DEF_CMD
};

enum REG_CODES {
#define DEF_REG(name)	REG_##name,
#include "reg_list.h"
REG_MAX,
#undef DEF_REG
};

enum TRAP_CODES {
TRAP_NO_TRAP,
TRAP_SYSCALL,
TRAP_WRONG_SYSCALL,
TRAP_MEMORY_FAIL,
};


struct cpu_t {
	uint64_t rip;
	uint64_t reg[REG_MAX];
	uint64_t trap;
};

ssize_t code_asm (char    *text, uint8_t **code_p);
ssize_t code_dasm(uint8_t *code, char    **text_p);

int	cpu_init(struct cpu_t *cpu);
int	cpu_load(struct cpu_t *cpu, uint8_t *code);
int	cpu_exec(struct cpu_t *cpu);

#endif // _CPU_T_H_
