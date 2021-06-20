#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

int fd;
int main(){
fd=open ("test",O_RDWR);
if(fd==-1){
    fd=creat("test",S_IRWXU);
    printf("%d",fd);
}
return 0;
}
