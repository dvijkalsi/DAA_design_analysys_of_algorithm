//wap to find total number of duplicate elements in the array, and find out the most repeating element in the array.
#include<stdio.h>
void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int arr[n],i,j,k,l,m,count=0,max=0,max_count=0;
    printf("Enter the elements of the array : ");
    for (i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    //sorting the array
    sort(arr, n);
    int repeat_count=0;
    for(i=0;i<n;i++)
    {
        int count=1;
        int flag=0;
        for(j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                flag=1;
            }
            else
            {
                break;
            }
            i=j;
        }
        if(max_count<count)
        {
            max_count=count;
            max=arr[i];
        }
        if(flag)
        {
            repeat_count++;
        }
        count=0;
    }
    printf("Total number of duplicate elements in the array is %d\n",repeat_count);
    printf("Most repeating element in the array is %d\n",max);
    return 0;

}