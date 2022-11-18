// 7.3 Write a program to find the Longest palindromic subsequence (Hint: Subsequence is obtained 
// by deleting some of the characters from a string without reordering the remaining characters, 
// which is also a palindrome). 

// Write a C program to implement the Longest Common Subsequence.Sample Inputs & outputs 
// The LCS of HUMAN and CHIMPANZEE is HMAN 
#include<stdio.h>
#include<string.h>
int max (int x, int y) { return (x > y)? x : y; }
int longest_palindrome(char a[], int i, int j)
{
     if (i == j)
      return 1;
    if (a[i] == a[j] && i + 1 == j)
    return 2;
    if (a[i] == a[j])
    return longest_palindrome(a, i+1, j-1) + 2;
    return max(longest_palindrome(a, i, j-1), longest_palindrome(a, i+1, j) );
}
int main()
{
    char seq[10000];
    printf("Enter the string: ");
    scanf("%s", seq);
    int n = strlen(seq);
    printf("The length of the longest palindrome subsequence is: %d", longest_palindrome(seq, 0, n-1));

    return 0;

}