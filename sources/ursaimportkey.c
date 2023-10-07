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
		printf("%s: Bad RSA Key.\n", filename); close(fd); exit(1);
	}
	int rexp = read(fd, exponent, header.exponent_size);
	int rmod = read(fd, modulus, header.modulus_size);
	close(fd);
}
