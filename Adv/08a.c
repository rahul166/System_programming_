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
    if(num==SIGSEGV)
    printf("Error SIGSEV");
}

int main(){
    signal(SIGSEGV,(__sighandler_t)sig_hand);
    kill(getpid(),SIGSEGV);


    return 0;
}

