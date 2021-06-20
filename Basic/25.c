#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(){
    int p1,p2,p3;
    p1=fork();
    if(p1==0){
        sleep(10);
    }
    if(p1!=0){
        p2=fork();
        if(p2!=0){
            p3=fork();
            if(p3!=0){
                waitpid(p1,2,NULL); //If we don't do waitpid it will not wait for p1 to get over it will execute the below printf statement
                printf("This is a parrent process %d",getpid());
            }
        }
    }
    return 0;
}


