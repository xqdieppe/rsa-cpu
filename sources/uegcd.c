#include "rsa-cpu.h"

/*
def sub(sx, x, sy, y):
    if (sx == -1 and sy == -1):
        if abs(x) >= abs(y):
            return -1, abs((abs(x) - abs(y)))
        else:
            return 1, abs((abs(y) - abs(x)))

    if (sx == 1 and sy == 1):
        if abs(x) >= abs(y):
            return 1, abs(abs(x) - abs(y))
        else:
            return -1, abs(abs(y) - abs(x))
    
    if (sx == 1 and sy == -1):
        return 1, abs(abs(x) + abs(y))
    
    if (sx == -1 and sy == 1):
        if abs(x) >= abs(y):
            return -1, abs(abs(x) + abs(y))
        else:
            return -1, abs(abs(y) + abs(x))
*/

void uegcdsub(int8_t sunit0, uint32_t *unit0, int8_t sunit1, uint32_t *unit1, uint8_t *sresult, uint32_t *result, size_t bits) {
	if (sunit0 == -1 && sunit1 == -1) {
		if (usupeq(unit0, unit1, bits)) {
			*sresult = -1;
			usub(unit0, unit1, result, bits);
		} else {
			*sresult = 1;
			usub(unit1, unit0, result, bits);
		}
	}
	if (sunit0 == 1 && sunit1 == 1) {
		if (usupeq(unit0, unit1, bits)) {
			*result = 1;
			usub(unit0, unit1, result, bits);
		} else {
			*result = -1;
			usub(unit1, unit0, result, bits);
		}	
	}
	if (sunit0 == 1 && sunit1 == -1) {
		*sresult = 1;
		uadd(unit0, unit1, result, bits);
	}
	if (sunit0 == -1 && sunit1 == 1) {
		*result = -1;
		uadd(unit0, unit1, result, bits);
	}
}


/*

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
