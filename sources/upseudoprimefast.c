#include "rsa-cpu.h"

void upseudoprimefastcandidate(uint32_t *result, size_t size, size_t bits) {
	#define PRIME_SIZE 64
	u(one, bits); one[0] = 1;
	u(prime, bits); prime[0] = 2;
	size_t nbr_of_primes = size / PRIME_SIZE;
	for (size_t i = 0; i < nbr_of_primes; i++) {
		u(p, bits); upseudoprime(p, PRIME_SIZE, PRIME_SIZE * 2);
		u(tmpprime, bits); umul(prime, p, tmpprime, bits); uassign(prime, tmpprime, bits);
	}
	uadd(prime, one, result, bits);
}

void upseudoprimefast(uint32_t *result, size_t size, size_t bits) {
	do {
		upseudoprimefastcandidate(result, size, bits);
		if (upseudoprime_test_32(result, bits)) return;
	} while (1);
}
