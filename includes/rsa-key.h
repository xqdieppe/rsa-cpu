#ifndef RSA_KEY_H
#define RSA_KEY_H

#include <stdint.h>

typedef struct rsa_key_header_s {
	uint64_t	exponent_size;
	uint64_t	modulus_size;
}rsa_key_header_t;

#endif
