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

void dump_byte(uint8_t byte) {
	printf("%d", (byte & 128) >> 7);
	printf("%d", (byte & 64) >> 6);
	printf("%d", (byte & 32) >> 5);
	printf("%d", (byte & 16) >> 4);
	printf("%d", (byte & 8) >> 3);
	printf("%d", (byte & 4) >> 2);
	printf("%d", (byte & 2) >> 1);
	printf("%d", (byte & 1));
}

void udumpbin(uint32_t *unit, size_t bits) {
	int64_t size = bits / 8;

	for (int64_t i = size - 1; i > -1; i--) {
		dump_byte(((uint8_t *) unit)[i]);
	}
	printf("\n");
}
