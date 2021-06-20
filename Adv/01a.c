#include<stdio.h>
#include <fcntl.h>
#include <sys/time.h>

int main(){

// struct itimerval told;
struct itimerval t;
t.it_interval.tv_sec=10;
t.it_interval.tv_usec=10;
t.it_value.tv_sec=10;
t.it_value.tv_usec=10;

setitimer(ITIMER_REAL,&t,NULL);
	while(1){}
	return 0;
}

