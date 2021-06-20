#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc,char *argv[]){
    int fd=open(argv[1],O_RDWR);
    char * buf={"This is 10 by"};
    write(fd,buf,10);
    off_t ret=lseek(fd,10,SEEK_END);
    printf("%d\n",ret);
    write(fd,buf,10);
    return 0;
}

/**
out put of od -c 
0000000   T   h   i   s       i   s       1   0  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   T   h   i   s       i   s       1   0
0000036
 **/
