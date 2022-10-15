#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define PATH_SIZE 64
#define MAX_STRLEN 128

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


int main(int argc, char **argv)
{
    char path[PATH_SIZE] = "getpath.c";
    char rootpath[PATH_SIZE];
    if(argc < 2)
    {
        printf("Arguements too few!\n");
    }
    getAbspath(rootpath,path,argv[1]);

    return 0;
}