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

void help(char **argv) {
	printf("usage: %s --mode <mode> <...params>\n", argv[0]);
	printf("%s --mode keygen --size <keysize> --directory <dirname>\n", argv[0]);
	printf("%s --mode encrypt --pubkey <pubkey> --message <message> --file <file>\n", argv[0]);
	printf("%s --mode decrypt --privkey <privkey> --file <file>\n", argv[0]);
}

char *get_parameter(int argc, char **argv, char *parameter) {
	for (int i = 0; i < argc; i++) {
		if (!strcmp(argv[i], parameter) && (i + 1) < argc)
			return (argv[i + 1]);
	}
	return (NULL);
}

int keygen_args(int argc, char **argv) {
	char *directory = get_parameter(argc, argv, "--directory");
	char *size = get_parameter(argc, argv, "--size");

	if (size == NULL) { help(argv); return (1); }
	int s = atoi(size);
	if (s < 128 | (s % 32)) { help(argv); return (1); }

	if (directory == NULL)
		{ help(argv); return (1); }
	keygen(directory, s);
	return (0);
}

int encrypt_args(int argc, char **argv) {
	char *pubkey = get_parameter(argc, argv, "--pubkey");
	char *message = get_parameter(argc, argv, "--message");
	char *file = get_parameter(argc, argv, "--file");

	if (pubkey == NULL || file == NULL || message == NULL)
		{ help(argv); return (1); }
	sencrypt(message, pubkey, file);
	return (0);
}

int decrypt_args(int argc, char **argv) {
	char *privkey = get_parameter(argc, argv, "--privkey");
	char *file = get_parameter(argc, argv, "--file");

	if (privkey == NULL || file == NULL)
		{ help(argv); return (1); }
	sdecrypt(privkey, file);
	return (0);
}

int main(int argc, char **argv) {
	srand(time(0));
	char *mode = get_parameter(argc, argv, "--mode");
	if (mode == NULL) { help(argv); return (1); }
	else if (!strcmp(mode, "keygen")) { return (keygen_args(argc, argv)); }
	else if (!strcmp(mode, "encrypt")) { return (encrypt_args(argc, argv)); } 
	else if (!strcmp(mode, "decrypt")) { return (decrypt_args(argc, argv)); }
	else { help(argv); return (1); }
}
