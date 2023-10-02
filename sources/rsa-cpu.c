#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	u(unit0, 256); u(unit1, 256); u(uresult, 256);
	urand(unit0, 128); urand(unit1, 128);
	uadd(unit0, unit1, uresult, 256);
	udump(unit0, 128); udump(unit1, 128); udump(uresult, 256);
}
