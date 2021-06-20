#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Fork-->>>>>\n");
    int cpid=fork();
    if(cpid!=0){
        printf("child process id %d \n",cpid);
        printf("Main process id %d",getpid());
    }


    return 0;
}


