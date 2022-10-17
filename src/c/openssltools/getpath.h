#define PATH_SIZE 64
#define MAX_STRLEN 128

int isaDir(char *buff);

int getAbspath(char *rootpath,char *path,char *pid);

int getRootPath(char *rootpath,char *path,char *pid);