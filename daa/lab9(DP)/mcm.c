// Write a program to implement the matrix chain multiplication problem using M-table &
// S-table to find optimal ordering of matrix multiplication. 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


//global variables
int **m;
int **s;
int *p;
int n;

void matrix_chain_order(int n) {
    int i, j, k, l, q;
    m = (int **)malloc(n+1 * sizeof(int *));
    s = (int **)malloc(n+1 * sizeof(int *));
    for (i = 0; i < n; i++) {
        m[i] = (int *)malloc(n+1 * sizeof(int));
        s[i] = (int *)malloc(n+1 * sizeof(int));
    }
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        print_optimal_parens(s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int i, j;
    printf("Enter the number of matrices: ");
    //not working for more than 4 matrices
    scanf("%d", &n);
    p = (int *)malloc((n + 1) * sizeof(int));
    printf("Enter the dimensions of the matrices: ");
    for (i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    matrix_chain_order(n);
    printf("The minimum number of scalar multiplications is: %d \n", m[1][n]);
    printf("The optimal parenthesization is: ");
    print_optimal_parens(1, n);
    printf("\n");
    return 0;
}