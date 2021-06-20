#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

//First run 17init.c

int main(){

    struct flock fl;
    fl.l_type=F_WRLCK;
    fl.l_whence=SEEK_SET;
    fl.l_start=0;
    fl.l_len=0;
    fl.l_pid=getpid();
     int fd=open("tic.txt",O_RDWR);
     int t;
    printf("You want to book a ticket \n");
    // // printf("%d",re);
    fcntl(fd,F_SETLKW,&fl);
    if(fd==-1) perror("error");
    printf("press enter \n");
    getchar();
    read(fd,&t,sizeof(int));
    printf("current ticket number %d \n",t);
    t++;
    // sprintf(buf,"%d",ticket);  
    lseek(fd,0,SEEK_SET);
    printf("Ticket is booked->> %d",t);
    write(fd,&t,sizeof(int));
    fl.l_type=F_UNLCK;
    fcntl(fd,F_SETLK,&fl);

    return 0;
}

//FIBo,knapsack,LCS,Subsequence

