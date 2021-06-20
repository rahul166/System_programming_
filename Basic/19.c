#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(){
//     struct timeval endtv;
//     struct timeval start;
//     gettimeofday(&start,NULL);

//     getpid();

//     gettimeofday(&endtv,NULL);

//     int elap=(endtv.tv_sec-start.tv_sec);

    // printf("It tool %s seconds to execute getpid()",ctime(&elap));
    clock_t before;
    clock_t after;
    before=clock();
    getpid();
    after=clock();
    double sec=((double)(after-before)/CLOCKS_PER_SEC);
    printf("%f",sec);
    return 0;
}


