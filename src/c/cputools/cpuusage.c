#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memusage.h"
#include "cpuusage.h"

#define MAX 1024
#define PATH_SIZE 128
#define NUMBER_SIZE 64

int GetCpuPartTimes(CpuTotalTime *cpuTotalTime,char *buf)
{
    int buflen = strlen(buf);
    int timescount = 0;

    char timebuf[NUMBER_SIZE];
    int timebuflen = 0;    
    for(int i = 5; i < buflen; i++)
    {
        if(buf[i] < 58 && buf[i] > 47 && timebuflen < 64)
        {
            timebuf[timebuflen++] = buf[i];
        }
        else if(buf[i] == ' ')
        {
            timebuf[timebuflen] = 0;
            cpuTotalTime->times[timescount++] = atolu(timebuf);
            timebuflen = 0;
            if(timescount == 9)
            {
                break;
            }
        }
    }
}

int GetCpuTotalTime(CpuTotalTime *cpuTotalTime)
{
    FILE* fp;
    char buf[MAX];
    if (!(fp = fopen("/proc/stat", "r")))
    {
        printf("Error in Function GetMemTotal: failed to open /proc/meminfo");
        exit(-1);
    }
    if (!fgets(buf, MAX, fp))
    {
        printf("Error in Function GetMemTotal: failed to read /proc/meminfo");
        exit(-1);
    }
}

int main()
{
    
    return 0;
}

