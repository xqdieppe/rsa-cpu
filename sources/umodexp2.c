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

void umodexp(uint32_t *unit, uint32_t *exp, uint32_t *mod, uint32_t *result, size_t bits) {
	u(e, bits); uassign(e, exp, bits); 
	u(one, bits); one[0] = 1; u(two, bits); two[0] = 2;
	u(zero, bits); uassign(result, zero, bits);
	u(b, bits); uassign(b, unit, bits);
	u(div, bits);

	if (ueq(mod, one, bits)) {
		uassign(result, zero, bits);
		return;
	}
	
	u(r, bits); r[0] = 1;
	u(tmpb, bits); udivmod(b, mod, div, tmpb, bits); uassign(b, tmpb, bits);

	while (usup(e, zero, bits)) {
		u(emod2,bits); udivmod(e, two, div, emod2, bits);
	        if (ueq(emod2, one, bits)) {
			u(tmp0, bits); umul(r, b, tmp0, bits);
			udivmod(tmp0, mod, div, r, bits);
		}
		u(tmpb1, bits); uassign(tmpb1, b, bits);
		u(tmp1, bits); umul(b, tmpb1, tmp1, bits);
		udivmod(tmp1, mod, div, b, bits);
		
		u(tmpe, bits); uassign(tmpe, e, bits);
		urshift(tmpe, e, 1, bits);
	}
	uassign(result, r, bits);
	return;
}
