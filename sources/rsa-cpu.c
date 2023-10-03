#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	#define USIZE 256
	u(unit0, USIZE); u(unit1, USIZE); u(uresult, USIZE);
	//memset(unit0, 0xee, 512 / 8); memset(unit1, 0xff, 256 / 8);
	urand(unit0, 128); urand(unit1, 96);
	udiv(unit0, unit1, uresult, USIZE);
	udump(unit0, USIZE); udump(unit1, USIZE); udump(uresult, USIZE);
	/*
	u(unit, 512); u(result, 512);
	memset(unit, 0xff, 256 / 8);
	udump(unit, 256);
	urshift(unit, result, 128, 512);
	udump(result, 512);
	*/
}
