#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>

int PORTNO=6001;
int main(){
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in ds;
    ds.sin_family=AF_INET;
    ds.sin_addr.s_addr=INADDR_ANY;
    ds.sin_port=htons(PORTNO);

   if(bind(sfd,(struct sockaddr*)&ds,sizeof(ds))==-1) perror("BIND");
    if(listen(sfd,3)==-1){perror("Listen");}
    while(1){
        int afd=accept(sfd,(struct sockaddr*)NULL,NULL);
        if(afd==-1){perror("Connect");}
        pid_t pid=fork();
        if(pid==0){
        char buf[20];
        int ret=read(afd,&buf,20);
        printf("%s \n",buf);}
        else{
        write(afd,"Hello from server",20);
        close(afd);}
    }
    return 0;
}
