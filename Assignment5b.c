#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h> 
  
// create a global variable  
int g = 0;
void *myThreadFun(void *vargp) 
{ 
    int *myid = (int *)vargp; 
    // create a local variable
    int l =1;
    // create a static variable  
    static int s = 0; 
  
    // Change static and global variables 
    ++s; ++g; 
    printf("Thread ID: %d, Static: %d, Global: %d, Local: %d\n", *myid, ++s, ++g,++l); 
} 
  
int main() 
{ 
    int i; 
    pthread_t tid; 
  
    // three threads creation
    for (i = 0; i < 3; i++) 
        pthread_create(&tid, NULL, myThreadFun,&tid); 
  
    pthread_exit(NULL); 
    return 0; 
}
