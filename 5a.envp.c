// An environment consists of a table of environment variables, each with an assigned value. When you log in certain login files are executed. They initialize the table holding the environment variables for the process. When this file passes the process to the shell, the table becomes accessible to the shell. When a (parent) process starts up a child process, the child process is given a copy of the parent process' table.#include<stdio.h>

#include<unistd.h>

int main(int argc,char *argv[],char* envp[]){

          int i=0;
          for(i=0;envp[i]!=NULL;i++)
                printf("%s",envp[i]);

}
                    
