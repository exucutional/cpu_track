#include "cpu_t.h"













// Shell for amd64-like stack
// add check later (trap segfault)
inline void cpu_push(struct cpu_t *cpu, uint64_t val)
{
	cpu->reg[REG_RSP] -= sizeof(uint64_t);
	*(uint64_t) (cpu->reg[REG_RSP]) = val;
}
inline uint64_t cpu_pop(struct cpu_t *cpu)
{
	register int val = *(uint64_t) (cpu->reg[REG_RSP]);
	(cpu->reg[REG_RSP]) += sizeof(uint64_t);
}

// Supported syscalls
// RCX - syscall number 
// 1 - input qword in rax
// 2 - out qword from rax
// 3 - input double in rax
// 4 - out double from rax
inline int cpu_syscall(struct cpu_t *cpu)
{
	switch (cpu->reg[REG_RCX]) {
	case 3:
		scanf("%lg", reg[REG_RAX]);
		return 0;
	default:
		cpu->trap = TRAP_WRONG_SYSCALL;
	}


/// CPU comands:
inline int cpu_cmd_pushq(struct cpu_t *cpu)
{
	cpu_push(cpu, *(uint64_t) cpu->rip);
	cpu->rip += sizeof(uint64_t);
}

inline int cpu_cmd_nop(struct cpu_t *cpu)
{
	// nop
}

inline int cpu_cmd_syscall(struct cpu_t *cpu)
{
	cpu->trap = TRAP_SYSCALL;
}