//posix defined configuration options supported by system


#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>

int main(){

          #ifdef  _POSIX_JOB_CONTROL
               printf("system supports job control\n");//If this symbol is defined, it indicates that the system supports job control. Otherwise, the implementation behaves as if all processes within a session belong to a single process group
          #else
               printf("system does not support job control\n");
          #endif
          
          #ifdef  _POSIX_SAVED_IDS
               printf("system supports saved set-UID and saved set-GID\n");//If this symbol is defined, it indicates that the system remembers the effective user and group IDs of a process before it executes an executable file with the set-user-ID or set-group-ID bits set, and that explicitly changing the effective user or group IDs back to these values is permitted.
          #else
               printf("system does not saved set UID and GID\n");
          #endif
          
          
          #ifdef  _POSIX_CHOWN_RESTRICTED
               printf("chown restricted option is %d \n",_POSIX_CHOWN_RESTRICTED);//If this option is set, the chown function is restricted so that the only changes permitted to nonprivileged processes is to change the group owner of a file to either be the effective group ID of the process
          #else
               printf("system does not support chown restricted option\n");
          #endif
          
          #ifdef  _POSIX_NO_TRUNC
               printf("pathname trunc option is:%d\n",_POSIX_NO_TRUNC);//file name components longer than NAME_MAX generate an ENAMETOOLONG error. Otherwise, file name components that are too long are silently truncated.
          #else
               printf("system does not support system wide pathname trunc\n");
          #endif
 
          #ifdef  _POSIX_VDISABLE
               printf("Disable char for terminal files is:%d\n",_POSIX_VDISABLE);// only meaningful for files that are terminal devices. If it is enabled, then handling for special control characters can be disabled individually.
          #else
               printf("system does not support the option\n");
          #endif
          
          
          return 0;
}
                   
          
               
               
