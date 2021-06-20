#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>


int main(){

    struct flock fl;
    fl.l_type=F_RDLCK;
    fl.l_whence=SEEK_SET;
    fl.l_start=0;
    fl.l_len=0;
    fl.l_pid=getpid();

    char buf[10];
    int fd=open("test.txt",O_RDWR);
    printf("Now starting to read");
    fcntl(fd,F_SETLKW,&fl);
    getchar();
    read(fd,buf,10);
    fl.l_type=F_UNLCK;
    write(1,buf,10);
    fcntl(fd,F_SETLK,&fl);
    return 0;
}


