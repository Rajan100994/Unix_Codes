#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fd[2];
    int cnt=1;
    int child;
    int parent;
    int nprocs = atoi(argv[1]);
    char data[] = "Hello World";
    // create pipe descriptors
    pipe(fd);
while(cnt < nprocs){
    pipe(fd);
    cnt++;
    // fork() returns 0 for child process, child-pid for parent process.
    if ((child=fork()) != 0)
    {
        close(fd[0]);
        write(fd[1], data, sizeof(data));
        close(fd[1]);
        printf("Current process is %d\n",getpid());
        printf("The recieved message is %s\n",data );
        if(cnt!=2)
        exit(1);
    }
    else
    {   
        close(fd[1]);
        read(fd[0], data, sizeof(data));

        printf("Sending data to child(%d) \n\n ", getpid());
        
        close(fd[0]);
    }
}
    read(fd[0], data, sizeof(data));
    printf("Original Parent(%d) got %s \n",getpid(),data);

    usleep(40000);
    return 0;

}