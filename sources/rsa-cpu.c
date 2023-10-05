#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	#define USIZE 128

	/*
	u(unit0, USIZE); u(unit1, USIZE); u(uresult, USIZE); u(umod, USIZE);
	//memset(unit0, 0xff, 256 / 8); memset(unit1, 0xff, 256 / 8);
	urand(unit0, USIZE / 2); urand(unit1, USIZE / 4);
	udivmod(unit0, unit1, uresult, umod, USIZE);
	udump(unit0, USIZE); udump(unit1, USIZE); udump(uresult, USIZE); udump(umod, USIZE);
	*/

	/*
	u(unit, 128); u(result, 128);
	memset(unit, 0xff, 32 / 8);
	udump(unit, 128);
	ulshift(unit, result, 1, 128);
	udump(result, 128);
	*/

	/*
	u(unit0, 128); u(unit1, 128);
	memset(unit0, 0xff, 32 / 8);
	memset(unit1, 0xfe, 32 / 8);
	udump(unit0, 128); udump(unit1, 128);
	printf("%d\n", usup(unit0, unit1, 128));
	*/

	/*
	u(unit, USIZE); u(exp, USIZE); u(mod, USIZE); u(result, USIZE);
	urand(unit, 64); urand(exp, 32); urand(mod, 64);
	umodexp(unit, exp, mod, result, USIZE);
	udump(unit, USIZE); udump(exp, USIZE); udump(mod, USIZE); udump(result, USIZE);
	*/

	u(prime, USIZE);
	upseudoprime(prime, USIZE / 2, USIZE);
	udump(prime, USIZE);

	/*
	u(e, USIZE); u(d, USIZE); u(n, USIZE);
	ursakeygen(e, d, n, USIZE, USIZE);
	udump(e, USIZE); udump(d, USIZE); udump(n, USIZE);
	*/
}
