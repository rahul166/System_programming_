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

    int fd[2]; //parrent read child write
    int fd2[2]; //parrent write child read
    pipe(fd);
    pipe(fd2);
    const char wrt[20]="From write end";
    const char buf[20];

    int ret=fork();
    if(!ret){
         read(fd2[0],buf,sizeof(buf));
         close(fd[0]);
        write(fd[1],"From child ",20);
        close(fd[1]);
        printf("%s",buf);
    }
    else{
    write(fd2[1],"From parrent ",20);  
    close(fd[1]);       
   read(fd[0],buf,sizeof(buf));
   close(fd[0]);
    printf("%s",buf);
    }
   
    return 0;
}
