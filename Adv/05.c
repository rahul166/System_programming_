#include<unistd.h>
#include<stdio.h>

int main(){
printf("Maximum length of arguments %ld\n",sysconf(_SC_ARG_MAX));
printf("Maximum number of simul process per id %ld\n",sysconf(_SC_CHILD_MAX));
printf("number of clock ticks %ld\n",sysconf(_SC_CLK_TCK));
printf("Maximum number of open files %ld\n",sysconf(_SC_OPEN_MAX));
printf("Size of page %ld\n",sysconf(_SC_PAGE_SIZE));
printf("Number of pages %ld\n",sysconf(_SC_PHYS_PAGES));
printf("Number of pages Available %ld\n",sysconf(_SC_AVPHYS_PAGES));

    return 0;
}