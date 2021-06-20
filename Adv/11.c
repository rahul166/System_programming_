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
    newact.sa_handler=SIG_IGN;
    printf("Disabled \n");
    sigaction(SIGINT,&newact,NULL);
    sleep(5);
    newact.sa_handler=SIG_DFL;
    sigaction(SIGINT,&newact,NULL);
    printf("Enabled \n");
    sleep(6);
    return 0;
}

