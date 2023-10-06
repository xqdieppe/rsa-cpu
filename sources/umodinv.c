#include "rsa-cpu.h"

void umodinv(uint32_t *a, uint32_t *mod, uint32_t *result, size_t bits) {
	u(pgcd, bits);
	int8_t su_ = 1; u(u_, bits);
	int8_t sv_ = 1; u(v_, bits);
	uegcd(a, mod, pgcd, &su_, u_, &sv_, v_, bits);
	u(tmpdiv, bits); udivmod(u_, mod, tmpdiv, result, bits);
}
