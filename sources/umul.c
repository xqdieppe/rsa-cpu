#include "rsa-cpu.h"

void umul_step(uint32_t *unit0, uint16_t unit1, uint32_t *result, size_t bits) {
	uint64_t tmp = 0;
	uint64_t r = 0;
	size_t s = bits / 16;

	for (size_t i = 0; i < s; i++) {
		tmp = ((uint16_t *)unit0)[i] * unit1 + r; 
		((uint16_t *)result)[i] = tmp & 0xffff;
		r = tmp >> 16;
	}
}

void umul(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	size_t s = bits / 16;

	for (size_t i = 0; i < s; i++) {
		u(tmp, bits); u(tmp_shift, bits); u(nresult, bits);

		umul_step(unit0, ((uint16_t *)unit1)[i], tmp, bits);

		ulshift(tmp, tmp_shift, i * 16, bits);
		uadd(result, tmp_shift, nresult, bits);
		uassign(result, nresult, bits);
	}
}
