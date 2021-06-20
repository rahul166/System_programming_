#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>



int main(){
    // printf("From this program executing dummy.c");
    // const char var='A';
    // execl("./dummy",&var,(char*) NULL);
    // return 0;
    
    //execl
    // const char path[12]="/home/adbid";
    char *arg1="-Rl";
    char *arg2="/proc";
    execl("/bin/ls","/bin/ls",arg1,arg2,NULL);
     execlp("ls","ls",arg1,arg2,NULL);

    //Pass env variables
    // execle("/bin/ls","/bin/ls",arg1,arg2,NULL);
    
    char *argv[]={"/bin/ls","-Rl","/home",NULL};
    execv("/bin/ls",argv);

    char *argvp[]={"ls","-Rl","/home",NULL};
    execvp("ls",argvp);
    return 0;
}





