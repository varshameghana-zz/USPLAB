//if wait command(used to suspend calling process until the state of child as specified by pid is changed) is not used then parent resumes its execution,hence parent is not aware of termination of child and child becomes zombie.


//The PS command specified here displays state of child as zombie(Z) 
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


#define PS "ps -o pid,ppid,state,tty,command"


int main(){


            pid_t pid;
            
            if((pid=fork())<0)
                 printf("fork() error\n");
                 
                 
            else if(pid==0)
                 exit(0);//exit from child process
                 
                 
            sleep(4);//delay for a specified amount of time
            
            system(PS);//execute specified shell command
            
            
            
            exit(0);
 }
