#ifndef RSA_KEY_H
#define RSA_KEY_H

#include <stdint.h>

typedef struct rsa_key_header_s {
	uint64_t	exponent_size;
	uint64_t	modulus_size;
}rsa_key_header_t;

void ursaexportpubkey(uint32_t *e, uint32_t *n, size_t keysize, char *filename);
void ursaexportprivkey(uint32_t *d, uint32_t *n, size_t keysize, char *filename);
void ursaimportkeyheader(rsa_key_header_t *header, char *filename);
void ursaimportkey(uint32_t *exponent, uint32_t *modulus, char *filename);

#endif
