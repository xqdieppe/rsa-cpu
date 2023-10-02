#ifndef UNITS_H
#define UNITS_H

#define u(name,bits) \
	unsigned long *name[bits / 32]; \
	memset((void *)name, 0, bits / 8);

#endif
