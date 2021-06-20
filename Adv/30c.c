#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
    key_t key = ftok("",67); 
  
    int shmid = shmget(key,1024,IPC_CREAT | 0666); 
  
    char *data = (char*) shmat(shmid,(void*)0,SHM_RDONLY); 
  
    printf("Data is %s\n",data); 

    printf("Detaching now "); 
    shmdt(data);
    return 0;
}

