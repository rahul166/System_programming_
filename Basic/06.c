#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

int main(){
    int fd;
    const char buf[30]; 
    // fd=open(1, O_RDWR);
    size_t rt=read(1,buf,30);
    write(2,buf,rt);
    
return 0;
}
