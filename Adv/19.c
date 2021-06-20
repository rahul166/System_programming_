#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

    	char *file = "fifonod";
	mknod(file, __S_IFIFO | 0666, 0);// mknod is used for block or chracter special files.

	char *file1 = "fifomkf";
	mkfifo(file1, 0666);
}

