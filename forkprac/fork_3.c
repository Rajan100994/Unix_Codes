#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
fork(); 
fork();
fork(); 
printf("This is process %d \n",getpid());
return 0;
}
