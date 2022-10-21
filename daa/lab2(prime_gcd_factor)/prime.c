#include<stdio.h>
#include<math.h>
int is_prime2(int n)
{
    
    int c=1;
    
    for(int i=2;i<=n/2;i++)
    {
        c++;
        if(n%i==0)
        {
            //printf("%d is not prime\n",n);
            printf("Count of steps: %d\n",c);
            return 0;
        }
        
    }
    printf("Count of steps: %d\n",c);
    return 1;
    
}
int is_prime1(int n)
{
    
    int c=1;
    for(int i=2;i<n;i++)
    {
        c++;

        if(n%i==0)
        {
            printf("Count of steps: %d\n",c);
            //printf("%d is not prime\n",n);
            return 0; 
           
        }
        
    }
    printf("Count of steps: %d\n",c);
    return 1;
    
}
int is_prime3(int n)
{
    
    int c=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        c++;
        if(n%i==0)
        {
            printf("Count of steps: %d\n",c);
            //printf("%d is not prime\n",n);
            return 0;
            
        }
    }
    printf("Count of steps: %d\n",c);    
    return 1;
    
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("algo1: %d\n",is_prime1(n));
    printf("algo2: %d\n",is_prime2(n));
    printf("algo3: %d\n",is_prime3(n));


    
}