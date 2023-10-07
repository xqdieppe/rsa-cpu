/*
    Copyright (C) 2023  Quentin DIEPPE

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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
	u(zero, bits);
	if (strlen(string))
		printf("%s\n", string);
}
