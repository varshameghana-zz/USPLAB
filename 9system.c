// Program to system function

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>


void sys(const char* cmd){

      //sys function uses fork to create a child process, which helps execute shell command(cmd) specified in execl

       int pid;
       pid=fork();
       
       
       if(pid==0)
           execl("/bin/sh","sh","-c",cmd,NULL);//first argument specifies the pathname,arg1,arg2... represent pointers to null terminated strings to be executed,and execl always ends with NULL string
           
       waitpid(pid,NULL,0);//suspends execution of calling process until child(having pid) changes its state
       
}

int main(int argc,char* argv[]){

            int i;
            
            if(argc<2){
            
                printf("Invalid no. of arguments!");
            }
            
            else{
            
                  for(i=1;i<argc;i++){
                       
                               
                       sys(argv[i]);
                       printf("\n");
                   }
           }
 
          exit(0);
}


