//implement SDD "if E then s1 else s2" and "if E then s1"

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void gen(char b[10],char s1[10],char s2[10],int flag){

               int add1=1,add2=2,add3=3;
               
               
               printf("\n\t if %s goto %d\n",b,add1);//if is true,1 is address of first instruction in if
               printf("\tgoto %d\n",add2);//indicate if condition is true,2 is address of first instruction in else
               
               printf("\n\t %d: %s",add1,s1);//if part
              
               
               if(!flag)//elseflag was set to 0
                    printf("\n\t %d:\n",add2);//go to next instruction,after if statements are executed
                    
                    
               else{
                     //else flag was set to 1
                     printf("\n\t %d\n",add3);
                     printf("\n\t %d:%s",add2,s2);
                     printf("\n\t %d:\n",add3);
               }
               
               
}
               

int main(){

              char *pch,tok[10][10],stmt[50];
              
              int i=0,elseflag=0;//else flag is set to 1 when an else is encountered
              
              printf("Enter the input string:\n");
              gets(stmt);
              
              //The C library function char *strtok(char *str, const char *delim) breaks string str into a series of tokens using the delimiter 
              pch=strtok(stmt," ");//delimitar here is space" "
              
              
              while(pch!=NULL){
              
                     strcpy(tok[i++],pch);//i.e.. if is copied to tok[0], s1 is copied to tok[1] and so on..
                     if(strcmp(pch,"else")==0)
                          elseflag=1;
                         
                     pch=strtok(NULL," ");
               }
               
               
               gen(tok[1],tok[3],tok[5],elseflag);//passing (say) E,s1,s2 and elseflag value to generate func
              
               return 0;
}




               
                     
              
