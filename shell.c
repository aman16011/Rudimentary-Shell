#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
/* getting input from the user , this is basically going to call the input function and then it is going to return 
a string of characters*/
char *getinput()
{
	char *input = NULL;
	// printf("1\n");
	size_t number_of_bytes = 200;
	getline(&input, &number_of_bytes,stdin);
	return input;
} 
/* **ptr : = is going to point to the address of the beginning of the pointer 
*/
char **parseinput(char *ptr)
{
	//printf("1\n");
	char **inputs;  /*it is going to store the arguments and the type of variable that one wants to call*/
	//printf("%s\n",ptr);
	const char *delimeteres = " \t\n\v\f\r";
	char *token;

	token = strtok(ptr , delimeteres);
	int bufsize = 50;
	int currentbufsize = 50;
	int size=0;
	
	inputs = (char**)malloc(sizeof(char*)*bufsize);
	//printf("Not enough memoryaman\n");
	while(token!=NULL)
	{
		inputs[size] = token;
		size++;
		if(size >= currentbufsize)
		{
			bufsize += bufsize;
			inputs = (char **)(inputs , sizeof(char*)*bufsize);
			if(inputs==NULL)
			{
				printf("Not enough memory\n");
				fflush(stdout);
				exit(-1);
			}
		}
		token = strtok(NULL , delimeteres);
	}
	inputs[size] = NULL;
	return inputs;
}

void implement_echo(char *arg1 ,char *arg2, char **arg3)
{
	char temp[] = "-n";
	char temp1[] = "-E";
	//printf("%s\n",arg1);
	if(!arg3)
	{
		printf("no input to print\n");
		return;
	}
	if(!arg1)
	{
			while(*arg3!=NULL)
			{
				printf("%s ",*arg3 );
				arg3++;
			}
			printf("\n");
	}
	else
	{
		if((strcmp(arg1,"-n")==0) || (arg2 && (strcmp(arg2,"-n")==0)))
		{
			while(*arg3!=NULL)
			{
				printf("%s ",*arg3 );
				arg3++;
			}
		}
		else
		{
			while(*arg3!=NULL)
			{
				printf("%s ",*arg3 );
				arg3++;
			}
			printf("\n");
		}
	}
}
int main()
{
	int i=0;
	do
	{
		printf("aman ->");
		char *line;

		char *pointer;
		int fd = open("history.txt",O_WRONLY | O_APPEND);
		//printf("%s\n","aman");
		line = getinput();
		pointer = line;
		write(fd,pointer,strlen(pointer));
		/*while(pointer)
		{
			printf("%c\n",*pointer );
			write(fd,pointer,1);
			pointer++;
		}*/
		close(fd);
		//printf("%s\n","aman1");
		//printf("%s\n" , line);
		char **arguments = NULL;
		if(!(*line=='\n'))
		arguments = parseinput(line);
		else
		{
			printf("try again no command\n");
		}
		//printf("%s\n",*arguments);
		if(arguments)
		{
			char *command = *arguments;
			++arguments;
			if(strcmp(command,"echo")==0)
			{
				if(!*arguments)
				{
					printf("not enough arguments\n");
				}
				else{
				char *temp = *arguments;
				if(temp && *temp=='-')
				{
					arguments++;
					if(*arguments){
					char *temp1 = *arguments; 
					//printf("%d\n",strcmp(*arguments,"-n")==0);
					if(*temp1=='-')
					{
						implement_echo(temp,temp1,++arguments);
					}
					else

					{implement_echo(temp,NULL,arguments);}}
				else
				{

					printf("Not Enough Arguments\n");
				}
				//printf("%d\n",s);
				}
				else
				{
					implement_echo(NULL,NULL,arguments);
				}}
				//free(temp);
			}
			else if(strcmp(command,"exit")==0)
			{
				return 0;
				i=1;
			}
			else if(strcmp(command,"pwd")==0)
			{
				if(*arguments && (strcmp(*arguments,"-P") == 0))
				{
					char *buf = (char*) malloc(sizeof(char*)*1024);
					size_t size = 1024;
					getcwd(buf,size);
					printf("%s\n",buf );
					free(buf);
				}
				else if(!(*arguments) || (*arguments && (strcmp(*arguments,"-L") == 0)))
				{
					printf("%s\n",getenv("PWD"));
				}
				else
				{
					printf("wrong input\n");
				}		
			}
			else if(strcmp(command,"cd")==0)
			{
				char *temp = *arguments;
				if(temp && strcmp(temp,"~")==0)
				{
					chdir(getenv("HOME"));
				}
				else if(temp)
				{
					if(chdir(temp)!=0)
					{
						printf("error \n");
					}
				}
				else
				{
					printf("error insufficient number of arguments");
				}
				//free(temp);
				char cwd[1024];
				if (getcwd(cwd, sizeof(cwd)) != NULL)
				fprintf(stdout, "Current working dir: %s\n", cwd);		
			}
			else if(strcmp(command,"history")==0)
			{		
				char *temp = *arguments;
				if(temp && strcmp(temp,"-n")==0 || !temp)
				{
					int fd = open("/home/aman/Desktop/assignment0_OS/history.txt",O_RDONLY);
					int x;
					char *buf = (char*)malloc(sizeof(char*)*4);
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
				else if(temp && strcmp(temp,"-c")==0 || !temp)
				{

					FILE *fd = NULL;
					fd = fopen("/home/aman/Desktop/assignment0_OS/history.txt","w");
					fprintf(fd," ");
					fclose(fd);
				}
				else
				{
					printf("Invalid Commands\n");
				}
			}
			else if(strcmp(command,"ls")==0)
			{
				pid_t pid;
				pid = fork();
				//printf("%d\n",1);
				//printf("%s\n",*arguments);
				if(pid < 0)
				{
					fprintf(stderr,"Fork Failed");
					return 1;
				}
				else if(pid==0)
				{
					execvp("/home/aman/Desktop/assignment0_OS/ls",arguments);
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strcmp(command,"date")==0)
			{
				pid_t pid;
				pid = fork();
				//printf("%s\n",*arguments);
				if(pid < 0)
				{
					fprintf(stderr,"Fork Failed");
					return 1;
				}
				else if(pid==0)
				{
					execvp("/home/aman/Desktop/assignment0_OS/date",arguments);
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strcmp(command,"rm")==0)
			{
				pid_t pid;
				pid = fork();
				printf("%d\n",1);
				//printf("%s\n",*arguments);
				if(pid < 0)
				{
					fprintf(stderr,"Fork Failed");
					return 1;
				}
				else if(pid==0)
				{
					execvp("/home/aman/Desktop/assignment0_OS/rm",arguments);
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strcmp(command,"mkdir")==0)
			{
				pid_t pid;
				pid = fork();
				//printf("%s\n",*arguments);
				if(pid < 0)
				{
					fprintf(stderr,"Fork Failed");
					return 1;
				}
				else if(pid==0)
				{
					execvp("/home/aman/Desktop/assignment0_OS/mkdir",arguments);
				}
				else
				{
					wait(NULL);
				}
			}
			else if(strcmp(command,"cat")==0)
			{
				pid_t pid;
				pid = fork();
				//printf("%s\n",*arguments);
				if(pid < 0)
				{
					fprintf(stderr,"Fork Failed");
					return 1;
				}
				else if(pid==0)
				{
					execvp("/home/aman/Desktop/assignment0_OS/cat",arguments);
				}
				else
				{
					wait(NULL);
				}
			}
			else
			{
				printf("(Either is is wrong command or I don't know about it I am quite new to this)\n");
			}
			free(line);
			//free(arguments);
		}
		else
		{
			printf("type something\n");
		}
	}while(i==0);	
}
