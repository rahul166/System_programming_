#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
union semun {
    int val;
    struct semid_ds *buf;
    unsigned short  *array;
};
int main(){
    union semun arg;
    arg.val=1;

    struct sembuf buf;
    buf.sem_flg=0;
    buf.sem_op=-1;
    buf.sem_num=0;
key_t key;
	key = ftok(".", 'A');
    int semid=semget(key,1,IPC_CREAT| IPC_EXCL | 0774 );
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
    printf("Enter crictical section\n");
    printf("Waiting for lock...\n");
    if(semop(semid,&buf,1)==-1){perror("semop");}
    printf("Inside critical section");
    getchar();
    buf.sem_op=1;
    printf("%d",semid);
    semop(semid,&buf,1);
    semctl(semid,0,IPC_RMID);

}

