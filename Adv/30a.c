#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>
#include<string.h>
int main(){
    key_t key=ftok("",67);
    int shmid=shmget(key,1024,IPC_CREAT | 0744);
    char *data;
    data=(char*) shmat(shmid,(void*)0,0);
    printf("Enter Data \n");
    // scanf("%s",&data);
    gets(data);
    shmdt(data);
    return 0;
}

