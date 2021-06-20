#include<sched.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
    // int pid=getpid();
   int mask= sched_getscheduler(0);
    printf("%d \n",mask);
    struct sched_param sp;
    if(sched_setscheduler(0,SCHED_RR,&sp)==0){perror("error");}
  
return 0;
}

