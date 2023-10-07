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

void sencrypt(char *string, char *pubkey, char *encrypted_file) {
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
