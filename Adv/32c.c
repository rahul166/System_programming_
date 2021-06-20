/**
This ticket number program using semaphore(used for protecting sim acceess of shared memory) and shared memory
This is counting semaphore question 
Run 32a.c to intialize/creat shared memory with some ticket number
**/


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
//#include<iostream>
//#include<sstream>
#include <sys/shm.h>
#include <errno.h>
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};
int main(){
    union semun arg;
    arg.val=2;
key_t key =ftok("",'A');
    struct sembuf buf;
    buf.sem_flg=0;
    buf.sem_op=-1;
    buf.sem_num=0;
    int semid=semget(key,1,IPC_CREAT | 0774 );
     if(semid==-1){

	if(errno == EEXIST)
		{
			// semaphore already exist opening it
			if((semid = semget(key, 1, 0)) == -1)
				perror("semget");
		}
else{perror("OTHER");}
	}
	else
	{
	
		arg.val = 2;
		if(semctl(semid, buf.sem_num, SETVAL, arg) == -1)
			perror("semctl");
	}
    key_t keys=ftok("",67);
    int shmid=shmget(keys,1024,0);
    char *data;
    data=(char*) shmat(shmid,(void*)0,0);
    printf("%s\n",data);

    printf("Want to book ???  Current ticket number is %s \n",data);
    getchar();
    semop(semid,&buf,1);
    int temp=atoi(data);
	temp++;
	sprintf(data,"%d",temp);
	printf("Ticket booked your ticket number is %s Press enter \n",data);    
shmdt(data);
    
    getchar();
    buf.sem_op=1;
    semop(semid,&buf,1);
    // printf("%d",t);
semctl(semid,0,IPC_RMID);
    return 0;
}
