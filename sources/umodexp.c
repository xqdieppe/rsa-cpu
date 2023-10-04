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
	        if (ueq(emod2, one)) {
			u(tmp0, bits); umul(r, b, tmp0, bits);
			udivmod(tmp0, mod, div, r, bits);
		}
		u(tmpb1, bits); uassign(tmpb1, b);
		u(tmp1, bits); umul(b, tmpb1, tmp1, bits);
		udivmod(tmp1, mod, div, b, bits);
		
		u(tmpe, bits); uassign(tmpe, e);
		urshift(tmpe, e, 1, bits);
	}
	uassign(result, r, bits);
	return;
/*
  else
    local r = 1
    b = b % m
    while e > 0 do
      if e % 2 == 1 then
        r = (r*b) % m
      end
      b = (b*b) % m
      e = e >> 1     --use 'e = math.floor(e / 2)' on Lua 5.2 or older
    end
    return r
  end
end
*/
}
