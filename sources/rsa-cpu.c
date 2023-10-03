#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	#define USIZE 1024
	u(unit0, USIZE); u(unit1, USIZE); u(uresult, USIZE);
	//memset(unit0, 0xee, 512 / 8); memset(unit1, 0xff, 256 / 8);
	urand(unit0, 512); urand(unit1, 256);
	udiv(unit0, unit1, uresult, USIZE);
	udump(unit0, USIZE); udump(unit1, USIZE); udump(uresult, USIZE);

	/*
	u(unit, 128); u(result, 128);
	//memset(unit, 0xff, 32 / 8);
	((uint64_t *)unit)[0] = 0x17FFFFFFB;
	udump(unit, 128);
	urshift(unit, result, 1, 128);
	udump(result, 128);
	
	*/
}
