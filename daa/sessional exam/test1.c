// sorting each row of 2D array using quicksort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int c=0;
int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;
    int temp;
    c+=4;
    for (j = low; j < high; j++)
    {
        c++;
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            c+=4;
        }
    }
    c+=4;
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int *arr, int low, int high)
{
    c++;
    if (low < high)
    {
        c+=3;
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    clock_t start, end;
    double time;
    start = clock();

    printf("Enter the number of rows: ");
    scanf("%d", &n);



    int arr[n][n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int i, j;
    for (i = 0; i < n; i++)
    {
        quicksort(arr[i], 0, n - 1);
    }
    printf("\nThe sorted array is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f ns\n", time);
    printf("Steps: %d\n", c);

    return 0;
}