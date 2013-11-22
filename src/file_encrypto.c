#include "stdio.h"
#include "stdlib.h"
#include "xxtea.h"

#define FILE_LEN 1024*1024*10
#define KEY "123456"

int main(int argc, char *argv[])
{
    FILE *file;
    char* inPath = argv[1];
    char* outPath = argv[2];
    unsigned char* fileData = malloc(FILE_LEN);

    file = fopen(inPath, "rb");
    unsigned long num = fread(fileData, 1, FILE_LEN, file);
    fclose(file);

    unsigned int dataLen = 0;
    unsigned char* data = xxtea_encrypt(fileData, num, (unsigned char*)KEY, 32, &dataLen);

    file = fopen(outPath, "web+");
    fwrite(data, 1, dataLen, file);
    fclose(file);
    
    return 0;
}
