#include "rsa-cpu.h"

void ulshift(unsigned int *unit, unsigned int *result, uint64_t lshift, size_t bits) {
	size_t skip = lshift / 16;
	size_t shift = lshift % 16;
	size_t s = bits / 16 - skip;
	uint64_t r = 0;

	for (size_t i = 0; i < s; i++) {
		uint64_t tmp = ((uint16_t *)unit)[i];
		((uint16_t *)result)[skip + i] = (((uint16_t) tmp) << shift) | r;
		r = (tmp >> (16 - shift));
	}
}
