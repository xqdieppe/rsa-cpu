#include "rsa-cpu.h"

uint32_t upseudoprime_pretest(uint32_t *prime, uint32_t number, size_t bits) {
	u(zero, bits);
	u(tmpdiv, bits); u(tmpmod, bits);
	u(divisor, bits); divisor[0] = number;
	udivmod(prime, divisor, tmpdiv, tmpmod, bits);
	return (ueq(tmpmod, zero, bits));
}

uint8_t upseudoprime_test(uint32_t *prime, size_t bits) {
	if (
		upseudoprime_pretest(prime, 2, bits)
		| upseudoprime_pretest(prime, 3, bits)
		| upseudoprime_pretest(prime, 5, bits)
		| upseudoprime_pretest(prime, 7, bits)
		| upseudoprime_pretest(prime, 11, bits)
		| upseudoprime_pretest(prime, 13, bits)
		| upseudoprime_pretest(prime, 17, bits)
		| upseudoprime_pretest(prime, 19, bits)
		| upseudoprime_pretest(prime, 23, bits)
		| upseudoprime_pretest(prime, 29, bits)
		| upseudoprime_pretest(prime, 31, bits)
	) return (0);

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
