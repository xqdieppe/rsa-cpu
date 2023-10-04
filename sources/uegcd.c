#include "rsa-cpu.h"

/*
def egcd(a, b):
    lastremainder, remainder = abs(a), abs(b)
    x, lastx, y, lasty = 0, 1, 1, 0
    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
        x, lastx = lastx - quotient*x, x
        y, lasty = lasty - quotient*y, y
    return lastremainder, lastx * (-1 if a < 0 else 1), lasty * (-1 if b < 0 else 1)*/

void uegcd(uint32_t *a, uint32_t *b, uint32_t *pgcd, uint32_t *u_, uint32_t *v_, size_t bits) {
	u(lastreminder, bits); uassign(lastreminder, a, bits);
	u(reminder, bits); uassign(reminder, b, bits);
	u(zero, bits);
	u(one, bits); one[0] = 1;
	u(x, bits); u(lasty, bits);
	u(lastx, bits); uassign(lastx, one, bits);
	u(y, bits); uassign(y, one, bits);

	while (!ueq(reminder, zero, bits)) {
		printf("OK\n");
		uassign(lastreminder, reminder, bits);
		u(tmpdiv, bits); u(tmpmod, bits); udivmod(lastreminder, reminder, tmpdiv, tmpmod, bits);
		u(quotient, bits); uassign(quotient, tmpdiv, bits);
		uassign(reminder, tmpmod, bits);

		uassign(lastx, x, bits);
		u(tmpmul, bits); umul(quotient, x, tmpmul, bits);
		u(tmpsub, bits); usub(lastx, tmpmul, tmpsub, bits);
		uassign(x, tmpsub, bits);

		uassign(lasty, y, bits);
		u(tmpmul1, bits); umul(quotient, y, tmpmul1, bits);
		u(tmpsub1, bits); usub(lasty, tmpmul1, tmpsub1, bits);
		uassign(y, tmpsub1, bits);
	}
	uassign(pgcd, lastreminder, bits);
	uassign(u_, lastx, bits);
	uassign(v_, lasty, bits);
}
