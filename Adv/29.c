#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include<string.h>
#include<unistd.h>
int main(){

    key_t key;
    scanf("Enter the key of msg_queue %d",&key);
    int msgid=msgget(key,0);

    msgctl(msgid,IPC_RMID,NULL);
    
    // execlp("ipcs","ipcs","-q",NULL);
    return 0;
}

