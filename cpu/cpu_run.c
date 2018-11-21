/*!
 * \brief cpu_code.c
 * \author Exdev
 * \version 0.5
 */

#include "cpu_t.h"
#include <assert.h>

const size_t MEMORY_SIZE = 4096;

int main(int argc, char* argv[])
{
	char *text = calloc(MEMORY_SIZE, sizeof(char));
	uint8_t *code = calloc(MEMORY_SIZE, sizeof(uint8_t));

	FILE *fin = NULL;

	if (argc < 1)
		assert (0);
	fin = fopen(argv[1], "r");

	if (fin == NULL)
		assert (0);
	fread(text, 1024, 1, fin);

	code_asm(text, &code);

	struct cpu_t cpu = {};
	cpu_init(&cpu, &code);

	fprintf(stderr, "----Running----\n");
	int tmp = cpu_run(&cpu);
	//assert(tmp == 0);
	unit_test(&cpu, &code);

	return 0;
}
