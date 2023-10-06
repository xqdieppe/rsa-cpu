#include "rsa-cpu.h"

void help(char **argv) {
	printf("usage: ./%s <mode> <...paramters>\n", argv[0]);
}

int main(int argc, char **argv) {
	srand(time(0));

	if (argc < 1) { help(argv); return (1); }
	else if (!strcmp(argv[1], "keygen")) keygen(argv[2], atoi(argv[3]));
	else if (!strcmp(argv[1], "encrypt")) encrypt(argv[2], argv[3], argv[4]);
	else if (!strcmp(argv[1], "decrypt")) decrypt(argv[2], argv[3]);
	else { help(argv); return (1); }
}
