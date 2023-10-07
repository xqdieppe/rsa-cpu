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

void urshift(uint32_t *unit, uint32_t *result, size_t rshift, size_t bits) {
	size_t skip = rshift / 16;
	size_t shift = rshift % 16;
	size_t s = bits / 16 - skip;
	uint32_t r = 0;
	
	for (int64_t i = s - skip - 1; i > -1; i--) {
		uint64_t tmp = ((uint16_t *)unit)[i + skip];
		((uint16_t *)result)[i] = (((uint16_t) tmp) >> shift) | r;
		r = (tmp << (16 - shift));
	}
}
