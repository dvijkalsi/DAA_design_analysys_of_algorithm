#include<stdio.h>
int main ()
{
    int arr[10], n, i, max, min;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    max = arr[0];
    for (i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    min = arr[0];
    for (i = 0; i < n; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    printf("Largest element : %d\n", max);
    printf("Smallest element : %d",min);
    return 0;
}