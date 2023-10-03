#include "rsa-cpu.h"

void udiv2(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	u(u0, bits); uassign(u0, unit0, bits);
	u(block, bits);

	while (1) {
		uint8_t supeq = usupeq(unit1, block, bits);
		if (!supeq) {
			u(tmpblock, bits); ulshift(block, tmpblock, 1, bits); uassign(block, tmpblock, bits);
			block[0] |= u0[0] & 1;
			u(tmpu0, bits); urshift(u0, tmpu0, 1, bits); uassign(u0, tmpu0, bits);
			
			u(tmpresult, bits); ulshift(result, tmpresult, 1, bits); uassign(result, tmpresult, bits);
			continue;
		} else {
			u(tmpu0, bits); usub(u0, unit1, tmpu0, bits); uassign(u0, tmpu0, bits);
			
			u(tmpresult, bits); ulshift(result, tmpresult, 1, bits); uassign(result, tmpresult, bits);
			result[0] |= 1;
		}
	}
}
