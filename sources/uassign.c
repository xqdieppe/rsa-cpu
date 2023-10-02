#include "rsa-cpu.h"

void uassign(uint32_t *unit0, uint32_t *unit1, size_t bits) {
	memcpy(unit0, unit1, bits / 8);
} 
