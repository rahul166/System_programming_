//check man 2 stat

//10 check man leseek

#include<sys/types.h>
#include<sys/stat.h>
#include<time.h>
#include<stdio.h>
int main(int argc,char *arg[]){
    struct stat st;
    stat(arg[1],&st);
    // st.st_ino;
    printf("Indode number %d \n",(long)st.st_ino);
    printf("Number of hrad links %d \n",(long)st.st_nlink);
    printf("Block size %d \n",(long)st.st_blksize);
    printf("Number of blocks %d \n",(long)st.st_blocks);

    printf("Last access %s \n",ctime(&st.st_atime));
    printf(" Last status changed %s \n",ctime(&st.st_ctime));
    printf(" Last file modification %s \n",ctime(&st.st_mtime));
    // // write()
    return 0;
}



