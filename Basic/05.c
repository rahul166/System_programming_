#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>

int main(){ 
    // int i=5;
    creat("file1.txt",S_IRWXU);
    creat("file2.txt",S_IRWXU);
    creat("file3.txt",S_IRWXU);
    creat("file4.txt",S_IRWXU);
    creat("file5.txt",S_IRWXU);
    while(1){}

    return 0;
}


