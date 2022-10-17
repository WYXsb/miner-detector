#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#include "getpath.h"

int isaDir(char *buff)
{
    struct stat st;
    stat(buff,&st);
    if (S_ISDIR(st.st_mode))
    {
        //printf("is a dir\n");
        return 1;
    }
    else{
        return 0;
    }
}

int getRootPath(char *rootpath,char *path,char *pid)
{
    char temp[MAX_STRLEN];
    int pathlen = strlen(path);
    if(pathlen == 0)
    {
        printf("Error in function getRootPath: path str is null \n");
        return -1;
    }

    if(path[0] == '/')
    {
        sprintf(rootpath,"/proc/%s/root%s",pid,path);
    }
    else if (path[0] == '.' && path[1] == '/')
    {
        /* code */
        for(int i = 0; i < pathlen; i++)
        {
            temp[i] = path[i+1];
        }
        sprintf(rootpath,"/proc/%s/cwd%s",pid,temp);
    }
    else{
        sprintf(rootpath,"/proc/%s/cwd/%s",pid,path);
    }
    return 0;
}

int getAbspath(char *rootpath,char *path,char *pid)
{
    int pathlen;
    char cwd[MAX_STRLEN];
    char linkpath[MAX_STRLEN];
    char Relativepath[MAX_STRLEN]={0};
    if (path[0] == '/')
    {
        //printf("%s\n", path);
		sprintf(rootpath, "%s", path);
        return isaDir(path);
    } 
    else if (path[0] == '.' && path[1] == '/')
    {
        pathlen = strlen(path);
        for (int i = 0; i < pathlen; i++)
        {
            Relativepath[i] = path[i+1];
        }
        sprintf(cwd, "/proc/%s/cwd", pid);
        readlink(cwd, linkpath, MAX_STRLEN - 1);
        sprintf(rootpath, "%s%s", linkpath,Relativepath);
		//printf("rootpath:%s\nrelvpath:%s\n",rootpath,Relativepath);
        return isaDir(rootpath);

    }
    else
    {
        sprintf(cwd, "/proc/%s/cwd", pid);
        readlink(cwd, linkpath, MAX_STRLEN - 1);
        sprintf(rootpath, "%s/%s", linkpath,path);
        //printf("rootpath:%s\nrelvpath:%s\n",rootpath,path);
        return isaDir(rootpath);
    }
	
}


// int main(int argc, char **argv)
// {
//     char path[MAX_STRLEN] = "./getpath.c";
//     char rootpath[MAX_STRLEN];
//     FILE *fp;
//     if(argc < 2)
//     {
//         printf("Arguements too few!\n");
//     }
//     //getAbspath(rootpath,path,argv[1]);
//     getRootPath(rootpath,path,argv[1]);
//     printf("%s\n",rootpath);
//     fp = fopen(rootpath,"r");
//     return 0;
// }