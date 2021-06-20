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
#include<sys/time.h>
void sig_hand(int num){
    if(num==SIGVTALRM)
    printf("Alarm !!!!!!");
}

int main(){
    signal(SIGVTALRM,(__sighandler_t)sig_hand);
    struct itimerval t;
t.it_interval.tv_sec=5;
t.it_interval.tv_usec=0;
t.it_value.tv_sec=5;
t.it_value.tv_usec=0;

setitimer(ITIMER_VIRTUAL,&t,NULL);

    while(1){}  

    return 0;
}
