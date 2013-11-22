CFLAGS = -g
file_encrypto:file_encrypto.o xxtea/xxtea.o
	gcc -o $@ file_encrypto.o xxtea/xxtea.o

#file_decrypto:file_decrypto.o xxtea/xxtea.o
#	gcc -o $@ file_decrypto.o xxtea/xxtea.o

file_enctypto.o:file_enctypto.c
	gcc -o $@ -c $^

file_dectypto.o:file_dectypto.c
	gcc -o $@ -c $^

xxtea/xxtea/xxtea.o:xxtea/xxtea.c xxtea/xxtea.h
	gcc $(CFLAGS) -c $<
