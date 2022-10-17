

int sha256str(const char *readstr, unsigned char *md);

void printf256(unsigned char *md);

void printfbuf(unsigned char *buf);

int sha256file(const char *filepath, unsigned char *md);

int GetSHA256(char *path,int pid);