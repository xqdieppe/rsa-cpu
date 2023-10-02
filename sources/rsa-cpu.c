#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	u(unit0, 1024); u(unit1, 1024); u(uresult, 1024);
	memset(unit0, 0xff, 128 / 8); memset(unit1, 0xff, 128 / 8);
	//urand(unit0, 128); urand(unit1, 128);
	umul(unit0, unit1, uresult, 1024);
	udump(unit0, 256); udump(unit1, 256); udump(uresult, 256);
	/*
	u(unit, 512); u(result, 512);
	memset(unit, 0xff, 256 / 8);
	udump(unit, 256);
	ulshift(unit, result, 128, 512);
	udump(result, 512);
	*/
}
