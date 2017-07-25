#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

char *getinput(char *buffer, size_t buflen) {
	printf("$$ ");
	return fgets(buffer, buflen, stdin);
}

int main(int argc, char **argv) {
	char buf[1024];
	pid_t pid;
	int status;
	char *token;
	char c;
	char *source=NULL;
	FILE *fp,*fp1,*fp2,*fp3;
	int flag_read=0,flag_write=0,flag_append=0;


	while (getinput(buf, sizeof(buf))) {
		buf[strlen(buf) - 1] = '\0';
		if(strcmp(buf,"exit")==0)
		{
			return 0;
		}


		if((pid=fork()) == -1) {
			fprintf(stderr, "shell: can't fork: %s\n", strerror(errno));
			continue;
		} else if (pid == 0) {
            
            token = strtok(buf,"<>| ");
   
   		while( token != NULL ) 
   		{
        	if(flag_read==1)
        	{
        	  flag_read=0;
        	  fp=fopen(token,"r");
        	  fp1=fopen("temp.txt","w+");
        	while((c = fgetc(fp)) != EOF) {
     	        fputc(c,fp1);
    			}	 
    			fclose(fp);
    			fclose(fp1);
    		}
    		else if(flag_write==1)
    		{
    			flag_write=0;
    			fp2=fopen("temp.txt","r");
    			fp3=fopen(token,"w+");
    			
        	while((c = fgetc(fp2)) != EOF) {
     	        fputc(c,fp3);
    			}	 
    			fclose(fp2);
    			fclose(fp3);
    	
    		}
    		
    		else if(flag_append==1)
    		{
    	       flag_append=0;
    			fp2=fopen("temp.txt","r");
    			fp3=fopen(token,"a");
    			
        	  
        	while((c = fgetc(fp2)) != EOF) {
     	        fputc(c,fp3);
    			}	 
    			fclose(fp2);
    			fclose(fp3);
    			
    		}
        	else if(strcmp(token,"read")==0)
        	{
            flag_read=1;
        	}
        	else if(strcmp(token,"write")==0)
        	{
        		 flag_write=1;
        	}
        	else if(strcmp(token,"append")==0)
        	{
        		flag_append=1;
        	}
        	else
        	{

        	}

      	token = strtok(NULL,"<>| ");
   		}


			exit(EX_OK);
		}

		if ((pid=waitpid(pid, &status, 0)) < 0)
			fprintf(stderr, "shell: waitpid error: %s\n",
					strerror(errno));
	}
	exit(EX_OK);
}

