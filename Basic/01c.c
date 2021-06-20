#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>

int main(){
    int ret=mknod("myfifo",__S_IFIFO,3);
    if(ret==-1)perror("Error::");
    else if(ret==0)printf("DONE!!");
    return 0;
}

