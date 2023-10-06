#include "rsa-cpu.h"

void keygen(char *dirname, size_t bits) {
	int m = mkdir(dirname, 666);
	printf("%d\n", m);
}
