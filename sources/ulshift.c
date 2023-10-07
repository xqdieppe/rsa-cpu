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

void ulshift(unsigned int *unit, unsigned int *result, uint64_t lshift, size_t bits) {
	size_t skip = lshift / 16;
	size_t shift = lshift % 16;
	size_t s = bits / 16 - skip;
	uint64_t r = 0;

	for (size_t i = 0; i < s; i++) {
		uint64_t tmp = ((uint16_t *)unit)[i];
		((uint16_t *)result)[skip + i] = (((uint16_t) tmp) << shift) | r;
		r = (tmp >> (16 - shift));
	}
}
