//demonstrate interprocess communication between a reader and a writer process

#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char *argv[]){


         char buff[256];
         int fd;//filedescriptor used to store value resulting from open command,returns -1 on every unsuccessful attempt
         
         if(!(argc==2 | argc ==3)){ //the no. of arguments should either be 2 for a read operation ,or 3 for a write operation.
         
             printf("invalid no. of arguments\n");
             return 0;
         }
         
         
         
         mkfifo(argv[1],S_IFIFO|S_IRWXU|S_IRWXG|S_IRWXO);//make a fifo file with the name specified in argv[1] field.Includes read,write,execute permissions for user,group,other defined under header sys/stat.h              
         
         if(argc==2){
         
               //reader process
               fd=open(argv[1],O_RDONLY);//opens file specified in argv[1] argument in readonly mode. 
               printf("contents of fifo file are\n");
               
               if(read(fd,buff,sizeof(buff)))//reads contents of argv[1] file into a buffer and prints contents
                    printf("%s",buff);
                    
                    
         }
         
         else{
                    //writer process(argc=3)
                    fd=open(argv[1],O_WRONLY);//opens file in argv[1] field
                    write(fd,argv[2],strlen(argv[2]));//writes contents upto specified bytes(in argv[2]) into opened file(argv[1])
         
         
        }
         
         
         close(fd);
      }
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
