#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#include<string.h>

//Intialization code for 32 question
int main(){
    key_t key=ftok("ticket",67);
    int shmid=shmget(key,1024,IPC_CREAT | 0744);
    char *data;
    data=(char*) shmat(shmid,(void*)0,0);
printf("Intialize the ticket Number");
    gets(data);
    shmdt(data);
    return 0;
}
