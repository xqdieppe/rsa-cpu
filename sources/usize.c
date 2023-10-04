#include "rsa-cpu.h"

void usize(uint32_t *unit, int64_t bits) {
	int64_t size = bits / 32;

	for (int64_t i = size - 1; i > -1; i--) {
		if (unit[i])
			return (i * 32);
	}
	return (0);
}
