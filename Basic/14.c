#include<sys/types.h>
#include<sys/stat.h>
#include<sys/fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[]){
    struct stat st;
    stat(argv[1],&st);
    int mask=st.st_mode & __S_IFMT;
    if(mask == __S_IFBLK){
        printf("This a block device file");
    }
    else if(mask == __S_IFCHR){
        printf("This a character device device file");
    }
    else if(mask == __S_IFIFO){
        printf("This a FIFO file");
    }
    else if(mask == __S_IFDIR){
        printf("This a directory");
    }
    else if(mask == __S_IFLNK){
        printf("This a soft link");
    }

    else if(mask == __S_IFREG){
        printf("This a Regular file");
    }
    else if(mask == __S_IFSOCK){
        printf("This a socket file");
    }
    else{
        printf("Unknown");
    }
    return 0;
}


