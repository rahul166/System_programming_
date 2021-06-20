#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/sem.h>
#include<sys/stat.h>
#include<fcntl.h>


int main(){

	int id;
	int msqid;
	struct msqid_ds msqid_ds, *buf;
	buf = &msqid_ds;
	scanf("Enter msqid %d\n",&msqid);
	msgctl(msqid, IPC_STAT,buf);
	
	printf("Current permission %d\n",buf->msg_perm.mode);
	
	buf->msg_perm.mode=0774;
	
printf("permission changed to %d\n",buf->msg_perm.mode);
	

return 0;
}
