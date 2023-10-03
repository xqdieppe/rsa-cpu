#include "rsa-cpu.h"

uint8_t uinf(uint32_t *unit0, uint32_t *unit1, int64_t bits) {
	int64_t size = bits / 32;

	for (int64_t i = size - 1; i > -1; i--) {
		if (unit0[i] ^ unit1[i]) {
			return (unit0[i] < unit1[i]);
		}
	}
	return (0);
}
