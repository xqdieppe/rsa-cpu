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

void umul_step(uint32_t *unit0, uint16_t unit1, uint32_t *result, size_t bits) {
	uint64_t tmp = 0;
	uint64_t r = 0;
	size_t s = bits / 16;

	for (size_t i = 0; i < s; i++) {
		tmp = ((uint16_t *)unit0)[i];
	       	tmp *= unit1;
		tmp += r; 
		((uint16_t *)result)[i] = tmp & 0xffff;
		r = tmp >> 16;
	}
}

void umul(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits) {
	size_t s = bits / 16;

	for (size_t i = 0; i < s; i++) {
		u(tmp, bits); u(tmp_shift, bits); u(nresult, bits);

		umul_step(unit0, ((uint16_t *)unit1)[i], tmp, bits);

		ulshift(tmp, tmp_shift, i * 16, bits);
		uadd(result, tmp_shift, nresult, bits);
		uassign(result, nresult, bits);
	}
}
