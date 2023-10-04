#include "rsa-cpu.h"

uint8_t upseudoprime_test(uint32_t *prime, size_t bits) {
	u(a, bits); urand(a, bits / 2);
	u(one, bits); one[0] = 1;
	u(psubone, bits); usub(prime, one, psubone, bits);
	u(result, bits);
	umodexp(a, psubone, prime, result, bits);
	udump(result, bits);
	if (ueq(result, one, bits)) { return (1); }
	return (0);
}

void upseudoprime(uint32_t *result, size_t size, size_t bits) {
	do {
		urand(result, size); 
		for (size_t i = 0; i < 32; i++) {
			if (!upseudoprime_test(result, bits))
				break;
		}
	} while (1);
}
