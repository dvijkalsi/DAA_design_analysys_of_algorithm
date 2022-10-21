
// Q1.Write a program to sort a given set of elements using the Quick sort method and determine 
// the time required to sort the elements. Repeat the experiment for different values of n, the 
// number of elements in the list to be sorted and plot a graph of the time taken versus n. The 
// elements can be read from a file or can be generated using the random number generator.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int a[],int low,int high)
{
    int x=a[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(a[j]<=x)
        {
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    i++;
    int temp=a[i];
    a[i]=a[high];
    a[high]=temp;
    return i;
}

void quicksort(int a[],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

int main()
{
    clock_t start,end;
    double time;
    start=clock();
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    printf("\nThe elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    quicksort(a,0,n-1);
    printf("\nThe sorted elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    end=clock();
    time=(end-start)/CLOCKS_PER_SEC;
    printf("\nTime taken to sort: %f",time);
    
    return 0;
}