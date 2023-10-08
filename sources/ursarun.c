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

void ursarun(uint32_t *unit, uint32_t *result, char *filename) {
	rsa_key_header_t header;
	ursaimportkeyheader(&header, filename);

	size_t bits = header.modulus_size * 16;
	u(exp, bits); u(mod, bits);
	ursaimportkey(exp, mod, filename);
	if (usupeq(unit, mod, bits))
		{ printf("Unit too large to encrypt.\n"); exit(1); }
	umodexp(unit, exp, mod, result, bits);
}
