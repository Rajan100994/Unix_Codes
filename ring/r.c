#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{

	int fd[2];
	int childpid;
	int nprocs=5;
	int i;
	char data[]="Hellow world";
	printf("started\n");
	pipe(fd);
	dup2(fd[0],0);
	dup2(fd[1],1);
	close(fd[0]);
	close(fd[1]);
	for (i = 1; i < nprocs; i++) {
 	pipe(fd);
 	if ((childpid = fork())) {
		dup2(fd[1],1);	
 		write(fd[1],data,sizeof(data));
 		}
 	else {
 		dup2(fd[0],0);
 		read(fd[0],data,sizeof(data));
 		printf("Process id:%d and message recieved=%s,sending data to child(%d)\n",getpid(),data,childpid);
		 }
 	close(fd[0]);
 	close(fd[1]);
 	if (childpid)
 	{
     printf("here\n");
 	 break;
 	}
	}
	printf("\nThis is process %d recievd message %s", getpid(),data); 

    return 0;

}

