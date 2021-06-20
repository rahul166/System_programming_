#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
    int fd=open("seek.txt",O_RDWR);
    int nwfd=fcntl(fd,F_DUPFD);
    if(nwfd==-1) perror("Error");
    printf("new FD :%d , OLD fd :%d \n Using fcntl",nwfd,fd);

    return 0;
}


