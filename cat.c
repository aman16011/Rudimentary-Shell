#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char const *argv[])
{
	int fd;
	char *buf = (char*)malloc(sizeof(char*)*4);
	if(argc <= 0)
	{
		printf("error\n");
		return 0;
	}
	else
	{
		if(argc == 2 && strcmp(argv[argc-2],"-E")==0)
		{
			fd = open(argv[1],O_RDONLY);
			if(fd==-1)
			{
				printf("%s\n","error" );
			}
			int x;
			x = read(fd,buf,1);
			while(x>0) // to avoid possibility of end of file and an interrupted signal
			{
				if(*buf=='\n')
				{
					printf("%c",'$');
				}
				printf("%c",*buf);
				x = read(fd,buf,1);
			}
			close(fd);
		}
		else if(argc==2 && strcmp(argv[0],"-n")==0)
		{
			fd = open(argv[1],O_RDONLY);
			if(fd==-1)
			{
				printf("%s\n","error" );
			}
			int x;
			x = read(fd,buf,1);
			int count;
			count = 2;
			printf("     %d  ",1);
			while(x>0) // to avoid possibility of end of file and an interrupted signal
			{
				if(*buf=='\n')
				{
					printf("%c",*buf);
					x = read(fd,buf,1);
					if(x<=0)
					{
						break;
					}
					printf("     %d  ",count);
					count+=1;
				}
				else
				{
					printf("%c",*buf);
					x = read(fd,buf,1);
				}
			}
			close(fd);
		}
		else if(argc==1)
		{
			fd = open(argv[0],O_RDONLY);
			if(fd==-1)
			{
				printf("%s\n","error" );
			}
			int x;
			x = read(fd,buf,1);
			while(x>0) // to avoid possibility of end of file and an interrupted signal
			{
				printf("%c",*buf);
				x = read(fd,buf,1);
			}
			close(fd);
		}
		else
		{
			printf("%s\n","retype! error" );
		}


	}
	return 0;
}