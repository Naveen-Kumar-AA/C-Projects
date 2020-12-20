/*
#include<stdio.h>

int main()

{
    int i,n,t;

    char a[200];

    printf("Enter how many times u need ur job to be done:");
    scanf("%d",&n);


    printf("Enter in what interval your job is to be done(in s):");
    scanf("%d",&t);

    getchar();

    printf("Enter the worker name and job name: ");

    scanf("%[^\n]s",a);


    for(i=0;i<n;i++)
    {

        if(system(a) == -1)
        {
            printf("\nfailed connection\n");
        }

        sleep(t);

    }

    printf("Number of times your job done : %d",i);

    return 1;

}

*/




#include<stdio.h>
#include<string.h>


void writeToFile(char* fileName, char* jobName , int n, int t)
{
   FILE * fp;
   fp=fopen(fileName , "a");
    if(fp == NULL)
      exit(1);
   fprintf(fp, "%s", jobName);

   fprintf(fp, " %d ", n);
   fprintf(fp, "%d \n", t);
   fclose(fp);
}

int assignJobToWorker(int flag,char* jobName , int n , int t){

if(flag % 2 == 0){

    writeToFile("worker1.txt" , jobName , n ,t );

}
else{

    writeToFile("worker2.txt", jobName , n , t);

}


return flag+1;
}




int main()
{

    int flag = 0;

    int status;

    int n,t;

    char worker[200],jobName[200];

    while(1){

    printf("Enter 0 to exit | 1 to continue...");
    scanf("%d",&status);

    switch (status){
    case 0:
        return;
    case 1:

     printf("Enter job name....");
     scanf("%s",jobName);



     printf("Enter how many times u need ur job to be done:");
     scanf("%d",&n);


     printf("Enter in what interval your job is to be done(in s):");
     scanf("%d",&t);


     flag = assignJobToWorker(flag, jobName , n , t);


    }

}

}
