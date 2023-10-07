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

void umodinv(uint32_t *a, uint32_t *mod, uint32_t *result, size_t bits) {
	u(pgcd, bits);
	int8_t su_ = 1; u(u_, bits);
	int8_t sv_ = 1; u(v_, bits);
	uegcd(a, mod, pgcd, &su_, u_, &sv_, v_, bits);
	u(tmpdiv, bits); udivmod(u_, mod, tmpdiv, result, bits);
}
