#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

//dummy is some executable program 

int main(){
    printf("From this program executing dummy.c");
    const char var='A';
    execl("./dummy",&var,(char*) NULL);
    return 0;
}



