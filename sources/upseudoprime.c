#include "rsa-cpu.h"

uint8_t upseudoprime_test(uint32_t *prime, size_t bits) {
	u(a, bits); urand(a, 32);
	u(one, bits); one[0] = 1;
	u(psubone, bits); usub(prime, one, psubone, bits);
	u(result, bits);
	umodexp(a, psubone, prime, result, bits);
	udump(result, bits);
	if (ueq(result, one, bits)) { return (1); }
	return (0);
}

uint8_t upseudoprime_test_32(uint32_t *prime, size_t bits) {
	for (size_t i = 0; i < 32; i++) {
		if (!upseudoprime_test(prime, bits))
			return (0);
	}
	return (1);
}

void upseudoprime(uint32_t *result, size_t size, size_t bits) {
	do {
		urand(result, size); 
		if (upseudoprime_test_32(result, bits)) return;
	} while (1);
}
