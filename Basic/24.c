#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>



int main(){
    int cpid=fork();
    if(cpid==0){
        sleep(60);
    }
    else{
        // printf("Main process id %d",getpid());
        // printf("child process id %d",cpid);
        exit(0);
    }


    return 0;
}



