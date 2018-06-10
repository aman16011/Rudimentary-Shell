#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc<=0)
	{
		printf("insufficient Arguments\n");
		return 0;
	}
	if(argc ==3 && strcmp(argv[0],"-m")==0)
	{
		mkdir(argv[2],atoi(argv[1]));
	}
	else if(argc == 2 && strcmp(argv[0],"-p")==0 )
	{
		char *token;
		const char * delimeter = "/";
		size_t i= 0;
		char *temp = strdup(argv[1]);
		//printf("%s\n",temp);
		token = strtok(temp,delimeter);
		/*printf("%s\n",token);
		printf("%s\n",++token );
		printf("%s\n",++token );*/
		while(token!=NULL)
		{
			mkdir(token,0777);
			chdir(token);
			//printf("%s\n",token);
			token = strtok(NULL,delimeter);
		}
		free(temp);
		free(token);
	}
	else
	{
		printf("Error insufficient or invalid arguments\n");
	}
}