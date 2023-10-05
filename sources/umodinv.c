#include "rsa-cpu.h"

void umodinv(uint32_t *a, uint32_t *mod, uint32_t *result, size_t bits) {
	u(a_, bits); a_[0] = 12;
	u(mod_, bits); mod_[0] = 7;

	u(pgcd, bits);
	int8_t su_ = 1; u(u_, bits);
	int8_t sv_ = 1; u(v_, bits);
	udump(a_, bits);
	uegcd(a_, mod_, pgcd, &su_, u_, &sv_, v_, bits);
	printf("===============\n");
	udump(pgcd, bits);
	printf("%s", ((su_ == 1) ? "" : "-")); udump(u_, bits);
	printf("%s", ((sv_ == 1) ? "" : "-")); udump(v_, bits);
	printf("===============\n");
}
