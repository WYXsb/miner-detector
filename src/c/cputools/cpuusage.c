#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memusage.h"
#include "cpuusage.h"

#define MAX 1024
#define PATH_SIZE 128
#define NUMBER_SIZE 64

int GetCpuPartTimes(CpuTotalTime *cpuTotalTime, char *buf)
{
    int buflen = strlen(buf);
    int timescount = 0;

    char timebuf[NUMBER_SIZE];
    int timebuflen = 0;
    for (int i = 5; i < buflen; i++)
    {
        if (buf[i] < 58 && buf[i] > 47 && timebuflen < 64)
        {
            timebuf[timebuflen++] = buf[i];
        }
        else if (buf[i] == ' ')
        {
            timebuf[timebuflen] = 0;
            cpuTotalTime->times[timescount++] = atolu(timebuf);
            timebuflen = 0;
            if (timescount == 9)
            {
                break;
            }
        }
    }
}

int GetCpuTotalTime(CpuTotalTime *cpuTotalTime)
{
    FILE *fp;
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
    GetCpuPartTimes(cpuTotalTime, buf);
    cpuTotalTime->timesum = 0;
    for (int i = 0; i < 9; i++)
    {
        cpuTotalTime->timesum += cpuTotalTime->times[i];
    }

    return 0;
}

int GetCpuProcessPartTime(CpuProcessTime *cpuProcessTime, char *buf)
{
    char timebuf[NUMBER_SIZE];
    int timebuflen = 0;
    int buflen = strlen(buf);
    int timecount = 0;
    for (int i = 0; i < buflen; i++)
    {
        timebuf[timebuflen++] = buf[i];
        if(buf[i] == ' ')
        {
            timecount++;
            if(timecount >= 14 && timecount < 18)
            {
                cpuProcessTime->times[timecount - 14] = atolu(timebuf);
            }
            else if(timecount == 18)
            {
                break;
            }
            timebuflen = 0; 
        }
    }
}

int GetCpuProcessTime(CpuProcessTime *cpuProcessTime, int pid)
{
    FILE *fp;
    char buf[MAX];
    char path[PATH_SIZE];
    sprintf(path, "/proc/%d/stat", pid);

    if (!(fp = fopen(path, "r")))
    {
        printf("Error in Function GetCpuProcessTime: failed to open /proc/%d/stat", pid);
        exit(-1);
    }

    if (!fgets(buf, MAX, fp))
    {
        printf("Error in Function GetCpuProcessTime: failed to read /proc/%d/stat", pid);
        exit(-1);
    }
    GetCpuProcessPartTime(cpuProcessTime,buf);
    cpuProcessTime->timesum = 0;
    for(int i = 0; i < 4; i++)
    {
        cpuProcessTime->timesum += cpuProcessTime->times[i];
        //printf("%lu\n",cpuProcessTime->times[i]);
    }
    //printf("%lu\n",cpuProcessTime->timesum);
    return 0;
}

int main(int argc, char **argv)
{
    int pid;
    CpuProcessTime cpuProcessTime1,cpuProcessTime2;
    CpuTotalTime cpuTotalTime1,cpuTotalTime2;

    if (argc < 2)
    {
        printf("arguments too few!\n");
        return -1;
    }

    pid = atoi(argv[1]);
    GetCpuTotalTime(&cpuTotalTime);
    GetCpuProcessTime(&cpuProcessTime, pid);
    return 0;
}
