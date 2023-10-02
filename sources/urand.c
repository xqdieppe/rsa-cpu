#include "rsa-cpu.h"

void urand(unsigned int *unit, size_t size) {
	size_t s = size / 32;

	for (size_t i = 0; i < s; i++) {
		unit[i] = rand();
	}
}
