#include "rsa-cpu.h"

char *decrypt(char *privkey, char *encrypted_file) {
	rsa_key_header_t header;
	ursaimportkeyheader(&header, privkey);
	size_t bits = header.modulus_size * 16;
	
	u(data, bits); u(decrypted, bits);
	int fd = open(encrypted_file, O_RDWR);
	read(fd, data, bits / 16);
	close(fd);

	ursarun(data, decrypted, privkey);
	udump(decrypted, bits / 2);
	size_t s = usize(decrypted, bits) / 8;

	printf("%d\n", s);	
	char *string = (void *) malloc((s + 1) * sizeof(char));
	memset(string, 0, s + 1); memcpy((void *) string, (void *) decrypted, s);
	printf("%s\n", string);
}
