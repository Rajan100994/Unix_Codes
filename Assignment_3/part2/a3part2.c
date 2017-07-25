#include <stdio.h>
#include <string.h>


int main(int argc, char **argv){

	FILE *fp,*fp1;
	char c[5000];
	char *token;
	int cnt=0;

	fp=fopen("passwd","r");
	fp1=fopen("a3p2task1.txt","w+");
        	while(fgets(c,sizeof(c),fp) != NULL) {
        		token = strtok(c,":");
        		cnt=0;
        		while(token!=NULL){
        			if(strcmp(token,"*")==0){
        				token = strtok(NULL,":");
        				continue;
        			}
        			if(cnt==0)
        				fputs("userid:",fp1);
        			else if(cnt==1)
        				fputs("uid:",fp1);
        			else if(cnt==2)
        				fputs("gid:",fp1);
        			else if(cnt==3)
        				fputs("gecos:",fp1);
        			else if(cnt==4)
        				fputs("home directory:",fp1);
        			else{
        				fputs("shell:",fp1);
        			}
        			cnt++;
        			fputs(token,fp1);
        			fputs("\n",fp1);
        			token = strtok(NULL,":");
        		}
        		fputs("\n",fp1);
     	        
    			}	 
    			fclose(fp);
    			fclose(fp1);

    return 0;

}
