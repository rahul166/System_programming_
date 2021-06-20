#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sched.h>

int main(){
    int mx=sched_get_priority_max(SCHED_RR);
    int mn=sched_get_priority_min(SCHED_RR);
    
    printf("MAX- %d \n MIN-%d",mx,mn);
    return 0;
}
