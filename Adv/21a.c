#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int fd;
	char buf[20];
	while(1)
	{		
		fd = open(argv[1], O_RDONLY);
		read(fd, buf, sizeof(buf));
		write(1, buf, strlen(buf));
		close(fd);
		
		fd = open(argv[1], O_RDWR);
		int sz=read(0, buf, sizeof(buf));
		buf[sz]='\0';
		write(fd, buf, strlen(buf));
		close(fd);
	}
}
