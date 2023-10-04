#include "rsa-cpu.h"

void uphi(uint32_t *p, uint32_t *q, uint32_t *result, size_t bits) {
	u(one, bits); one[0] = 1;
	u(psubone, bits); usub(p, one, psubone, bits);
	u(qsubone, bits); usub(q, one, qsubone, bits);
	umul(psubone, qsubone, result, bits);
}
