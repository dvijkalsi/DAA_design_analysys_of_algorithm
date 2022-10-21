// 4.4 Write a program that uses a divide-and-conquer algoritluniuser defined function for the
// exponentiation problem of computing all where a , 0 and n is a positive integer. How does this
// algorithm compare with the brute-force algorithm in terms of number of multiplications made by
// both algorithms.

#include <stdio.h>
#include <stdlib.h>
#define ll long long 

ll power_brute(int, int);
ll power_divide(ll, int);

int main()
{
    int a, n;
    printf("Enter a and n: ");
    scanf("%d %d", &a, &n);
    printf("Enter method to use: \n1. Brute force\n2. Divide and conquer\n");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {
        ll ans = power_brute(a, n);
        printf("a^n = %d", ans);
    }
    else if (ch == 2)
    {
        ll ans = power_divide(a, n);
        printf("a^n = %d", ans);
    }
    return 0;
}

ll power_brute(int a, int n)
{
    if(a==1) 
    {
        return 1;
    }
    ll ans = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        ans = ans * a;
    }
    printf("Number of multiplications: %d\n", n);
    return ans;
}

ll power_divide(ll a, int n)
{
    static int count = 1;
    if(a==1)
    {
        return 1;
    }
    if (n == 0)
    {
        printf("Number of multiplications: %d\n", count);
        return 1;
    }
    else if (n % 2 == 0)
    {
        count++;
        return power_divide(a * a, n / 2);
    }
    else
    {
        count+=2;
        return a * power_divide(a * a, (n - 1) / 2);
    }
}