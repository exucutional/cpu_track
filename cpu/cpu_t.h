/*!
 * \brief cpu_t.h
 * \author Exdev
 * \version 0.6.0
 */

#ifndef _CPU_T_H_
#define _CPU_T_H_

#include <stdint.h>
#include "stack_t.h"
#include <string.h>

#define LABEL_MAX 1024

enum CMD_CODES
{
	#define DEF_CMD(name, val)	CMD_##name,
	#include "cmd_list.h"
	CMD_MAX,
	#undef DEF_CMD
};

enum REG_CODES
{
	#define DEF_REG(name)	REG_##name,
	#include "reg_list.h"
	REG_MAX,
	#undef DEF_REG
};

enum TRAP_CODES
{
	TRAP_NO_TRAP,
	TRAP_EXIT,
	TRAP_SYSCALL,
	TRAP_WRONG_SYSCALL,
	TRAP_MEMORY_FAIL,
};

enum SYSCALL_CODES
{
	SYSCALL_EXIT,
	SYSCALL_INPQ,
};

struct label_t
{
	size_t offs;
	int isdefined;
}lbl[LABEL_MAX];

struct cpu_t
{
	uint64_t *rip;
	uint64_t reg[REG_MAX];
	struct stack cpu_stk;
	uint64_t trap;
};

ssize_t code_asm (char    *text, uint8_t **code_p);
ssize_t code_dasm(uint8_t *code, char **text_p, ssize_t size);

int get_cmd(char **text_p, uint8_t **code_p);
int get_reg(char **text_p, uint8_t **code_p);
int get_num(char **text_p, uint8_t **code_p);
int get_label(char **text_p, uint8_t **code_p);

int put_cmd(char **text_p, uint8_t **code_p);
int put_reg(char **text_p, uint8_t **code_p);
int put_num(char **text_p, uint8_t **code_p);
int put_label(char **text_p, uint8_t **code_p);

int	cpu_init(struct cpu_t *cpu);
int	cpu_load(struct cpu_t *cpu, uint8_t *code);
int	cpu_exec(struct cpu_t *cpu);


#endif // _CPU_T_H_
