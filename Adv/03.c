#include <time.h>
#include <sys/resource.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{	
	// int pid=getpid();
	struct rlimit rnew;
	rnew.rlim_cur=10;
	rnew.rlim_max=20;
	if(setrlimit(RLIMIT_CPU,&rnew)==-1){return 0;}
	printf("%lld\n",(long long)rnew.rlim_cur);
	printf("%lld\n",(long long)rnew.rlim_max);
	// while(1){};
	return 0;
}


