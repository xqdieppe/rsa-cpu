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

uint64_t ursakeygen_rand_prime_size(size_t size) {
	size_t s = size / 64;
	return ((rand() % (s + 1)) + 0) * 64;  
}

void ursakeygen(uint32_t *e, uint32_t *d, uint32_t *n, size_t keysize, size_t bits) {
	u(zero, bits);
	size_t rand_prime_size = ursakeygen_rand_prime_size(keysize / 4);
	u(p, bits * 2); upseudoprime(p, keysize / 2 + rand_prime_size, (keysize / 2 + rand_prime_size) * 2);
	u(q, bits); upseudoprime(q, keysize / 2 - rand_prime_size, bits);
	umul(p, q, n, bits);
	u(phi, bits); uphi(p, q, phi, bits);
	u(clear, bits); u(encrypted, bits); u(decrypted, bits);

	do {
		upseudoprime(e, keysize / 4, bits / 2);
		umodinv(e, phi, d, bits);
		
		urand(clear, bits / 4);
		uassign(encrypted, zero, bits);
		uassign(decrypted, zero, bits);
		
		umodexp(clear, e, n, encrypted, bits);
		umodexp(encrypted, d, n, decrypted, bits);
	} while (!ueq(clear, decrypted, bits));
}
