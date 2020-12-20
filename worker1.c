
/*

#include <stdio.h>
#include <dos.h>


int main(int argc, char ** argv)
{




    printf("Directing to your Job via worker 1\n");


    if(system(argv[1])==-1)
        printf("Connection Failed\n");


}


*/





#include<stdio.h>
#include<dos.h>
#include<stdlib.h>


int main () {


FILE * fp;
char ch;
int n;
int t;
char content [100];
int index =0;
char nString[100];
char tString[100];
int i=0,j=0;
while(1)
{
    char job[100][100];
    int count[100], times[100];i=0; j=0;


    fp = fopen("worker1.txt", "r");
    if(fp == NULL){
        printf("exception occured...");
         continue;
    }


    while(1){
        ch = fgetc(fp);
        if(ch == EOF){
          fclose(fp);
          fp = fopen("worker1.txt", "w");
          fclose(fp);
          break;
        }
        if(ch == ' '){

            job[i][j] = '\0';
            j=0;
            index =0;
            while(1){

               char c;
               c= fgetc(fp);
               if(c == ' '){
                 nString[index] ='\0';
                 break;
               }
               else{
                nString[index] = c;
               }
               index++;
            }

            count[i] = atoi(nString);

            index=0;
             while(1){

               char c;
               c= fgetc(fp);
               if(c == ' '){
                 tString[index] ='\0';
                 break;
               }
               else{
                tString[index] = c;
               }
               index++;
            }


            times[i] = atoi(tString);
            printf("%s %d %d\n", job[i], count[i], times[i]);
            i++;
            continue;
        }

       job[i][j] = ch;
       j++;
    }





    for(int currJob = 0; currJob<i; currJob++){

    printf("Directing to your Job via worker 1\n");


     for(int currItr = 0; currItr<count[currJob]; currItr++){
         if(system(job[currJob])==-1)
            printf("Connection Failed\n");
         sleep(times[currJob]);
     }

    }

}

}
