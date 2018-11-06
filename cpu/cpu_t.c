/*!
 * \brief cpu_t.c
 * \author Exdev
 * \version 0.6.0
 */

#include "cpu_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*

// Shell for amd64-like stack
// add check later (trap segfault)

/*
inline void cpu_push(struct cpu_t *cpu, uint64_t val)
{
	cpu->reg[REG_RSP] -= sizeof(uint64_t);
	*(uint64_t*) (cpu->reg[REG_RSP]) = val;
}

inline uint64_t cpu_pop(struct cpu_t *cpu)
{
	register int val = *(uint64_t*) (cpu->reg[REG_RSP]);
	(cpu->reg[REG_RSP]) += sizeof(uint64_t);
	return val;
}

/// CPU commands:
static inline int cpu_cmd_pushm(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_pushmr(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_popr(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_popm(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_popmr(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_add(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_sub(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_mul(struct cpu_t *cpu) {return 0;}
static inline int cpu_cmd_div(struct cpu_t *cpu) {return 0;}

inline int cpu_cmd_pushq(struct cpu_t *cpu)
{
	stack_push(&cpu->cpu_stk, (uint64_t)cpu->rip);
	cpu->rip += sizeof(uint64_t);
	return 0;
}

inline int cpu_cmd_pushr(struct cpu_t *cpu)
{
	uint8_t reg = *(uint8_t*) cpu->rip;
	cpu->rip += sizeof(uint8_t);
	stack_push(&cpu->cpu_stk, (uint64_t)cpu->reg[reg]);
	return 0;
}

inline int cpu_cmd_nop(struct cpu_t *cpu)
{
	// nop
	return 0;
}

inline int cpu_cmd_syscall(struct cpu_t *cpu)
{
	cpu->trap = TRAP_SYSCALL;
	return 0;
}

int cpu_syscall(struct cpu_t *cpu)
{
	switch(cpu->reg[REG_RAX]) {
	case SYSCALL_EXIT:
		cpu->trap = TRAP_EXIT;
		break;
	default:
		cpu->trap = TRAP_WRONG_SYSCALL;
		return -1;
	}
	return 0;
}

int cpu_exec(struct cpu_t *cpu)
{
	while (1) {
		if (!cpu->trap) {
			if (cpu->trap == TRAP_SYSCALL)
				cpu_syscall(cpu);
			if (cpu->trap == TRAP_EXIT)
				return 0;
			if (cpu->trap == TRAP_WRONG_SYSCALL)
				return -1;
		}

		uint8_t cmd = *(uint8_t*) (cpu->rip);
		(cpu->rip)++;
		switch (cmd) {

#define DEF_CMD(name)		\
		case CMD_##name:		\
			cpu_cmd_##name(cpu);\
			break;

#include "cmd_list.h"
#undef DEF_CMD

		default:
			printf("Wrong cmd\n");
			return -1;
		}
	}
}
*/
