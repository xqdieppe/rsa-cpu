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

void usub(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	int64_t tmp = 0;
	uint32_t r = 0;
	size_t s = bits / 32;

	for (size_t i = 0; i < s; i++) {
		tmp = unit0[i]; tmp -= unit1[i]; tmp -= r;
		result[i] = (tmp < 0) ? (tmp + 0xffffffff + 1) : tmp;
		r = (tmp < 0) ? 1 : 0;
	}
}
