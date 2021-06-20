#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>


    /**
     * I created record.txt manually
     * My code is expecting it to be like this
    1 2  
    3 4
    5 6

    this numbers can be anything between 0 to 9,each record is of 3 bytes 
    **/




int main(){

    struct flock fl;
    fl.l_type=F_RDLCK;
    fl.l_whence=SEEK_SET;
    fl.l_pid=getpid();

    int n;
    printf("Which record you want to read\n");
    scanf("%d",&n);
    if(n==1){
        fl.l_start=0;   
        fl.l_len=2;
    }
    else if(n==2){
        fl.l_start=4;   
        fl.l_len=2;
    }

    else if(n==3){
        fl.l_start=8;   
        fl.l_len=2;
    }
    char buf[10];
    int fd=open("record.txt",O_RDWR);

    if(fd==-1) perror("error"); 
    fcntl(fd,F_SETLKW,&fl);
    printf("press enter\n");
    getchar();
    getchar();
    lseek(fd,fl.l_start+2,SEEK_SET);
    int ret=read(fd,buf,sizeof(buf));
    //  int digit=(int)buf[0];
    printf("%d Record is %c",n,buf[0]);
    fl.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&fl);
    return 0;
}


