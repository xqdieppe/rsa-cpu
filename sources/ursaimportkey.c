#include "rsa-cpu.h"

void ursaimportkeyheader(rsa_key_header_t *header, char *filename) {
	int fd = open(filename, O_RDWR);
	int r = read(fd, header, sizeof(rsa_key_header_t));
	printf("%d, %d, %d\n", fd, r, header->exponent_size);
	close(fd);
}

void ursaimportkey(uint32_t *exponent, uint32_t *modulus, char *filename) {
	rsa_key_header_t header;
	int fd = open(filename, O_RDWR);
	read(fd, &header, sizeof(rsa_key_header_t));
	read(fd, exponent, header.exponent_size);
	read(fd, modulus, header.modulus_size);
	close(fd);
}
