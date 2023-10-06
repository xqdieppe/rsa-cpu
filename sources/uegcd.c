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


/*
def egcd_main(sx, x, slx, lastx, quotient):
    qx = quotient*abs(x)
    print(sx,x,slx,lastx, qx)
    tmpsx, tmpx = sub(slx, lastx, sx, qx)
    slx, lastx = sx, abs(x)
    sx, x = tmpsx, abs(tmpx)
    return sx, x, slx, lastx;
*/

void uegcdmain(int8_t *sx, uint32_t *x, int8_t *slx, uint32_t *lastx, uint32_t *quotient, size_t bits) {
	int8_t sx_ = *sx; int8_t slx_ = *slx; int8_t tmpsx = 1;
	u(tmpx, bits);
	u(qx, bits); umul(x, quotient, qx, bits);
	uegcdsub(slx_, lastx, sx_, qx, &tmpsx, tmpx, bits);
	*slx = sx_; uassign(lastx, x, bits);
	*sx = tmpsx; uassign(x, tmpx, bits);
}

/*
def egcd(a, b):
    lastremainder, remainder = abs(a), abs(b)
    x, lastx, y, lasty = 0, 1, 1, 0
    sx, slx, sy, sly = 1, 1, 1, 1

    while remainder:
        lastremainder, (quotient, remainder) = remainder, divmod(lastremainder, remainder)
        print (quotient)
        sx, x, slx, lastx = egcd_main(sx, x, slx, lastx, quotient)
        sy, y, sly, lasty = egcd_main(sy, y, sly, lasty, quotient)
    return lastremainder, slx * lastx * (-1 if a < 0 else 1), sly * lasty * (-1 if b < 0 else 1)

*/

void uegcd(uint32_t *a, uint32_t *b, uint32_t *pgcd, int8_t *su_, uint32_t *u_, int8_t *sv_, uint32_t *v_, size_t bits) {
	u(zero, bits); u(one, bits); one[0] = 1;
	udump(a, bits);
	u(lastreminder, bits); uassign(lastreminder, a, bits);
	u(reminder, bits); uassign(reminder, b, bits);
	
	int8_t sx = 1; int8_t slx = 1;
	u(x, bits); uassign(x, zero, bits);
	u(lastx, bits); uassign(lastx, one, bits);

	int8_t sy = 1; int8_t sly = 1;
	u(y, bits); uassign(y, one, bits);
	u(lasty, bits); uassign(lasty, zero, bits);

	while (!ueq(reminder, zero, bits)) {
		u(savereminder, bits); uassign(savereminder, reminder, bits);
		u(quotient, bits); u(tmpreminder, bits);
		udivmod(lastreminder, reminder, quotient, tmpreminder, bits);
		uassign(reminder, tmpreminder, bits);

		uassign(lastreminder, savereminder, bits);

		uegcdmain(&sx, x, &slx, lastx, quotient, bits);
		uegcdmain(&sy, y, &sly, lasty, quotient, bits);
	}
	uassign(pgcd, lastreminder, bits);
	*su_ = slx; uassign(u_, lastx, bits);
	*sv_ = sly; uassign(v_, lasty, bits);
}
