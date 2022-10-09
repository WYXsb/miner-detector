typedef struct cpuTotalTime
{
    unsigned long times[9];
    unsigned long timesum;
    /* data */
}CpuTotalTime;
typedef struct cpuProcessTime
{
    unsigned long times[4];
    unsigned long timesum;
    /* data */
}CpuProcessTime;

int GetCpuPartTimes(CpuTotalTime *cpuTotalTime, char *buf);
int GetCpuTotalTime(CpuTotalTime *cpuTotalTime);
int GetCpuProcessPartTime(CpuProcessTime *cpuProcessTime, char *buf);
int GetCpuProcessTime(CpuProcessTime *cpuProcessTime, int pid);
float GetProcessCpuUsage(int pid);