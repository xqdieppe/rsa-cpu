#include "rsa-cpu.h"

void umul(unsigned int *unit0, unsigned int *unit1, unsigned int *result, size_t bits) {
	unsigned long long tmp = 0;
	unsigned long long r = 0;
	size_t s = bits / 16;

	for (size_t i = 0; i < s; i++) {
		tmp = (((unsigned short *) unit0)[i] * ((unsigned short *) unit1)[i]) + r;
		printf("tmp: %016x\n", tmp);
		printf("r: %016x\n", r);
		printf("result: (%016x * %016x) + %016x = %016x\n",
				((unsigned short *) unit0)[i],
				((unsigned short *) unit1)[i],
				r, tmp
		      );
		((unsigned short *)result)[i] = (tmp & 0xffff);
		r = tmp >> 16;


		
	}
}
