#include "rsa-cpu.h"

void udiv2(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	u(u0, bits); uassign(u0, unit0, bits); u(block, bits);

	for (size_t i = 0; i < bits; i++) {
		u(tmpblock, bits); ulshift(block, tmpblock, 1, bits); uassign(block, tmpblock, bits);
		block[0] |= (u0[bits / 32 - 1]) >> 31;
		u(tmpu0, bits); ulshift(u0, tmpu0, 1, bits); uassign(u0, tmpu0, bits);
		if (usup(unit1, block, bits)) {	
			u(tmpresult, bits); ulshift(result, tmpresult, 1, bits); uassign(result, tmpresult, bits);
		} else {
			u(tmpblock, bits); usub(block, unit1, tmpblock, bits); uassign(block, tmpblock, bits);	
			u(tmpresult, bits); ulshift(result, tmpresult, 1, bits); uassign(result, tmpresult, bits);
			result[0] |= 1;
		}
	}
}
