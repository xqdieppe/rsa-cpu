#include "rsa-cpu.h"

void ursaexportpubkey(uint32_t *e, uint32_t *n, size_t keysize, char *filename) {
	rsa_key_header_t header;
	header.exponent_size = keysize / (4 * 8); 
	header.modulus_size = keysize / 8;

	int fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
	write(fd, &header, sizeof(rsa_key_header_t));
	write(fd, e, header.exponent_size);
	write(fd, n, header.modulus_size);
	close(fd);
}

void ursaexportprivkey(uint32_t *d, uint32_t *n, size_t keysize, char *filename) {
	rsa_key_header_t header;
	header.exponent_size = keysize / 8; 
	header.modulus_size = keysize / 8;

	int fd = open(filename, O_CREAT | O_RDWR, S_IRWXU);
	write(fd, &header, sizeof(rsa_key_header_t));
	write(fd, d, header.exponent_size);
	write(fd, n, header.modulus_size);
	close(fd);
}
