CFLAGS = -g

debug/file_encrypto:debug/file_encrypto.o debug/xxtea.o
	gcc -o $@ $^

debug/file_encrypto.o:src/file_encrypto.c
	gcc $(CFLAGS) -o $@ -c $<

debug/xxtea.o:src/xxtea.c src/xxtea.h
	gcc $(CFLAGS) -o $@ -c $<

clean :
	rm debug/file_encrypto debug/file_encrypto.o debug/xxtea.o
