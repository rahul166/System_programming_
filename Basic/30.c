#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(){
    int pid;
    pid=fork();
    if(pid==0){
        setsid();
        umask(0);
        printf("This is a deamon process");
        execlp("ls","ls",NULL);
        return 0;
    }   
    else{
        return 0;
    }

    return 0;
}

