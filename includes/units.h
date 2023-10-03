#ifndef UNITS_H
#define UNITS_H

/*
#define u(name,bits) \
	uint32_t name[bits / 32]; \
	memset((void *)name, 0, bits / 8);
*/
#define u(name,bits) \
	uint32_t *name = malloc(bits / 8); \
	memset((void *)name, 0, bits / 8);
#endif
