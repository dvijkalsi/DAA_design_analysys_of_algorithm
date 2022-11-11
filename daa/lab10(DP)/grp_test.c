#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
    FILE *fp;
    fp=fopen("input.txt","r");
    if(fp==NULL)
    {
        printf("File not found");
        return 0;
    }


    char key[100];
    printf("Enter the key: ");
    scanf("%s",key);
    int m=strlen(key);
    int n;
    
    char element[100];
    int flag;
    int count=0;
    while (fscanf(fp,"%s",element)!=EOF)
    {
        flag=1;
        n=strlen(element);
        count++;
        if(strcmp(key,element)==0)
        {
            printf("Key found");
            printf("step count: %d",count);
            
            return 0;
        }
    }
    
    printf("file not found");
    printf("\nstep count: %d\n",count);
    fclose(fp);



    return 0;
}