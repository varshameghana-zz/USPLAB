#define _POSIX_SOURCE //includes the functionality from the POSIX.1 standard as well as all of the ISO C facilities. 
#define _POSIX_C_SOURCE 199309L//The value 199309L or greater additionally exposes definitions for POSIX.1b

#include <stdio.h>
#include <unistd.h>

int main(){

	long res;
	//POSIX  allows  an  application to test at compile or run time whether certain options are supported, or what the value is of certain configurable constants or limits.At compile time this is done by including <unistd.h> and/or <limits.h> and testing the value of certain macros.
	
	
	//At run time, one can ask for numerical values using the present function sysconf()
     
        if((res=sysconf(_SC_CLK_TCK))==-1)
           printf("error in sysconf");
           
        else
             printf("no. of clock ticks=%ld\n",res);//The number of clock ticks per second
        
                

        if((res=sysconf(_SC_CHILD_MAX))==-1)
		printf("error in sysconf");

        else
                printf("max no. of child processes =%ld\n",res);//  The max number of simultaneous processes per user ID.  Must not be less than _POSIX_CHILD_MAX (25).

          if((res=sysconf(_SC_OPEN_MAX))==-1)
		printf("error in sysconf");

           else
                printf("max no. of open files =%ld\n",res);//The maximum number of files that a process can have open at any time.  Must not be less than _POSIX_OPEN_MAX (20).
                
                
               
               // we can check for the numerical  values  that may  depend  on  the  file  system a file is in using the calls fpathconf(3) and pathconf(3)

        
         if((res=pathconf("/",_PC_PATH_MAX))==-1)
		printf("error in sysconf");

         else
                printf("max path length =%ld\n",res);//maximum length of a relative pathname when path or fd is the current working directory

          if((res=pathconf("/",_PC_NAME_MAX))==-1)
		printf("error in sysconf");

         else
                printf("max no. of charac in a file =%ld\n",res);//maximum length of a filename in the directory path or fd that the process is allowed to create


      return 0;
}
        
