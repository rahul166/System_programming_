#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc ,char * arg[]){
    int fd=open(arg[1],O_RDWR);
    char buf[100];
    size_t ret;
    int i=0;
    while((read(fd,&buf[i],1))!=0){
        if(buf[i]=='\n'){
            buf[i]=0;
            i++;
        i=0;
        printf("\n");
        sleep(3);
        // write(1,'\n',1);
        continue;
        }
        printf("%c",buf[i]);
        i++;
        // write(1,buf[i],1);
            }
    close(fd);
}
