#include "rsa-cpu.h"

uint64_t ursakeygen_rand_prime_size(size_t size) {
	size_t s = size / 32;
	return ((rand() % (s + 1)) + 0);  
}

void ursakeygen(uint32_t *e, uint32_t *d, uint32_t *n, size_t keysize, size_t bits) {
	u(zero, bits);
	size_t rand_prime_size = ursakeygen_rand_prime_size(keysize / 4);
	u(p, bits); upseudoprime(p, keysize / 2 + rand_prime_size, bits);
	u(q, bits); upseudoprime(q, keysize / 2 - rand_prime_size, bits);
	umul(p, q, n, bits);
	u(phi, bits); uphi(p, q, phi, bits);
	u(clear, bits); u(encrypted, bits); u(decrypted, bits);

	do {
		upseudoprime(e, keysize / 4, bits / 2);
		umodinv(e, phi, d, bits);
		
		urand(clear, bits / 4);
		uassign(encrypted, zero, bits);
		uassign(decrypted, zero, bits);
		
		umodexp(clear, e, n, encrypted, bits);
		umodexp(encrypted, d, n, decrypted, bits);
	} while (!ueq(clear, decrypted, bits));
	udump(n, bits);
}
