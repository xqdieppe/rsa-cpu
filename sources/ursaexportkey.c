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
