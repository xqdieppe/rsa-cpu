#include "rsa-cpu.h"

void sdecrypt(char *privkey, char *encrypted_file) {
	rsa_key_header_t header;
	ursaimportkeyheader(&header, privkey);
	size_t bits = header.modulus_size * 16;
	
	u(data, bits); u(decrypted, bits);
	int fd = open(encrypted_file, O_RDWR);
	if (fd == -1) { printf("%s: Unable To Read File.\n", encrypted_file); exit(1); }

	struct stat stat_;
	fstat(fd, &stat_);
	if (stat_.st_size != (bits / 16))
		{ printf("%s: Bad Encrypted File.\n", encrypted_file); close(fd); exit(1); }

	read(fd, data, bits / 16);
	close(fd);

	ursarun(data, decrypted, privkey);
	size_t s = usize((uint8_t *) decrypted, bits) / 8;

	char *string = (void *) malloc((s + 1) * sizeof(char));
	memset(string, 0, s + 1); memcpy((void *) string, (void *) decrypted, s);
	printf("%s\n", string);
}
