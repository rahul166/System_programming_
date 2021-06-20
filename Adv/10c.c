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
void sig_hand(int num){
    printf("Error");
}

int main(){
    struct sigaction newact;
    newact.sa_handler=sig_hand;
    sigaction(SIGFPE,&newact,NULL);
    kill(getpid(),SIGFPE);


    return 0;
}

