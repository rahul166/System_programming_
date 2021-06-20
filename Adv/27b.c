#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<string.h>

struct mymsg
{
	long mtype;
	char text[200];
}msg,mrc;
int main(){
    key_t key=ftok('msg_q',67);
	int msgid=msgget(key,IPC_CREAT|0744);

	size_t rcv_nowait=msgrcv(msgid,&mrc,sizeof(mrc.text),4,IPC_NOWAIT);

	printf("%s",mrc.text);


	return 0;


}