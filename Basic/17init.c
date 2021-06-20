#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

//This is initialization code for 17th question

int main(){
    int init=0;
    int fd=open("tic.txt",O_RDWR | O_CREAT | O_TRUNC,0644);
    write(fd,&init,sizeof(init));
    close(fd);
    return 0;
}
