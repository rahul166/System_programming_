#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *func(void *ms){
    char *msg=(char*)ms;
     printf("Thread id is:::%d \n",pthread_self());
    printf("%s \n",msg);
    return NULL;
}
int main(){
    pthread_t th1,th2,th3;
    char *msg1="This is thread 1";
     char *msg2="This is thread 2";
      char *msg3="This is thread 3";

      int ret1=pthread_create(&th1,NULL,func,(void*)msg1);
      int ret2=pthread_create(&th2,NULL,func,(void*)msg2);
      int ret3=pthread_create(&th3,NULL,func,(void*)msg3);
      pthread_join(th1,NULL);
      pthread_join(th2,NULL);
      pthread_join(th3,NULL);
   
     
    // printf("%d \n",ret1);
    // printf("%d \n",ret2);
    // printf("%d \n",ret3);
    // exit(0);
    return 0;
}
