#include<fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ulimit.h>


int main(){

	write(1,"Maximum Number of files that can be opened is: ",sizeof("Maximum Number of files that can be opened is: "));
	system("ulimit -n");
	write(1,"Pipe size: ",sizeof("Pipe size: "));
	system("ulimit -p");
	return 0;
}