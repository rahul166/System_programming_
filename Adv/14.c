#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

    int fd[2];
    pipe(fd);
    const char wrt[20]="From write end";
    write(fd[1],"From write end",20);
    const char buf[20];
    read(fd[0],buf,sizeof(buf));
    printf("%s",buf);
    return 0;
}
