make re
./rsa-cpu --mode keygen --size 512 --directory keys/512-bits
./rsa-cpu --mode encrypt --pubkey keys/512-bits/pubkey.rsa --message '[TEST] ENCRYPT / DECRYPT : OK' --file out.bin
./rsa-cpu --mode decrypt --privkey keys/512-bits/privkey.rsa --file out.bin
rm out.bin
