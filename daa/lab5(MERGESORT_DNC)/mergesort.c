// 4.2 Write a program to sort a list of n elements using the merge sort method and determine the 
// time required to sort the elements. Repeat the experiment for different values of n and different
// nature of data (random data, sorted data. reversely sorted data) in the list. n is the user input 
// and n integers can be generated randomly. Finally plot a graph of the time taken versus n. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int main()
{    
    int n, i, j, k;
    clock_t start, end;
    double time;
    start = clock();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the kind of data: \n1. Random data\n2. Sorted data\n3. Reversely sorted data\n");
    int ch;
    scanf("%d", &ch);
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    if (ch==2)
    {
        mergeSort(a, 0, n - 1);
    }
    else if (ch==3)
    {        
        mergeSort(a, 0, n - 1);
        for (i = 0; i < n / 2; i++)
        {
            j = n - i - 1;
            k = a[i];
            a[i] = a[j];
            a[j] = k;
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            a[i] = rand() % n;
        }
        mergeSort(a, 0, n - 1);
    }
    printf("\nUnsorted list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    start = clock();
    mergeSort(a, 0, n - 1);
    printf("\n\nSorted list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }        
    end = clock();
    time = (end - start) ;
    printf("\n\nTime taken to sort the list: %f", time);
    free(a);
    return 0;
}

void merge(int *a, int l, int m, int r)
{
    int i=l;
    int j=m+1;
    int k=1;
    int ta[r-l+1];
    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
        {
            ta[k]=a[i];
            i++;
            k++;
        }
        else
        {
            ta[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        ta[k]=a[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        ta[k]=a[j];
        j++;
        k++;
    }
    for(i=l;i<=r;i++)
    {
        a[i]=ta[i-l+1];
    }
}
void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}