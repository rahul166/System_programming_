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
    int pid,fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    pid=fork();
    if(pid==0){
        close(1);
        dup2(fd1[1],1);
        close(fd1[0]);
        execl("/bin/ls","/bin/ls","-l",NULL);
    }
    else{
        int more=fork();
        if(!more){
        close(0),close(1);
        dup2(fd1[0],0);
        dup2(fd2[1],1);
        close(fd1[1]);
        close(fd2[0]);
        execl("/bin/grep","/bin/grep","^d",NULL);
        }
        else{
            close(0);
            dup2(fd2[0],0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("wc","wc",NULL);
        }
    }

    return 0;
}

