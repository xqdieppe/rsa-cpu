#include "rsa-cpu.h"

#define PUBKEY "pubkey.rsa"
#define PRIVKEY "privkey.rsa"

void keygen(char *dirname, size_t keysize) {
	int m = mkdir(dirname, 0777);
	
	int pub_filename_size = strlen(dirname) + strlen(PUBKEY) + 2;
	char pub_filename[pub_filename_size];
	memset(pub_filename, 0, pub_filename_size);
	strcat(pub_filename, dirname); strcat(pub_filename, "/"); strcat(pub_filename, PUBKEY);
	
	int priv_filename_size = strlen(dirname) + strlen(PRIVKEY) + 2;
	char priv_filename[priv_filename_size];
	memset(priv_filename, 0, priv_filename_size);
	strcat(priv_filename, dirname); strcat(priv_filename, "/"); strcat(priv_filename, PRIVKEY);

	size_t bits = keysize * 2;
	u(e, bits); u(d, bits); u(n, bits);
	ursakeygen(e, d, n, keysize, bits);
	ursaexportpubkey(e, n, keysize, pub_filename);
	ursaexportprivkey(d, n, keysize, priv_filename);
}
