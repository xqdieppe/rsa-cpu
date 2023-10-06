#include "rsa-cpu.h"

size_t usize(uint8_t *unit, int64_t bits) {
	int64_t size = bits / 32;

	for (int64_t i = size - 1; i > -1; i--) {
		if (unit[i])
			return ((i + 1) * 8);
	}
	return (0);
}
