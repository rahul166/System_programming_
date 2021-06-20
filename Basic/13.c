#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/types.h>

int main(){
    int ret;
    fd_set st;
    struct timeval tm;
    FD_ZERO(&st);
    FD_SET(0,&st);

    tm.tv_sec=10;

    ret=select(1,&st,NULL,NULL,&tm);
    if(ret==-1){
        perror("");
    }
    else if(ret){
        printf("Value is entered within time");
        
        //Something I was trying out when a file is ready in this case stdin we read from it working!!!
        const char buf[20];
        // printf("reading and writing");
        size_t ln= read(0,buf,30);
        if(ln==-1)perror("reading");
        // write(1,buf,ln);
        //End of the////////////////////////////////////////////////////////////////////////////////// 
    }
    else{
        printf("Not on time");
    }
    return 0;
}

