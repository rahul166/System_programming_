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
int main(int argc, char const *argv[])
{	
	key_t key=ftok('msg_q',67);
	int msgid=msgget(key,IPC_CREAT|0744);
	// printf("%d\n", msgid);
	// printf("%d\n", key);
	// int msgid=msgget(key,0);
	char buf[20]="My first msg";
	strcpy(msg.text,buf);
	printf("%s\n",msg.text );
	msg.mtype=4;
	msgsnd(msgid,&msg,sizeof(msg.text),0);
}