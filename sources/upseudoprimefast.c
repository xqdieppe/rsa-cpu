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

void upseudoprimefastcandidate(uint32_t *result, size_t size, size_t bits) {
	#define PRIME_SIZE 64
	u(one, bits); one[0] = 1;
	u(prime, bits); prime[0] = 2;
	size_t nbr_of_primes = size / PRIME_SIZE;
	for (size_t i = 0; i < nbr_of_primes; i++) {
		u(p, bits); upseudoprime(p, PRIME_SIZE, PRIME_SIZE * 2);
		u(tmpprime, bits); umul(prime, p, tmpprime, bits); uassign(prime, tmpprime, bits);
	}
	uadd(prime, one, result, bits);
}

void upseudoprimefast(uint32_t *result, size_t size, size_t bits) {
	do {
		upseudoprimefastcandidate(result, size, bits);
		if (upseudoprime_test_32(result, bits)) return;
	} while (1);
}
