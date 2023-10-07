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

#ifndef UNITS_H
#define UNITS_H

#define u(name,bits) \
	uint32_t name[bits / 32]; \
	memset((void *)name, 0, bits / 8);
/*
#define u(name,bits) \
	uint32_t *name = malloc(bits / 8); \
	memset((void *)name, 0, bits / 8);
*/

void sdecrypt(char *privkey, char *encrypted_file);
void sencrypt(char *string, char *pubkey, char *encrypted_file);
void keygen(char *dirname, size_t keysize);
void help(char **argv);
void uadd(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits);
void uassign(uint32_t *unit0, uint32_t *unit1, size_t bits);
void udiv_main(uint32_t *unit0, uint32_t *unit1, uint32_t *result, uint32_t *previous, uint32_t *current, size_t bits);
void udiv(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits);
void udivmod(uint32_t *unit0, uint32_t *unit1, uint32_t *result, uint32_t *mod, size_t bits);
void dump_byte(uint8_t byte);
void udumpbin(uint32_t *unit, size_t bits);
void udump(uint32_t *unit, size_t bits);
void uegcdsub(int8_t sunit0, uint32_t *unit0, int8_t sunit1, uint32_t *unit1, int8_t *sresult, uint32_t *result, size_t bits);
void uegcdmain(int8_t *sx, uint32_t *x, int8_t *slx, uint32_t *lastx, uint32_t *quotient, size_t bits);
void uegcd(uint32_t *a, uint32_t *b, uint32_t *pgcd, int8_t *su_, uint32_t *u_, int8_t *sv_, uint32_t *v_, size_t bits);
uint32_t ueq(uint32_t *unit0, uint32_t *unit1, int64_t bits);
uint32_t uinf(uint32_t *unit0, uint32_t *unit1, int64_t bits);
uint32_t uinfeq(uint32_t *unit0, uint32_t *unit1, int64_t bits);
void ulshift(unsigned int *unit, unsigned int *result, uint64_t lshift, size_t bits);
void umodexp(uint32_t *unit, uint32_t *exp, uint32_t *mod, uint32_t *result, size_t bits);
void umodexp(uint32_t *unit, uint32_t *exp, uint32_t *mod, uint32_t *result, size_t bits);
void umodinv(uint32_t *a, uint32_t *mod, uint32_t *result, size_t bits);
void umul_step(uint32_t *unit0, uint16_t unit1, uint32_t *result, size_t bits);
void umul(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits);
void uphi(uint32_t *p, uint32_t *q, uint32_t *result, size_t bits);
uint32_t upseudoprime_pretest(uint32_t *prime, uint32_t number, size_t bits);
uint32_t upseudoprime_test(uint32_t *prime, size_t bits);
uint8_t upseudoprime_test_32(uint32_t *prime, size_t bits);
void upseudoprime(uint32_t *result, size_t size, size_t bits);
void upseudoprimefastcandidate(uint32_t *result, size_t size, size_t bits);
void upseudoprimefast(uint32_t *result, size_t size, size_t bits);
void urand(unsigned int *unit, size_t size);

uint64_t ursakeygen_rand_prime_size(size_t size);
void ursakeygen(uint32_t *e, uint32_t *d, uint32_t *n, size_t keysize, size_t bits);
void ursarun(uint32_t *unit, uint32_t *result, char *filename);
void urshift(unsigned int *unit, unsigned int *result, size_t rshift, size_t bits);
size_t usize(uint8_t *unit, int64_t bits);
void usub(uint32_t *unit0, uint32_t *unit1, uint32_t *result, size_t bits);
uint32_t usup(uint32_t *unit0, uint32_t *unit1, int64_t bits);
uint32_t usupeq(uint32_t *unit0, uint32_t *unit1, int64_t bits);

#endif
