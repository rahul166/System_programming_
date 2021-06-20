#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>


int main(){

    struct flock fl;
    fl.l_type=F_WRLCK;
    fl.l_whence=SEEK_SET;
    fl.l_start=0;
    fl.l_len=0;
    fl.l_pid=getpid();

    int fd=open("test.txt",O_RDWR);
    printf("Now starting to write");
    fcntl(fd,F_SETLKW,&fl);
    getchar();
    write(fd,"Something",10);
    fl.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&fl);
    return 0;
}


