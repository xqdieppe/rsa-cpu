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

#define PUBKEY "pubkey.rsa"
#define PRIVKEY "privkey.rsa"

void keygen(char *dirname, size_t keysize) {
	int m = mkdir(dirname, 0777);
	
	int pub_filename_size = strlen(dirname) + strlen(PUBKEY) + 2;
	char pub_filename[pub_filename_size];
	memset(pub_filename, 0, pub_filename_size);
	strcat(pub_filename, dirname); strcat(pub_filename, "/"); strcat(pub_filename, PUBKEY);
	
	int priv_filename_size = strlen(dirname) + strlen(PRIVKEY) + 2;
	char priv_filename[priv_filename_size];
	memset(priv_filename, 0, priv_filename_size);
	strcat(priv_filename, dirname); strcat(priv_filename, "/"); strcat(priv_filename, PRIVKEY);

	size_t bits = keysize * 2;
	u(e, bits); u(d, bits); u(n, bits);
	ursakeygen(e, d, n, keysize, bits);
	ursaexportpubkey(e, n, keysize, pub_filename);
	ursaexportprivkey(d, n, keysize, priv_filename);
}
