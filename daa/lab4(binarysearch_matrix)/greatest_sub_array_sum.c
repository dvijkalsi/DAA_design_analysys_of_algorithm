// 1. Let A be an array of n integers a0,a1,... ,an-1 (negative integers are allowed). Choose 
// the sub-array a[i], a[i+1],... ,a[j] for all and find the sum of the elements of the subarray 
// a[i..j] from range i to j and store it in another array S[] .Write a program by using an user 
// defined function(UDF) that must run in O(n2) time to find out the maximum value of S[i..j]for 
// all the pair i, j with 0 j n-1. a. 
// For example, for the array A[]={1, 3, 7, 2, 1, 5, 1, 2, 4, 6, 3}. 
// b. This maximum sum is S = S[3..] = 2+( 1)+5+( 1)+( 2)+4 = 7. 

#include <stdio.h>
void max_sum_subarr(int S[],int m,int A[],int n)
{
    int i, j, max=0;
    int k=0;
    for (i = 0; i < n; i++)
    {
        S[k++] = A[i];
        for (j =i+1; j < n; j++)
        {
            S[k] = A[j]+S[k-1];
            k++;
        }
    }

    printf("\n S:");
    for(int i=0;i<m;++i)
    {
        printf("%d ",S[i]);
        if(S[i]>max)
            max=S[i];
    }
    printf("\n");

    printf("Maximum sum is %d\n", max);
}
int main()
{
    int A[] = { 3, -2, -1, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int m=n*(n+1)/2;
    int S[m];
    max_sum_subarr(S,m,A,n);
    return 0;
}