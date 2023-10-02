#include "rsa-cpu.h"

void udump(unsigned int *number, size_t bits) {
	size_t size = bits / 32;

	for (size_t i = 0; i < size; i++) {
		printf("%032x", number[i]);
	}
	printf("\n");
}
