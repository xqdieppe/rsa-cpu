#include "rsa-cpu.h"

void ursarun(uint32_t *unit, uint32_t *result, char *filename) {
	rsa_key_header_t header;
	ursaimportkeyheader(&header, filename);

	size_t bits = header.modulus_size * 16;
	u(exp, bits); u(mod, bits);
	ursaimportkey(exp, mod, filename);
	umodexp(unit, exp, mod, result, bits);
}
