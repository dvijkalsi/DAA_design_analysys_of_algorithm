#include<stdio.h>
int is_prime(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
    {
        if(n%i==0)
        {
            //printf("%d is not prime\n",n);
            return 0;
            break;
        }
    }
    if(i==n/2+1)
    {
        //printf("%d is prime\n",n);
        return 1;
    }
}
void prime_factor1(int n)
{
    printf("Prime factors:");
    int i=2;

    while(n!=1)
    {
        if(is_prime(i) &&  n%i==0)
        {
            printf("%d ",i);
            n/=i;    
        }
        else
        {
            ++i;
        }
    }
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    prime_factor1(n);

}