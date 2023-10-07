#include "rsa-cpu.h"

void ursaimportkeyheader(rsa_key_header_t *header, char *filename) {
	int fd = open(filename, O_RDWR);
	if (fd ==  -1) { printf("%s: Unable To Read File.\n"); exit(1); }
	int rhdr = read(fd, header, sizeof(rsa_key_header_t));
	if (rhdr != sizeof(rsa_key_header_t)) { printf("%s : Bad RSA Key.\n", filename); close(fd); exit(1); }
	close(fd);
}

void ursaimportkey(uint32_t *exponent, uint32_t *modulus, char *filename) {
	rsa_key_header_t header;
	int fd = open(filename, O_RDWR);
	if (fd ==  -1) { printf("%s: Unable To Read File.\n"); exit(1); }
	int rhdr = read(fd, &header, sizeof(rsa_key_header_t));
	if (rhdr != sizeof(rsa_key_header_t)) { printf("%s : Bad RSA Key.\n", filename); close(fd); exit(1); }
	
	struct stat stat_;
	fstat(fd, &stat_);
	if (stat_.st_size != (sizeof(rsa_key_header_t) + header.exponent_size + header.modulus_size)) {
		printf("%s: Bad RSA Key.\n", filename); exit(1);
	}
	int rexp = read(fd, exponent, header.exponent_size);
	int rmod = read(fd, modulus, header.modulus_size);
	close(fd);
}
