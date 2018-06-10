#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	if(argc<0)
		return 0;
	time_t t;
	struct tm *timer;
	char *out;
	out = (char*)malloc(sizeof(char*)*200);
	if(argc == 0)
	{
		time(&t);
		timer = localtime(&t);
		strftime(out,200,"%a %b %d %H:%M:%S %Z %Y",timer);
		printf("%s\n",out);

	}
	else if(argc == 1 && strcmp(argv[argc-1],"-R")==0)
	{
		time(&t);
		timer = localtime(&t);
		strftime(out,200,"%a, %d %b %Y %H:%M:%S +0530",timer);
		printf("%s\n",out);
	}
	else if(argc == 1 && strcmp(argv[argc-1],"-u")==0)
	{
		time(&t);
		timer = gmtime(&t);
		strftime(out,200,"%a %b %d %H:%M:%S %Z %Y",timer);
		printf("%s\n",out);
	}
	else
	{
		printf("Wrong option\n");
	}
}