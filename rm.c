#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
	if(argc<=0)
	{
		printf("Error not sufficient arguments\n");
		exit(0);
	}
	struct stat value;
	printf("%d\n",1);
    stat(argv[argc-1], &value);
	
	if(!S_ISREG(value.st_mode))
	{
		printf("Invalid file or no file\n");
	}
	else
	{
		if(strcmp(argv[argc-2],"-v")==0)
		{
			int status = remove(argv[argc-1]);
			if(status==0)
			{
				printf("deleted %s \n",argv[argc-1]);
			}
			else
			{
				printf("File not found or Unable to delete the file\n");
			}
			
		}
		else if(strcmp(argv[argc-2],"-i")==0)
		{
			printf("Do you really want to delete the file %s? If yes press y else press anything\n" ,argv[argc-1]);
			char *input;
			input = (char*)malloc(sizeof(char*)*2);
			fgets(input,2,stdin);
			if(*input=='y')
			{
				remove(argv[argc-1]);
			}	
			free(input);
		}
		else
		{
			remove(argv[argc-1]);
		}
	}
	exit(0);
}