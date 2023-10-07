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

uint32_t usupeq(uint32_t *unit0, uint32_t *unit1, int64_t bits) {
	int64_t size = bits / 32;

	for (int64_t i = size - 1; i > -1; i--) {
		if (unit0[i] ^ unit1[i]) {
			return (unit0[i] > unit1[i]);
		}
	}
	return (1);
}
