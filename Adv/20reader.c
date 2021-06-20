#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char const *argv[])
{
		char buf[256];
        while(1){
		int fd = open(argv[1], O_RDONLY);
		int sz=read(fd, buf, sizeof(buf));
		write(1, buf, sz);
		close(fd);
        }
	}
