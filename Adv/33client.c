#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>

int PORTNO=6003;
int main(){
    int sfd=socket(AF_INET,SOCK_STREAM,0);
    if(sfd==-1)perror("sfd");
    struct sockaddr_in ds;
    ds.sin_family=AF_INET;
    // ds.sin_addr.s_addr=inet_addr("127.0.0.1");
    if(inet_pton(AF_INET, "127.0.0.1", &ds.sin_addr)<=-0){
        perror("inet_pton");
    }
    ds.sin_port=htons(PORTNO);
    // getchar();
   printf("Let's connect\n");
        if(connect(sfd,(struct sockaddr*)&ds,(int)sizeof(ds))==-1) perror("Connection error");
        
        printf("Hi....\n");
        char buf[20]="Message from client";
         char buf_server[20];
        if(write(sfd,&buf,20)==-1)perror("Can't write");
        read(sfd,&buf_server,20);
        // close(cfd);
        printf("%s\n",buf_server);
	//close()	
	
    return 0;
}
