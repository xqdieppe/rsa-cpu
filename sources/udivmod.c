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

void udivmod(uint32_t *unit0, uint32_t *unit1, uint32_t *result, uint32_t *mod, size_t bits) {
	u(u0, bits); uassign(u0, unit0, bits); u(block, bits);
	u(zero, bits); uassign(result, zero, bits); uassign(mod, zero, bits);

	for (size_t i = 0; i < bits; i++) {
		u(tmpblock, bits); ulshift(block, tmpblock, 1, bits); uassign(block, tmpblock, bits);
		block[0] |= (u0[bits / 32 - 1]) >> 31;
		u(tmpu0, bits); ulshift(u0, tmpu0, 1, bits); uassign(u0, tmpu0, bits);
		if (usup(unit1, block, bits)) {	
			u(tmpresult, bits); ulshift(result, tmpresult, 1, bits); uassign(result, tmpresult, bits);
		} else {
			u(tmpblock, bits); usub(block, unit1, tmpblock, bits); uassign(block, tmpblock, bits);
			u(tmpresult, bits); ulshift(result, tmpresult, 1, bits); uassign(result, tmpresult, bits);
			result[0] |= 1;
		}
	}
	uassign(mod, block, bits);
}
