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
    const char buf[20];

    int ret=fork();
    if(!ret){
	close(fd[1]);
         read(fd[0],buf,sizeof(buf));
        printf("%s",buf);
    }
    else{
	close(fd[0]);
    write(fd[1],"From parrent ",20);         
   
    
    }
   
    return 0;
}
