#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "memusage.h"

#define MAX 1024
#define PATH_SIZE 128
#define NUMBER_SIZE 64

unsigned long atolu(char *buf)
{
    int buflen = strlen(buf);
    unsigned long sum = 0;
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
        else
        {
            break;
        }
    }
    return sum;
}

int getNumPosition(char *buf)
{
    int numPosition;
    int buflen = strlen(buf);
    for (numPosition = 0; numPosition < buflen; numPosition++)
    {
        if (isdigit(buf[numPosition]))
        {
            return numPosition;
        }
    }
}

unsigned long GetMemTotal()
{
    FILE *fp;
    char buf[MAX];
    int numPosition = 0;
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
    numPosition = getNumPosition(buf);
    return atolu(buf + numPosition);
}

unsigned long GetProcessMemTotal(int pid)
{
    FILE *fp;
    char path[PATH_SIZE];
    char buf[MAX];
    int numPosition;
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
            numPosition = getNumPosition(buf);

            ProcessMemTotal = atolu(buf + numPosition);
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

float GetProcessMemUsage(int pid)
{
    unsigned long memTotal;
    unsigned long processMemTotal;
    float processMemUsage = 0;
    memTotal = GetMemTotal();
    processMemTotal = GetProcessMemTotal(pid);
    processMemUsage = (processMemTotal * 100.0) / memTotal;

    printf("pid: %d MemUsage:%f%%\n", pid, processMemUsage);
    return processMemUsage;
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
