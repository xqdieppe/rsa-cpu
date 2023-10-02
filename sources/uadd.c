#include "rsa-cpu.h"

void uadd(unsigned int *unit0, unsigned int *unit1, unsigned int *result, size_t bits) {
	unsigned long long tmp = 0;
	unsigned long long r = 0;
	size_t s = bits / 16;

	for (size_t i = 0; i < s; i++) {
		tmp = unit0[i] + unit1[i] + r;
		result[i] = (tmp & 0xffffffff);
		r = tmp >> 32;
	}
}
