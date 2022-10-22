// Write a C program to implement the Longest Common Subsequence.Sample Inputs & outputs 
// The LCS of HUMAN and CHIMPANZEE is HMAN 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global arrays
int **b;
int **c;


void lcs(char *x, char *y, int m, int n) {
    int i, j;
    c = (int **)malloc((m + 1) * sizeof(int *));
    b = (int **)malloc((m + 1) * sizeof(int *));
    //initializing c and b
    for (i = 0; i <= m; i++) {
        c[i] = (int *)malloc((n + 1) * sizeof(int));
        c[i][0] = 0;
        b[i] = (int *)malloc((n + 1) * sizeof(int));
        b[i][0] = 0;
    }
    for(int i=0;i<=n;i++)
    {
        c[0][i]=0;
        b[0][i]=0;
    }


    //filling c and b
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = '\\';
            } 
            else if(c[i-1][j]>=c[i][j-1])
            {
                c[i][j]=c[i-1][j];
                b[i][j]='|';
            }
            else
            {
                c[i][j]=c[i][j-1];
                b[i][j]='-';
            }
        }
    }
    

}

void print_lcs(char *x, int i, int j ) {
    if (i == 0 || j == 0) {
        return;
    }
    if (b[i][j] == '\\') {
        print_lcs(x, i - 1, j - 1);
        printf("%c", x[i]);
    } 
    else if(b[i][j]=='|')
    {
        print_lcs(x,i-1,j);
    }
    else
    {
        print_lcs(x,i,j-1);
    }
}

int main() {
    char *x = " HUMAN";
    char *y = " CHIMPANZEE";
    int m = strlen(x);
    int n = strlen(y);
    lcs(x, y, m, n);
    printf("The LCS of %s and %s is ", x, y);
    print_lcs(x, m, n);
    return 0;
}