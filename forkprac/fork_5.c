#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	int childpid;
for (int i=1; i<=3; i++) {childpid = fork(); }
printf("This is process %d \n",getpid());
return 0;
}
