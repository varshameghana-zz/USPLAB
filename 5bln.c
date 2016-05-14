#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

int main(int argc, char* argv[]){


/* A hard link essentially creates a mirror copy of the original linked file. Each hard linked file is assigned the same inode value as the original, therefore they both reference the same physical file location. Any changes to the data in either file is reflected in the other.

Hard links are beneficial as they are more flexible and remain linked even if the original or linked files are moved throughout the file system, although hard links are unable to cross different file systems, hard links can only be assigned to files and not directories as to avoid recursive loops.*/


     if(argc==3){

            printf("Hardlink is created\n");//of form ./a.out filename1 filename2

            return link(argv[1],argv[2]);
     }


      
  /*Each soft linked file contains a separate inode value that points to the original file. As similar to hard links, any changes to the data in either file is reflected in the other.

Soft links are beneficial as they can be linked across different file systems, although if the original file is deleted or moved, the soft linked file will not work correctly (called hanging link).*/
     else if(argc==4){
      
        if(strcmp(argv[1],"-s")==0){ //of form ./a.out -s filename1 filename2

             printf("Sym link created\n");
             symlink(argv[2],argv[3]);
         }

     else{

           printf("argv[1] is -s for symbolic links\n");
     }
}

     else

         printf("invalid no. of arg\n");

return 0;

}
