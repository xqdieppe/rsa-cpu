#include "rsa-cpu.h"

void uadd(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	uint64_t tmp = 0;
	uint64_t r = 0;
	size_t s = bits / 32;

	for (size_t i = 0; i < s; i++) {
		tmp = unit0[i]; tmp += unit1[i]; tmp += r;
		r = (tmp >> 32);
		result[i] = (tmp & 0xffffffff);
	}
}
