#include "rsa-cpu.h"

int main(int argc, char **argv) {
	srand(time(0));

	#define USIZE 256 

	/*
	u(unit0, USIZE); u(unit1, USIZE); u(uresult, USIZE); u(umod, USIZE);
	//memset(unit0, 0xff, 256 / 8); memset(unit1, 0xff, 256 / 8);
	//urand(unit0, USIZE / 2); urand(unit1, USIZE / 4);
	unit0[0]=12; unit1[0]=7;
	udivmod(unit0, unit1, uresult, umod, USIZE);
	udump(unit0, USIZE); udump(unit1, USIZE); udump(uresult, USIZE); udump(umod, USIZE);
	*/

	/*
	u(unit, 128); u(result, 128);
	memset(unit, 0xff, 32 / 8);
	udump(unit, 128);
	ulshift(unit, result, 1, 128);
	udump(result, 128);
	*/

	/*
	u(unit0, 128); u(unit1, 128);
	memset(unit0, 0xff, 32 / 8);
	memset(unit1, 0xfe, 32 / 8);
	udump(unit0, 128); udump(unit1, 128);
	printf("%d\n", usup(unit0, unit1, 128));
	*/

	/*
	u(unit, USIZE); u(exp, USIZE); u(mod, USIZE); u(result, USIZE);
	urand(unit, 64); urand(exp, 32); urand(mod, 64);
	umodexp(unit, exp, mod, result, USIZE);
	udump(unit, USIZE); udump(exp, USIZE); udump(mod, USIZE); udump(result, USIZE);
	*/

	/*
	u(prime, USIZE);
	upseudoprime(prime, USIZE / 2, USIZE);
	udump(prime, USIZE);
	*/

	u(e, USIZE); u(d, USIZE); u(n, USIZE);
	ursakeygen(e, d, n, USIZE / 2, USIZE);
	udump(e, USIZE); udump(d, USIZE); udump(n, USIZE);
	ursaexportpubkey(e, n, USIZE / 2, "keys/pubkey.rsa");
	ursaexportprivkey(d, n, USIZE / 2, "keys/privkey.rsa");
	
	rsa_key_header_t header;
	ursaimportkeyheader(&header, "keys/pubkey.rsa");
	size_t bits = header.modulus_size * 16;
	u(loaded_e, bits); u(loaded_n, bits);
	ursaimportkey(loaded_e, loaded_n, "keys/pubkey.rsa");
	udump(loaded_e, bits);
	udump(loaded_n, bits);

	rsa_key_header_t header_prv;
	ursaimportkeyheader(&header_prv, "keys/privkey.rsa");
	size_t bits_prv = header.modulus_size * 16;
	u(loaded_d, bits_prv); u(loaded_n_prv, bits_prv);
	ursaimportkey(loaded_d, loaded_n_prv, "keys/privkey.rsa");
	udump(loaded_d, bits_prv);
	udump(loaded_n_prv, bits_prv);

	/*
	printf("==============================\n");
	u(clear, bits); urand(clear, bits / 4);
	udump(clear, bits);
	u(encrypted, bits); u(decrypted, bits);
	umodexp(clear, loaded_e, loaded_n, encrypted, bits);
	udump(encrypted, bits);
	umodexp(encrypted, loaded_d, loaded_n_prv, decrypted, bits_prv);
	udump(decrypted, bits);
	printf("==============================\n");
	*/

	//keygen(argv[1], atoi(argv[2]));
	//encrypt(argv[1], argv[2], argv[3]);
	decrypt(argv[1], argv[2]);
	/*
	u(clear, 131072); u(encrypted, 131072); u(decrypted, 131072);
	urand(clear, 128);
	ursarun(clear, encrypted, "mykeys/pubkey.rsa");
	ursarun(encrypted, decrypted, "mykeys/privkey.rsa");
	udump(clear, 512); udump(encrypted, 512); udump(decrypted, 512);
	*/
	/*
	char *line = NULL;
	char *cmd = NULL;
	do {
		line = readline("rsa-cpu$ ");
		if (!line) return (0);
		add_history(line);
		cmd = strtok(line, " ");
	} while (line && !strcmp(line, "exit"));
	*/
}
