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

int main(){
    signal(SIGINT,SIG_IGN);
    printf("SIGINT disabled \n");
    sleep(5);
    printf("SIGINT Enabled");
    signal(SIGINT,SIG_DFL);
    sleep(5);

    return 0;
}

