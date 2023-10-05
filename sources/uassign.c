#include "rsa-cpu.h"

void uassign(uint32_t *unit0, uint32_t *unit1, size_t bits) {
	memset((void *) unit0, 0, bits / 8);
	memcpy((void *) unit0, (void *) unit1, bits / 8);
} 
