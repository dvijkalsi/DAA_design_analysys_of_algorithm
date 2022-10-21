#include<stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array : ");
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    //store the array in such a manner that all even elements are in the left side and all odd elements are in the right side
    int arr1[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2==0)
        {
            arr1[j++]=arr[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]%2!=0)
        {
            arr1[j++]=arr[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=arr1[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}