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
    if(num==SIGPROF)
    printf("Alarm !!!!!!");
    else{
    printf("something wrong");
        
    }
}

int main(){
    if(signal(SIGPROF,(__sighandler_t)sig_hand)==SIG_ERR){
        perror("");
    }
    struct itimerval it_val;
	it_val.it_value.tv_sec = 5;
	it_val.it_value.tv_usec = 0;
	it_val.it_interval.tv_sec = 1;
	it_val.it_interval.tv_usec = 0;

setitimer(ITIMER_PROF,&it_val,NULL);

    while(1){}   

    return 0;
}
