#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>

int main(){
    int fd;
    fd=open("test.txt",O_CREAT | O_WRONLY);
    int  ret= fcntl(fd,F_GETFL);
    int unmask=ret & O_ACCMODE;
    if(unmask==1)
    printf("%s","O_WRONLY");
    else if(unmask==1)
    {
        printf("%s","O_RDONLY");
    }
    
}


