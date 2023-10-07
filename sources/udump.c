#include "rsa-cpu.h"

void udump(uint32_t *unit, size_t bits) {
	int64_t size = bits / 32;

	for (int64_t i = size - 1; i > -1; i--) {
		printf("%08X", unit[i]);
	}
	printf("\n");
}
