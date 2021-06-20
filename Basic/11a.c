#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int fd=open("seek.txt",O_RDWR);
    //11 a using dup
    int nwfd=dup(fd);
    printf("new FD :%d , OLD fd :%d \n Using dup",nwfd,fd);
    return 0;
}


