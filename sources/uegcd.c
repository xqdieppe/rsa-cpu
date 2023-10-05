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
	*sx = tmpsx; uassign(x, tmpx);
}

void uegcd(uint32_t *a, uint32_t *b, uint32_t *pgcd, uint32_t *u_, uint32_t *v_, size_t bits) {
}
