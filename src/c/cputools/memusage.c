#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "memusage.h"

#define MAX 1024
#define PATH_SIZE 128
#define NUMBER_SIZE 64

static const unsigned long ERROR = -1ul;


/**
  * @function: 得到字符数组中第一次出现数字的数组下标
  * @return  : 第一次出现数字的数组下标,如果没有数字，返回-1
  * @param   : char *buf 字符数组
  * 
  **/
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
    return ERROR;
}

/**
 * @function: 得到机器的总内存
 * @return    机器总内存（单位kb）   
 * 
 **/
unsigned long GetMemTotal()
{
    FILE *fp;
    char buf[MAX];
    int numPosition = 0;
    /* 打开/proc/meminfo */
    if (!(fp = fopen("/proc/meminfo", "r")))
    {
        printf("Error in Function GetMemTotal: failed to open /proc/meminfo");
        fclose(fp);
        return(ERROR);
    }
    /* 读出/proc/meminfo的第一行内容*/
    if (!fgets(buf, MAX, fp))
    {
        printf("Error in Function GetMemTotal: failed to read /proc/meminfo");
        fclose(fp);
        return(ERROR);
    }
    fclose(fp);

    numPosition = getNumPosition(buf);

    return (unsigned long)atoll(buf + numPosition);
}

/**
 * @funciton: 获得进程占用的物理内存大小(单位KB)
 * @return    进程占用的物理内存大小（单位Kb）
 * @param     int pid 进程号
 * */

unsigned long GetProcessMemTotal(int pid)
{
    FILE *fp;
    char path[PATH_SIZE];
    char buf[MAX];
    int numPosition;
    unsigned long ProcessMemTotal = 0;
    sprintf(path, "/proc/%d/status", pid);

    /* 打开/proc/<pid>/status */
    if (!(fp = fopen(path, "r")))
    {
        printf("Error in Function GetMemTotal: failed to open /proc/meminfo");
        fclose(fp);
        return(ERROR);
    }
    /* 从/proc/<pid>/status中寻找 VmRSS: 行*/
    while (fgets(buf, MAX, fp))
    {
        if (!strncmp(buf, "VmRSS:", 6))
        {
            numPosition = getNumPosition(buf);
            /*将VmRSS: xxxxkb 中的物理内存提取，转成unsigned long类型*/
            ProcessMemTotal = (unsigned long)atoll(buf + numPosition);
            break;
        }
    }
    fclose(fp);
    
    /* 没有读到进程实际占用内存，发生错误，返回-1 */
    if (ProcessMemTotal == 0)
    {
        printf("Error in Function GetMemTotal: The content read from  /proc/%d/status error\n", pid);
        return(ERROR);
    }
    return ProcessMemTotal;
}
/**
  * @function: 根据传入的进程号获得该进程的内存使用率
  * @retrun: 进程内存使用率
  * 
  * @param int pid : 进程号
  * 
**/
float GetProcessMemUsage(int pid)
{
    unsigned long memTotal;
    unsigned long processMemTotal;
    float processMemUsage = 0;

    /* 得到机器总内存*/
    memTotal = GetMemTotal();
    if(memTotal == ERROR){
        return -1;
    }

    /*得到进程占用物理内存*/
    if((processMemTotal = GetProcessMemTotal(pid)) == ERROR)
    {
        return -1;
    }

    /*计算得到内存使用率*/
    processMemUsage = (processMemTotal * 100.0) / memTotal;

    //printf("pid: %d MemUsage:%f%%\n", pid, processMemUsage);
    return processMemUsage;
}
