#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>


int main(){
    int pid;
    pid=fork();
    if(!pid){
        printf("Inside child process... \n");
        printf("Killing %d \n",getppid());
        kill(getppid(),SIGKILL);
        sleep(5);
        printf("Child : %d \n",getpid());
    }
    else{
        printf("From parrent %d",getpid());
        pause();
    }

    return 0;
}
