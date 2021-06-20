#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>
 //System calls for soft link and hard link
int main(){
    int fd;
    fd=open ("test.txt",O_CREAT | O_WRONLY );
    // const char str[]="HELLo world";
    symlink("test.txt","soft.txt");
}


