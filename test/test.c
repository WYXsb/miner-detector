#include<stdio.h>
#include<fcntl.h>

int main()
{
    char buf[32] = {0};
    FILE *file = NULL;
    file = fopen("/etc/passwd","r");

    if(0 >= fread(buf,1,31,file))
        return 0;
    
    printf("buf:%s\n",buf);
    fclose(file);
    
    return 0;
}