#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#define TimeInterval 2 //specified signal is generated after every 2units of time using alarm API

void date(){

           alarm(TimeInterval);
           system("date"); // system executes specified shell command i.e..,date
           
           /* printf("\n");
              system("who");*/            
}


int main(){

          //sigaction,defined under signal.h is used to examine and change a signal action, has inbuilt structure 'sigaction'
          
          struct sigaction action ; //declaring variable of type struct sigaction
          
          sigemptyset(&action.sa_mask); // sigemptyset initializes signalset specified by set to  empty , sa_mask field specifies the set of signals which need to be blocked(hence this field is set to be empty here)
          
           action.sa_handler=date; // specifies action(execute shell command date) to be assosiated with our signal,SIGALRM
           action.sa_flags=SA_RESTART;//used oly when sa_handler is used,SA_RESTART makes certain system calls restartable across signals
          
           if(sigaction(SIGALRM,&action,0)==-1){
           
              //sigaction returns 0 if successful
                 
                     printf("sigaction error\n");
                     return 1;
           }
           
           if(alarm(TimeInterval)==-1)
           
                   printf("alarm error");
           else
                 while(1){
                 
                 //do nothing
                 
                 }
                 
          return 0;
}   
               
                   
              
