#include <time.h>
#include <sys/resource.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{	
	// int pid=getpid();
	struct rlimit r;
	if(getrlimit(RLIMIT_CPU,&r)==-1){return 0;}
	printf("%f\n",(double)r.rlim_cur);
	printf("%f\n",(double)r.rlim_max);
	return 0;
}
