#include "rsa-cpu.h"

void usub(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	int64_t tmp = 0;
	uint32_t r = 0;
	size_t s = bits / 32;

	for (size_t i = 0; i < s; i++) {
		tmp = unit0[i]; tmp -= unit1[i]; tmp -= r;
		result[i] = (tmp < 0) ? (tmp + 0xffffffff + 1) : tmp;
		r = (tmp < 0) ? 1 : 0;
	}
}
