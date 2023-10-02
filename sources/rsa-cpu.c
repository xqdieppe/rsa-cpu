#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	u(unit0, 1024); u(unit1, 1024); u(uresult, 1024);
	urand(unit0, 128); urand(unit1, 128);
	umul(unit0, unit1, uresult, 1024);
	udump(unit0, 256); udump(unit1, 256); udump(uresult, 256);

	/*
	u(unit, 256); u(result, 256);
	urand(unit, 256);
	udump(unit, 256);
	ulshift(unit, result, 128, 256);
	udump(result, 256);
	*/
}
