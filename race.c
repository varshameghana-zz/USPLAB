//program to illustrate race condition

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void charatatime(char *str)
{
        
        //prints one char at a time(could either be from parent process or child process)
        char *ptr;
        int c;
        
        setbuf(stdout,NULL);//setting the stdout buff
        
        for(ptr=str;(c=*ptr++)!=0;)
                putc(c,stdout);//placing one char at a time into stdout buff(printing one char at a time)
}
void main()
{
        int pid;
        if((pid=fork())<0)
                printf("fork error\n");
         //after fork we cannot assume which process(child/parent) resumes execution
        else if(pid==0)
                charatatime("OUTPUT FROM CHILD\n");
        else
                charatatime("output from parent\n");
        exit(0);
}

