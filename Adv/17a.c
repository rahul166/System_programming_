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
    int pid,fd[2];
    pipe(fd);
    pid=fork();
    if(pid==0){
        close(1);
        dup(fd[1]);
        close(fd[0]);
        execl("/bin/ls","/bin/ls","-l",NULL);
    }
    else{
        close(0);
        dup(fd[0]);
        close(fd[1]);
        execl("/usr/bin/wc","/usr/bin/wc",NULL);

    }

    return 0;
}

