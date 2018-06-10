#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char const *argv[])
{
  struct dirent **list;
  int n;
  n = scandir(".", &list, NULL, alphasort);
  //printf("%d\n",argc);
  if (n < 0){
  perror("scandir");}
  else 
  {
    if(argc < 0 )
    {
      printf("Error in the directory\n");
    }
    else if(argc==0 )
    {
      //printf("%d\n",1);
      while (n--) 
      {
        if(!(*list[n]->d_name=='.' || strcmp(list[n]->d_name,"..")==0))
        printf("%s %lu\n", list[n]->d_name,list[n]->d_ino);
        free(list[n]);
      }
      free(list);
    }
    else if(argc == 1)
    {
      //n = scandir(".", &list, NULL, alphasort);
      if(strcmp(argv[argc-1],"-i")==0)
      {
        while (n--) 
      {
        if(!(strcmp(list[n]->d_name,".")==0 || strcmp(list[n]->d_name,"..")==0))
        printf("%s %lu\n", list[n]->d_name,list[n]->d_ino);
        free(list[n]);
      }
      free(list);
      }
      else if(strcmp(argv[argc-1],"-a")==0)
      {
        while (n--) 
      {
        printf("%s\n", list[n]->d_name);
        free(list[n]);
      }
      free(list);
      }
      else
      {
        printf("error\n");
      }
    }
    else
    {
      printf("error\n");
    }
  }
  return 0;
}
