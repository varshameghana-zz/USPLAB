 //1.consider last 100bytes as a region
//2.check if it is locked,if yes-print pid of process which locked it..if no-lock it
//3.read last 50bytes of the region
//4.unlock it

#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <fcntl.h> //contains inbuild struct flock and fcntl cmd
 #include <errno.h>
 
 int main(int argc,char *argv[])
 {
        int fd;
        char buffer[255];//buffer into which last 50bytes are to be read
        struct flock fvar; //declaring a variable of type struct flock
        
        
        
        //fd set to 0(stdin) , 1(stdout) ,2(stderr) and -1(unsuccessful)
        if((fd=open(argv[1],O_RDWR))==-1)//open file specified in argv[1] in read-write mode
        {
                printf("unable to open file\n");
                exit(1);
        }
        
        
        //setting a lock to the last 100 bytes,if it is not already locked by any process
           
         
           
        fvar.l_type=F_WRLCK;//type of lock,write lock
        fvar.l_whence=SEEK_END;//used as a reference for l_start..set to end of file
        fvar.l_start=SEEK_END-100;//"last" 100 bytes
        fvar.l_len=100;//length of region in bytes that needs to be locked
        
        
        printf("press enter to set lock\n");
        getchar();
        
        
        printf("trying to get lock..\n");
        if((fcntl(fd,F_SETLK,&fvar))==-1)
        {     
              fcntl(fd,F_GETLK,&fvar);//F_GETLK is used to test for existence of record lock
              printf("\nFile already locked by process (pid): \t%d\n",fvar.l_pid);        
              return -1;        
        }
        
        
        //else successfully locked
        printf("locked\n");
        
        lseek(fd,SEEK_END-50,SEEK_END);//since last 50 bytes are to be read,3rd field holds whence value
       
        
        
        if(read(fd,buffer,sizeof(buffer)))
                     printf("%s",buffer);
                     
                     
        printf("data read from file..\n");
        puts(buffer);
        printf("press enter to release lock\n");
        getchar();
        fvar.l_type = F_UNLCK;//unlock the region
        fvar.l_whence = SEEK_SET;
        fvar.l_start = 0;
        fvar.l_len = 0;
        if((fcntl(fd,F_UNLCK,&fvar))==-1)
        {
                 printf("fcntl error");
                 exit(0);
        }
        
        
        //else successfully unlocked
        printf("Unlocked\n");
        close(fd);
        return 0;
 }
