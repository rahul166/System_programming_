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
void sig_hand(int num){
    if(num==SIGFPE)
    printf("Error SIGFPE");
}

int main(){
    signal(SIGFPE,(__sighandler_t)sig_hand);
    kill(getpid(),SIGFPE);


    return 0;
}

