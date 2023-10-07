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

void uegcdsub(int8_t sunit0, uint32_t *unit0, int8_t sunit1, uint32_t *unit1, int8_t *sresult, uint32_t *result, size_t bits) {
	if (sunit0 == -1 && sunit1 == -1) {
		if (usupeq(unit0, unit1, bits)) {
			*sresult = -1;
			usub(unit0, unit1, result, bits);
		} else {
			*sresult = 1;
			usub(unit1, unit0, result, bits);
		}
	}
	else if (sunit0 == 1 && sunit1 == 1) {
		if (usupeq(unit0, unit1, bits)) {
			*sresult = 1;
			usub(unit0, unit1, result, bits);
		} else {
			*sresult = -1;
			usub(unit1, unit0, result, bits);
		}	
	}
	else if (sunit0 == 1 && sunit1 == -1) {
		*sresult = 1;
		uadd(unit0, unit1, result, bits);
	}
	else if (sunit0 == -1 && sunit1 == 1) {
		*sresult = -1;
		uadd(unit0, unit1, result, bits);
	}
}

void uegcdmain(int8_t *sx, uint32_t *x, int8_t *slx, uint32_t *lastx, uint32_t *quotient, size_t bits) {
	int8_t sx_ = *sx; int8_t slx_ = *slx; int8_t tmpsx = 1;
	u(tmpx, bits);
	u(qx, bits); umul(x, quotient, qx, bits);
	uegcdsub(slx_, lastx, sx_, qx, &tmpsx, tmpx, bits);
	*slx = sx_; uassign(lastx, x, bits);
	*sx = tmpsx; uassign(x, tmpx, bits);
}

void uegcd(uint32_t *a, uint32_t *b, uint32_t *pgcd, int8_t *su_, uint32_t *u_, int8_t *sv_, uint32_t *v_, size_t bits) {
	u(zero, bits); u(one, bits); one[0] = 1;
	u(lastremainder, bits); uassign(lastremainder, a, bits);
	u(remainder, bits); uassign(remainder, b, bits);
	
	int8_t sx = 1; int8_t slx = 1;
	u(x, bits); uassign(x, zero, bits);
	u(lastx, bits); uassign(lastx, one, bits);

	int8_t sy = 1; int8_t sly = 1;
	u(y, bits); uassign(y, one, bits);
	u(lasty, bits); uassign(lasty, zero, bits);

	while (!ueq(remainder, zero, bits)) {
		u(saveremainder, bits); uassign(saveremainder, remainder, bits);
		u(quotient, bits); u(tmpremainder, bits);
		udivmod(lastremainder, remainder, quotient, tmpremainder, bits);
		uassign(remainder, tmpremainder, bits);

		uassign(lastremainder, saveremainder, bits);

		uegcdmain(&sx, x, &slx, lastx, quotient, bits);
		uegcdmain(&sy, y, &sly, lasty, quotient, bits);
	}
	uassign(pgcd, lastremainder, bits);
	*su_ = slx; uassign(u_, lastx, bits);
	*sv_ = sly; uassign(v_, lasty, bits);
}
