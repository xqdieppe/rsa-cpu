#include "rsa-cpu.h"

void ursakeygen(uint32_t *e, uint32_t *d, uint32_t *n, size_t keysize, size_t bits) {
	u(zero, bits);
	u(p, bits); upseudoprime(p, keysize / 2, bits);
	u(q, bits); upseudoprime(q, keysize / 2, bits);
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
		
		printf("=====CLEAR======\n");
		udump(clear, bits);
		udump(encrypted, bits);
		udump(decrypted, bits);
		printf("==============\n");
	} while (!ueq(clear, decrypted, bits));
}
