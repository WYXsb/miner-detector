#include <stdio.h>
#include <string.h>

#include <openssl/sha.h>

#include "sha256.h"
#include "getpath.h"



int sha256str(const char *readstr, unsigned char *md)
{
    if (SHA256((unsigned char*)readstr, strlen(readstr), md) == NULL) {
        printf("sha256 erro\n");
        return -1;
    }    
    return 0;
}

void printf256(unsigned char *md)
{ 
    for (int i = 0; i < 32; i++) {
        printf("%02x", md[i]);
    }
    printf("\n");
}

void printfbuf(unsigned char *buf)
{
    for (int i = 0; i < strlen(buf); i++) {
        printf("%d:%c\n", i, buf[i]);
    }
    printf("\n");
}

int sha256file(const char *filepath, unsigned char *md)
{
    FILE* fp;
    SHA256_CTX ctx;
    char buf[SHA256_DIGEST_LENGTH] = {0};
    /* 打开预加密文件 */
    fp = fopen(filepath, "rb");
    if (fp == NULL) {
        printf("Can't open %s\n", filepath);
        return -1;
    }
    /* 初始化指针 */
    SHA256_Init(&ctx);
    
    int len = 0;
    int t = 0;

    /* 对读取的块数据进行加密更新 */
    while (!feof(fp)) {
        memset(buf, 0, sizeof(buf));
        len = fread(buf, 1, SHA256_DIGEST_LENGTH, fp);
        if (len > 0)
        {
            t += len;

            //若检验文本文件使用"r"代替"rb"，而且会多读到最后一个换行符，和字符串加密之后的不一样，printfbuf可打印读到的文件内容(内容手写一行字符串)发现最后多一个字符
            //printfbuf(buf);

            SHA256_Update(&ctx, buf, len);//加入新的文件块
        }
    }
    
    /* 生成最终的加密哈希 */
    SHA256_Final(md, &ctx);
    fclose(fp);
    return 0;
}

int GetSHA256(char *path,char *pid)
{
    char str[] = "123456789";
    unsigned char md[32];
    
    char rootpath[PATH_SIZE];

    getAbspath(rootpath,path,"2273");
    sha256file(rootpath, md);
    printf256(md);

    return 0;
}

int main()
{
    return 0;
}
