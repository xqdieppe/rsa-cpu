#include "rsa-cpu.h"

void help(char **argv) {
	printf("usage: %s --mode <mode> <...paramters>\n", argv[0]);
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
