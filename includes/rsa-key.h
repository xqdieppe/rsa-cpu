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

#ifndef RSA_KEY_H
#define RSA_KEY_H

#include <stdint.h>

typedef struct rsa_key_header_s {
	uint64_t	exponent_size;
	uint64_t	modulus_size;
}rsa_key_header_t;

void ursaexportpubkey(uint32_t *e, uint32_t *n, size_t keysize, char *filename);
void ursaexportprivkey(uint32_t *d, uint32_t *n, size_t keysize, char *filename);
void ursaimportkeyheader(rsa_key_header_t *header, char *filename);
void ursaimportkey(uint32_t *exponent, uint32_t *modulus, char *filename);

#endif
