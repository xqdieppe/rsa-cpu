#include "rsa-cpu.h"

void udiv_main(uint32_t *unit0, uint32_t *unit1, uint32_t *result, uint32_t *previous, uint32_t *current, size_t bits) {
	u(tmp, bits); u(tmp1, bits);
	umul(unit1, current, tmp, bits);

	usub(uint0, tmp, tmp1, bits);
	uint8_t d = usupeq(unit0, tmp, bits);
	uint8_t d1 = uinf(tmp1, unit1, bits);
	if (d & d1) { uassign(result, current, bits); return; }

	uint8_t d2 = usup(unit0, tmp, bits);
	if (d2) { u(current2, bits); u(mul2, bits); mul2[0] = 2; umul(current, mul2, current2, bits);
		  udiv_main(unit0, unit1, result, current, current2, bits); return; }

	uint8_t d3 = uinf(unit0, tmp, bits);
	if (d3) { u(tmp2, bits); uadd(previous, current, tmp2, bits);
		  u(ncurrent, bits); u(div2, bits); div2[0] = 2; udiv(tmp2, div2, ncurrent, bits);
		  udiv_main(unit0, unit1, previous, ncurrent); return; }

}

void udiv(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	u(previous, bits); u(current, bits); memset(current, 0xff, bits / 8);
	udiv_main(unit0, unit1, result, previous, current, bits);
}
