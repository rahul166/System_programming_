#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/select.h>



int main(int argc, char const *argv[])
{
	int fd;
	char buf[20];
    fd_set fds;
    struct timeval tv;
	while(1)
	{		
		fd = open(argv[1], O_RDONLY);
        FD_SET(fd,&fds);
        tv.tv_sec=10;
        int ret=select(fd+1,&fds,NULL,NULL,&tv);
        if(ret==-1)perror("Select");
        else if(ret) {
            int sz=read(fd,&buf,sizeof(buf));
            write(1,&buf,sz);
            break;
            }
        else {printf("data was not on time");break;}
		// read(fd, buf, sizeof(buf));
		// write(1, buf, strlen(buf));
		close(fd);
		
	}
}
