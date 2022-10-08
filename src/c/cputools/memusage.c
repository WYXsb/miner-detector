#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memusage.h"

#define MAX 1024
#define PATH_SIZE 128
#define NUMBER_SIZE 64

unsigned long atolu(char *buf)
{
    int buflen = strlen(buf);
    int sum = 0;
    for (int i = 0; i < buflen; i++)
    {
        if (buf[i] < 58 && buf[i] > 47)
        {
            if (sum > 10 * sum)
            {
                printf("Error in Function atolu(): This number is over the range of unsigned long \n");
                exit(-1);
            }
            else
            {
                sum = sum * 10 + buf[i] - 48;
            }
        }
        else if (buf[i] == '\n' || buf[i] == '\0')
        {
            break;
        }
    }
    return sum;
}

unsigned long GetMemTotal()
{
    FILE *fp;
    char buf[MAX];
    if (!(fp = fopen("/proc/meminfo", "r")))
    {
        printf("Error in Function GetMemTotal: failed to open /proc/meminfo");
        exit(-1);
    }
    if (!fgets(buf, MAX, fp))
    {
        printf("Error in Function GetMemTotal: failed to read /proc/meminfo");
        exit(-1);
    }
    return atolu(buf);
}

unsigned long GetProcessMemTotal(int pid)
{
    FILE *fp;
    char path[PATH_SIZE];
    char buf[MAX];
    unsigned long ProcessMemTotal = 0;
    sprintf(path, "/proc/%d/status", pid);

    if (!(fp = fopen(path, "r")))
    {
        printf("Error in Function GetMemTotal: failed to open /proc/meminfo");
        exit(-1);
    }

    while (fgets(buf, MAX, fp))
    {
        if (!strncmp(buf, "VmRSS:", 6))
        {
            ProcessMemTotal = atolu(buf);
            break;
        }
    }
    if (ProcessMemTotal == 0)
    {
        printf("Error in Function GetMemTotal: The content read from  /proc/%d/status error\n", pid);
        exit(-1);
    }
    return ProcessMemTotal;
}

int GetProcessMemUsage(int pid)
{
    unsigned long memTotal;
    unsigned long processMemTotal;
    float processMemUsage = 0;
    memTotal = GetMemTotal();
    processMemTotal = GetProcessMemTotal(pid);
    processMemUsage = (processMemTotal * 100.0) / memTotal;
    printf("pid: %d MemUsage:%f%%\n", pid, processMemUsage);
    return 0;
}

// int main(int argc, char **argv)
// {
//     int pid;
//     if (argc < 2)
//     {
//         printf("Arguments too few!\n");
//         return -1;
//     }
//     pid = atoi(argv[1]);
//     GetProcessMemUsage(pid);
//     return 0;
// }
