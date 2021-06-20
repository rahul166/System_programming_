#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char const *argv[])
{
		char buf[20];
		int fd = open(argv[1], O_RDWR);
		int sz=read(0, buf, sizeof(buf));
		buf[sz]='\0';
		write(fd, buf, sz);
		close(fd);
	
}
