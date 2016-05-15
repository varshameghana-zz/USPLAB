/*Avoiding a zombie process
We can avoid a zombie process by forking twice.*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){

         pid_t pid;
         
         if((pid=fork())<0)
             printf("fork() error\n");
             
         else if(pid==0){
              /*first child*/      
              printf("pid of first child=%d\npid of parent = %d\n",getpid(),getppid());
              
              //fork the second child
              
              if((pid=fork())<0)
                 printf("fork() error");
                 
              else if(pid>0){
               
               //in the parent of second child,i.e.. first child
               
                 exit(0);
              }
              
              
              
              //sleep in second child so that first child terminates before printing parent id of second child(so that parent ID of second child now becomes init process(pid 1) and not first child)
             
             
              sleep(2);    
              
              printf("pid of second child=%d\n pid of parent process =%d\n",getpid(),getppid());
              
              
              exit(0);
        }

        if(waitpid(pid,NULL,0)!=pid)
              printf("waitpid error\n");
              
              
              
          exit(0);
}
    

