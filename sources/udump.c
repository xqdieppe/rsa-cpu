#include "rsa-cpu.h"

void udump(unsigned int *unit, long long bits) {
	long long size = bits / 32;

	for (long long i = size - 1; i > -1; i--) {
		printf("%08X", unit[i]);
	}
	printf("\n");
}
