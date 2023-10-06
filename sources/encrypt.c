#include "rsa-cpu.h"

void encrypt(char *string, char *pubkey, char *encrypted_file) {
	rsa_key_header_t header;
	ursaimportkeyheader(&header, pubkey);
	size_t bits = header.modulus_size * 16;

	u(data, bits); u(encrypted, bits);
	memcpy((void *) data, (void *) string, strlen(string));	
	ursarun(data, encrypted, pubkey);

	int fd = open(encrypted_file, O_CREAT | O_RDWR, S_IRWXU);
	write(fd, encrypted, bits / 16);
	close(fd);
}
