#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>

unsigned long long rdtsc(){
unsigned long long dst;
__asm__ __volatile__("rdtsc":"=A"(dst));
return dst;

}
int main(){
    long long int start,end;
    start=rdtsc();
    int i=100;
    while(i){getpid();i--;}
    end=rdtsc();
    printf("Time taken = %llu \n",end-start);
    return 0;
    
}



