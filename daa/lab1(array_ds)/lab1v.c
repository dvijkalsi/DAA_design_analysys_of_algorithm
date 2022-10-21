#include<stdio.h>
int main()
{
    int m,n,i,j;
    printf("Enter the size of matrix\n");
    scanf("%d%d",&m,&n);
    int a[m][n];
    printf("Enter the elements of matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int sum=0;
    int sum1=0;
    int prod=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            sum+=a[i][j];
            if(j>i)
            {
                sum1+=a[i][j];
            }
            if(i==j || i==n-j-1)
            {
                prod*=a[i][j];
            }
        }
    }
    printf("Sum of all elements of matrix is %d\n",sum);
    printf("Sum of all elements of upper triangle of matrix is %d\n",sum1);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j<i)
            {
                printf("%d ",a[i][j]);
            }
        }
        printf("\n");
    }
    printf("Product of diagonal elements of matrix is %d\n",prod);

}