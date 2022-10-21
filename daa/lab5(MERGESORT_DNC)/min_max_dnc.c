// 4.3 Write a program to use divide and conquer method to determine the time required to find the 
// maximum and minimum element in a list of n elements. The data for the list can be generated randomly.
// Compare this time with the time taken by straight forward algorithm or brute force algorithm for
// finding the maximum and minimum element for the same list of n elements. Show the comparison by 
// plotting a required graph for this Problem. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct box
{
    int min;
    int max;
};
void min_max_brute(int *, int, int);
int min_divide(int *, int, int);
int max_divide(int *, int, int);
struct box min_max_divide(int *, int , int );
void min_max_divide2(int *,int ,int , int , int);


int main()
{
    int n, i, j, k;
    clock_t start, end;
    double time;
    start = clock();
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    printf("\nlist: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nEnter method to use: \n1. Brute force\n2. Divide and conquer\n");
    int ch;
    scanf("%d", &ch);
    if(ch==1)
    {
        min_max_brute(a, 0, n - 1);
    }
    else if (ch==2)
    {
        // int min = min_divide(a, 0, n - 1);
        // int max = max_divide(a, 0, n - 1);
        // printf("\nMinimum element: %d", min);
        // printf("\nMaximum element: %d", max);
        // struct box baxa=min_max_divide(a, 0, n - 1);
        // printf("\nMinimum element: %d", baxa.min);
        // printf("\nMaximum element: %d", baxa.max);
        min_max_divide2(a, 0, n - 1,a[0],a[0]);

    }
       
    end = clock();
    time = (end - start)/CLOCKS_PER_SEC;
    printf("\n\nTime taken to find min,max: %f", time);
    free(a);
    return 0;
}

void min_max_brute(int *a, int l, int r)
{
    int i, min, max;
    min = max = a[l];
    for (i = l + 1; i <= r; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
        }
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    printf("\nMinimum element: %d", min);
    printf("\nMaximum element: %d", max);
}

// int min_divide(int *a, int l, int r)
// {
//     int min1, min2;
//     if (l == r)
//     {
//         return a[l];
//     }
//     else
//     {
//         int m = (l + r) / 2;
//         min1 = min_divide(a, l, m);
//         min2 = min_divide(a, m + 1, r);
//         if (min1 < min2)
//         {
//             return min1;
//         }
//         else
//         {
//             return min2;
//         }
//     }
// }
// int max_divide(int *a, int l, int r)
// {
//     int max1, max2;
//     if (l == r)
//     {
//         return a[l];
//     }
//     else
//     {
//         int m = (l + r) / 2;
//         max1 = max_divide(a, l, m);
//         max2 = max_divide(a, m + 1, r);
//         if (max1 > max2)
//         {
//             return max1;
//         }
//         else
//         {
//             return max2;
//         }
//     }
// }

struct box min_max_divide(int *a, int l, int r)
{
    struct box b={a[l],a[l]};

    if (l == r)
    {
        b.min = a[l];
        b.max = a[l];
        return b;
    }
    else
    {
        int m = (l + r) / 2;
        struct box b1 = min_max_divide(a, l, m);
        struct box b2 = min_max_divide(a, m + 1, r);
        if (b1.min < b2.min)
        {
            b.min = b1.min;
        }
        else
        {
            b.min = b2.min;
        }
        if (b1.max > b2.max)
        {
            b.max = b1.max;
        }
        else
        {
            b.max = b2.max;
        }
        return b;
    }
}

