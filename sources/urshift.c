#include "rsa-cpu.h"

void urshift(unsigned int *unit, unsigned int *result, size_t rshift, size_t bits) {
	size_t skip = rshift / 16;
	size_t shift = rshift % 16;
	size_t s = bits / 16 - skip;
	uint32_t r = 0;
	
	for (int64_t i = s - skip - 1; i > -1; i--) {
		uint64_t tmp = ((uint16_t *)unit)[i + skip];
		((uint16_t *)result)[i] = (((uint16_t) tmp) >> shift) | r;
		r = (tmp << (16 - shift));
	}
}
