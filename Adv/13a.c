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
#include<sys/wait.h>
void sig_hand(int num){
    if(num==SIGSTOP)
    printf("Caught SIGSTOP");
}



int main(){
    printf("pid ::: %d\n",getpid());
    signal(SIGSTOP,(__sighandler_t)sig_hand);
    sleep(30);
    return 0;
}

