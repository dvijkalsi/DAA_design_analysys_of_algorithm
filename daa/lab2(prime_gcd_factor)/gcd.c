//find out gcd using 3 algorithmss

#include<stdio.h>
#include<math.h>
//Euclidean
int cou=0;
int gcd_algo1(int x, int y)
{
    // if (y == 0) {
    //     c++;
    //     return x;
    // } else if (x >= y && y > 0) {
    //     c++;
    //     return gcd_algo1(y, (x % y));
    // }
    int co=0;
    while(y!=0)
    {
        int r=x%y;
        x=y;
        y=r;
        co+=3;
    }
    printf("Count of steps: %d\n",co);
    return x;
}
//consecutive integer
int gcd_algo2(int x,int y)
{
    int gcd;
    int co=2;
    for(int i=1;i<=x &&  i<=y;++i)
    {
        co++;
        if(x%i==0 && y%i==0)
        {
            co++;
            gcd=i;
        }
    }
    printf("Count of steps: %d\n",co);
    return gcd;
}
//mid school
int is_prime(int n)
{
    int cou=1;
    int i;
    for(int i=2;i<=sqrt(n);i++)
    {
        cou++;
        if(n%i==0)
        {
            //printf("%d is not prime\n",n);
            cou++;
            return 0;
        }
    }
    cou++;
    return 1;
}
int gcd_algo3(int x,int y)
{
    int gcd=1;
    int i=2;
    int co=2;
    if(x==y)
    {
        printf("Count of steps: %d\n",co);
        return x;
    }

    while(i<x)
    {
        co++;
        if(is_prime(i) &&  x%i==0 && y%i==0)
        {
            gcd*=i;
            x/=i;
            y/=i;    
            co+=3;
        }
        else
        {
            ++i;
            co++;
        }
    }
    printf("Count of steps: %d\n",cou+co);
    return gcd;
}



int main()
{
    int a,b;
    printf("Enter 2 number: ");
    scanf("%d%d",&a,&b);
    printf("algo1:%d\n",gcd_algo1(a,b));

    printf("algo2:%d\n",gcd_algo2(a,b));

    printf("algo3:%d\n",gcd_algo3(a,b));
}