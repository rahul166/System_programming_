#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>

int fd;
int main(){
fd=open ("hd.txt",O_CREAT);
link("hd.txt","hardlink.txt");
return 0;
}
