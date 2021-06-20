#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //Printing all enviorment variables
for (char **env = __environ; *env != 0; env++)
  {
    char *curr = *env;
        printf("%s\n", curr);    
  }
// printf("Value of the USER Enviorment variable is %s",__environ[0]);
  printf("Value of the USER Enviorment variable is %s",getenv("USER"));
    return 0;
}

