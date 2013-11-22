#include "stdio.h"
#include "stdlib.h"
#include "xxtea/xxtea.h"

int main(int argc, char *argv[])
{
    FILE *hSource;
    FILE *hDestination;
    unsigned char* pbBuffer;
    unsigned long dwBufferLen = 1024 * 1024 * 30;
    unsigned long dwCount;
    unsigned char key[32] = "3c883f7813a3ee68a74ddcd4a3d24fcc";
    unsigned char *result;

    xxtea_long key_size = sizeof(key);
    unsigned int ret_length;

    if(argv[1] == 0 || argv[2] == 0)
    {
        printf("missing argument !\n");
        return 0;
    }

    unsigned char* szSource = argv[1];
    char* szDestination = argv[2];

    pbBuffer = (unsigned char*)malloc(dwBufferLen);

    // 打开源文件
    hSource = fopen(szSource, "rb");
    // 打开目标文件
    hDestination = fopen(szDestination, "wb+");

    if(hSource == NULL) {printf("open Source File error !\n"); return 0;};
    if(hDestination == NULL) {printf("open Destination File error !\n"); return 0;};

    dwCount = fread(pbBuffer, 1, dwBufferLen, hSource);

    pbBuffer = xxtea_encrypt(pbBuffer, dwCount, key, key_size, &ret_length);

//    result = xxtea_decrypt(result, ret_length, key, key_size, &ret_length);

    fwrite(pbBuffer, 1, ret_length, hDestination);

    // 关闭文件，释放内存
    free(pbBuffer);

    fclose(hSource);
    fclose(hDestination);

    printf("%s is encrypted to %s \n", szSource, szDestination);
    return 0;
}
