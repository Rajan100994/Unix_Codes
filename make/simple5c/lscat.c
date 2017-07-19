/*
 * simple-ls.c
 * Extremely low-power ls clone.
 * ./simple-ls .
 */

#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv) {

	DIR *dp;
	struct dirent *dirp;
	FILE *fptr;
    char filename[100], c;

	if (argc != 2) {
		fprintf(stderr, "usage: %s dir_name\n", argv[0]);
		exit(1);
	}

	if ((dp = opendir(argv[1])) == NULL ) {
		fprintf(stderr, "can't open '%s'\n", argv[1]);
		exit(1);
	}

	while ((dirp = readdir(dp)) != NULL ){
		if((strlen(dirp->d_name) >= strlen(".c")) &&
    	(0 == strcmp(dirp->d_name + (strlen(dirp->d_name) - strlen(".c")), ".c"))){
			printf("%s\n", dirp->d_name);
			fptr = fopen(dirp->d_name, "r");
			c = fgetc(fptr);
   			 while (c != EOF){
		        printf ("%c", c);
        		c = fgetc(fptr);
    		}
 
    		fclose(fptr);
		}	
	}

	closedir(dp);
	return(0);
}
