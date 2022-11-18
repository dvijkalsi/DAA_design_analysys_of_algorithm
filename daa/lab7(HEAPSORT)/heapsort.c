// Q1.Write a program to sort a given set of elements using the Heap sort method and determine 
// the time required to sort the elements. Repeat the experiment for different values of n, the 
// number of elements in the list to be sorted and plot a graph of the time taken versus n. The 
// elements can be read from a file or can be generated using the random number generator.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int heapsize;
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int a[],int i)
{
    int largest;
    int l=2*i;
    int r=2*i+1;
    if(l<=heapsize && a[l]>a[i])
    {
        largest=l;
    }
    else
    {
        largest=i;
    }
    if(r<=heapsize && a[r]>a[largest])
    {
        largest=r;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(a,largest);
    }
}
void buildheap(int a[],int n)
{
    int i;
    heapsize=n;
    for(i=n/2;i>=1;i--)
        heapify(a,i);

}
void heapsort(int a[],int n)
{
    buildheap(a,n);
    for(int i=n;i>=2;i--)
    {
        swap(&a[1],&a[i]);
        heapsize--;
        heapify(a,1);
    }
}

int main()
{
    int n;    
    clock_t start,end;
    start=clock();
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n+1];
    printf("\nArray: ");
    for(int i=1;i<=n;i++)
    {
        a[i]=rand()%100;
        printf("%d ",a[i]);
    }
    printf("\n");


    heapsort(a,n);

    printf("Sorted array is: ");
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");    
    end=clock();
    double time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Time taken is %f ms",time);
    return 0;
}
