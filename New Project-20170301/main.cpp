#define_GNU_Source 
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


extern char **environ;
// specifying POSIX complaint list
void clr();
void dir(char * c);
void ls_environ();
void quit();

int main(void)
{
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  
  printf("enter command:\n");
  
  // read line
  read = getline(&line, &len, stdin);
  printf("Retrieved line of length %zu :\n", read);
  
  if (line);
  exit(EXIT_SUCCESS);
  

// Get the first word of line
char firstword[100];

int numscanned = sscanf(line,"%s",firstword);

char* command[] = {"clr","dir","environ","quit"};

  if(strcmp(firstword,command[0])==0)
  {
    clr();
  }
  else if(strcmp(firstword,command[1])==1)
  {
      dir(char * c);
  }
  else if(strcmp(firstword,command[2])==2)
  {
    ls_environ();  
  }
  else if(strcmp(firstword,command[3])==3)
  {
      quit();
 }

// function for clear 
void clr()
{
    system("clear");
}

//function to list dir contents
void dir(char * c);
{
    printf(" %s\n", c);
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(c);
    while((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", c, myfile->d_name);
        stat(buf, &mystat);
        printf("%zu",mystat.st_size);
        printf(" %s\n", myfile->d_name);
    }
    closedir(mydir);
   
}

//function to list enviromental strings
void ls_environ()
{
    int count = 0;
    printf("\n");
    while(environ[count] != NULL)
    {
        printf("%s",line, environ[count]);
        count++;
    }
}

Void quit()
{
    
    exit(0);
    
}        

