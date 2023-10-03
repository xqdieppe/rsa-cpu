#include "rsa-cpu.h"

void urshift(unsigned int *unit, unsigned int *result, uint64_t rshift, size_t bits) {
	size_t skip = rshift / 16;
	size_t shift = rshift % 16;
	size_t s = bits / 16 - skip;
	uint32_t r = 0;
	
	for (int64_t i = s; i > -1; i--) {
		uint32_t tmp = ((uint16_t *)unit)[i + skip];
		tmp >>= rshift;
		((uint16_t *)result)[i] = ((uint16_t) tmp) | r;
		r = tmp << (16 - rshift);
	}
}
