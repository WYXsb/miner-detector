#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memusage.h"
#include "cpuusage.h"
#include <unistd.h>


#define MAX 1024
#define PATH_SIZE 128
#define NUMBER_SIZE 64

static const int ERROR = -1;

/**
 * @function:
 * 
 * */

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
            cpuTotalTime->times[timescount++] = (unsigned long)atoll(timebuf);
            timebuflen = 0;
            if (timescount == 9)
            {
                break;
            }
        }
    }
}

/**
 * @function: 得到机器启动到现在cpu运行的总节拍数
 * @return    函数执行正常与否，正常返回0，出现异常返回ERROR
 * @param     CpuTotalTime *cpuTotalTime 存储cpu各个类型的节拍的结构体指针
 * 
 * */
int GetCpuTotalTime(CpuTotalTime *cpuTotalTime)
{
    FILE *fp;
    char buf[MAX];
    /*打开/proc/stat*/
    if (!(fp = fopen("/proc/stat", "r")))
    {
        printf("Error in Function GetMemTotal: failed to open /proc/meminfo");
        fclose(fp);
        return(-1);
    }
    /* 读取第一行内容，cpu */
    if (!fgets(buf, MAX, fp))
    {
        printf("Error in Function GetMemTotal: failed to read /proc/meminfo");
        fclose(fp);
        return(-1);
    }
    fclose(fp);
    GetCpuPartTimes(cpuTotalTime, buf);
    cpuTotalTime->timesum = 0;
    for (int i = 0; i < 9; i++)
    {
        cpuTotalTime->timesum += cpuTotalTime->times[i];
    }

    return 0;
}
/**
 * @function: 得到进程占用的cpu节拍数
 * @return  : 函数执行正常与否，正常返回0，出现异常返回ERROR
 * @param   CpuProcessTime *cpuProcessTime 存储进程占用的cpu节拍数
 * @param   char * buf 存放进程占用cpu节拍数的字符数组
 * 
 **/
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
                cpuProcessTime->times[timecount - 14] = (unsigned long)atoll(timebuf);

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
        fclose(fp);
        return(-1);
    }

    if (!fgets(buf, MAX, fp))
    {
        printf("Error in Function GetCpuProcessTime: failed to read /proc/%d/stat", pid);
        fclose(fp);
        return(-1);
    }
    fclose(fp);

    GetCpuProcessPartTime(cpuProcessTime,buf);
    cpuProcessTime->timesum = 0;
    for(int i = 0; i < 4; i++)
    {
        cpuProcessTime->timesum += cpuProcessTime->times[i];
        
    }
    return 0;
}



float GetProcessCpuUsage(int pid)
{
    
    int cpunum = sysconf(_SC_NPROCESSORS_CONF);
    CpuProcessTime cpuProcessTime1,cpuProcessTime2;
    CpuTotalTime cpuTotalTime1,cpuTotalTime2;
    float cpuUsage = 0;


    if(GetCpuTotalTime(&cpuTotalTime1) == ERROR)
    {
        return ERROR;
    }
    
    if(GetCpuProcessTime(&cpuProcessTime1, pid) == ERROR)
    {
        return ERROR;
    }
    
    usleep(100000);
    
    if(GetCpuTotalTime(&cpuTotalTime2) == ERROR)
    {
        return ERROR;
    }
    if(GetCpuProcessTime(&cpuProcessTime2, pid) == ERROR)
    {
        return ERROR;
    }

    if(cpuTotalTime2.timesum - cpuTotalTime1.timesum == 0)
    {
        return 0;
    }
    cpuUsage = (cpuProcessTime2.timesum - cpuProcessTime1.timesum) * 100.0 * cpunum /(cpuTotalTime2.timesum - cpuTotalTime1.timesum) ;
    //printf("%lu %lu ",cpuProcessTime2.timesum - cpuProcessTime1.timesum,cpuTotalTime2.timesum - cpuTotalTime1.timesum);
    //printf("pid: %d cpuUsage:%f%%\n",pid,cpuUsage);
    return cpuUsage;
}
