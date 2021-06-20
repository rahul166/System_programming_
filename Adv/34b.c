#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>


void client_handler(int *afd){
        char buf[20];
        int ret=read(afd,&buf,20);
        printf("%s \n",buf);
    write(afd,"Hello user",sizeof("Hello user"));
}
int PORTNO=6003;
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
    pthread_t th;
    if(pthread_create(&th, NULL, (void*)client_handler, (void*)&afd)!=0) perror("Thread creation");
    }
    close(sfd);
    return 0;
}
