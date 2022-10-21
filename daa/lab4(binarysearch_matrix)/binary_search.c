// 4.1 Write a program to search an element x in an array of n integers using binary search algorithm
// that uses divide and conquer technique. Find out the best case, worst case and average case time
// complexities for different values of n and plot a graph of the time taken versus n. The n integers
// can be generated randomly and x can be choosen randomly, or any element of the array or middle or 
// last element of the array depending on type of time complexity analysis.
#include<math.h>
#include<stdio.h>
#include<time.h>

void sort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int binary_search(int A[], int n, int x)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == x)
            return mid;
        else if (A[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    clock_t start, end;
    start=clock();
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int A[n];
    int i=0,x;
    int k=0;
    while(i<n)
    {
        A[i]=rand()%100;
        i++;
    }
    sort(A,n);
    x=rand()%100;

    printf("\n%d found at:%d\n",x,binary_search(A, n, x));
    end = clock();
    float c=(end - start)/(float)CLOCKS_PER_SEC;
    printf("\nTime taken by binary search is %f\n", c);
    return 0;
}