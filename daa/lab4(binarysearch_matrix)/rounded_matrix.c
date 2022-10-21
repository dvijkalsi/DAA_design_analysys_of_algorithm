// 2. Consider an n x n matrix A = (aid) , each of elements of ao is a nonnegative real Number. 
// Write a program by defining an user defined function that is used to produce the rounded 
// matrix as shown below. Find out the Computation time of your function.
// before:- 
// 10.9 2.5 1.3 9.3
// 3.8 9.2 2.2 11.8 
// 7.9 5.2 7.3 0.6 
// 3.4 13.1 1.2 6.3 
// after:-
// 11 3 1 9 
// 4 9 2 12 
// 7 5 8 1 
// 4 13 2 6 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

float round_a(float f)
{
    float x = f * 10;
    x = x + 0.6;
    x = x / 10;
    return x;
}
float round_matrix(int n,int A[n][n])
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j] = round_a(A[i][j]);
        }
    }
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int main()
{   
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    clock_t start, end;
    start=clock();
    float A[n][n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            A[i][j]=((float)rand()/RAND_MAX)*100;
        }
    }    
    A[0][0]=4.612;
    printf("\nbefore:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.1f ", A[i][j]);
        }
        printf("\n");
    }


    round_matrix(n,A);
    end = clock();
    float cpu_time_used;
    cpu_time_used = ((end - start));
    printf("\nTime taken by rounding is %f\n", cpu_time_used);
    printf("\nafter:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.0f ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nafter rotating:\n");

        for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%.0f ", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}