//Zombie state when child dies before parrent

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>



int main(){
    int fd;
    fd=open("Fork.txt",O_RDWR | O_CREAT | O_TRUNC);
    int cpid=fork();
    if(cpid==0){
        char buf[11]="From child";
        write(fd,buf,sizeof(buf));
    }
    else{
        char buf[12]="From parrent";
        write(fd,buf,sizeof(buf));
    }
 
    return 0;
}