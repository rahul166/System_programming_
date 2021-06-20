#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    fd=open("test.txt",O_CREAT | O_EXCL);
    if(fd==-1){
        printf("Already there");
    }
    return 0;
}



