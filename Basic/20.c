#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
int main(){
    printf("%d",getpriority(PRIO_PROCESS,0));

    nice(4);
    printf("%d",getpriority(PRIO_PROCESS,0));
    return 0;
}

