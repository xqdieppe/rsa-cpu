#include "rsa-cpu.h"

void dump_byte(uint8_t byte) {
	printf("%d", (byte & 128) >> 7);
	printf("%d", (byte & 64) >> 6);
	printf("%d", (byte & 32) >> 5);
	printf("%d", (byte & 16) >> 4);
	printf("%d", (byte & 8) >> 3);
	printf("%d", (byte & 4) >> 2);
	printf("%d", (byte & 2) >> 1);
	printf("%d", (byte & 1));
}

void udumpbin(unsigned int *unit, long long bits) {
	long long size = bits / 8;

	for (long long i = size - 1; i > -1; i--) {
		dump_byte(((uint8_t *) unit)[i]);
	}
	printf("\n");
}
