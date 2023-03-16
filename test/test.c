#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int fd;
    char buf[32] = {0};
    fd = open("/etc/passwd",O_RDONLY);
    if(fd == -1)
    {
        printf("failed to open /etc/passwd\n");
        return -1;
    }

    printf("success to open fd:%d\n",fd);
    if(11 != read(fd,buf,11))
    {
        printf("failed to read fd:%d\n",fd);
    }
    printf("buf:%s\n",buf);
    close(fd);
    fd = open("/etc/passwd",O_RDONLY);
    if(fd == -1)
    {
        printf("failed to open /etc/passwd\n");
        return -1;
    }

    printf("success to open fd:%d\n",fd);
    if(11 != read(fd,buf,11))
    {
        printf("failed to read fd:%d\n",fd);
    }
    printf("buf:%s\n",buf);
    close(fd);
    return 0;
}