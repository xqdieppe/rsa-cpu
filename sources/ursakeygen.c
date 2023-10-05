#include "rsa-cpu.h"

void ursakeygen(uint32_t *e, uint32_t *d, uint32_t *n, size_t keysize, size_t bits) {
	u(p, bits); upseudoprime(p, keysize / 2, bits);
	u(q, bits); upseudoprime(q, keysize / 2, bits);
	umul(p, q, n, bits);
	u(phi, bits); uphi(p, q, phi, bits);
	upseudoprime(e, keysize / 4, bits / 2);
	umodinv(e, phi, d, bits);

	u(ed, bits);
	umul(e, d, ed, bits);
	u(edmod, bits); u(tmpdiv, bits);
	udivmod(ed, phi, tmpdiv, edmod, bits);
	udump(edmod, bits);

	/*
	u(clear, bits); urand(clear, bits / 4); u(encrypted, bits); u(decrypted, bits);
	umodexp(clear, e, n, encrypted, bits);
	umodexp(encrypted, d, n, decrypted, bits);
	printf("==============\n");
	udump(clear, bits);
	udump(decrypted, bits);
	printf("==============\n");
	*/
}
