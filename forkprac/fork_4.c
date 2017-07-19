#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
pid_t pid,pid2;
if ((pid = fork()) && (pid2 = fork())) {fork();}
if ((pid = fork()) && (pid2 = fork())) {fork();}
if ((pid = fork()) && (pid2 = fork())) {fork();} 

printf("This is process %d \n",getpid());
return 0;
}
