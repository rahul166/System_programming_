#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int fd=open("seek.txt",O_RDWR);
    //11 b using dup2
    int nwfd=dup2(fd,10);
        printf("new FD :%d , OLD fd :%d \n Using dup2",nwfd,fd);

    return 0;
}


