#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>


int main(){
    size_t len;
    const char buf[30];
    int from=open("file1.txt",O_RDONLY); //This should exist beforehand
    len=read(from,buf,sizeof(buf));
    if(len==-1){ perror("Read_error");}
    int fd=open("file2.txt",O_WRONLY | O_CREAT);
    size_t n=write(fd,buf,len);
    if(n==-1){ perror("error");}
    if(n==0){write(2,"n==0",5);}
    return 0;
}



