#include "rsa-cpu.h"

void ulshift(unsigned int *unit, unsigned int *result, uint64_t lshift, size_t bits) {
	uint64_t skip = lshift / 32;
	uint64_t shift = lshift % 32;
	size_t s = bits / 32 - skip;
	uint64_t tmp = 0;
	uint64_t r = 0;	

	for (size_t i = 0; i < s; i++) {
		tmp = (unit[i] << shift) & 0xffffffff;
		//printf("tmp=%016x\n", tmp);
		//printf("r=%016x\n", r);
		result[skip + i] = tmp | r;
		r = (unit[i] >> (32 - shift)) & 0xffffffff;
	}
}
