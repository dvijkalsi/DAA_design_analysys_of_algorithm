// 7.5 Given an array of n integers, n is input through keyboard. The problem is to find the length 
// of the subsequence in the given array such that all the elements of the subsequence are sorted 
// in increasing order and also they are alternately odd and even. 
// Exact Input/output Sample-1 
// Enter maximum size of array: 6 Enter 6 integers (separated by space): 5 6 9 4 7 8 
// The longest increasing odd-even subsequence: 15, 6, 7, 8) 
// The length of odd-even increasing subsequence: 4 
// Exact Input/output Sample-2 
// Enter maximum size of array: 10 Enter 6 integers (separated by space): 1 12 2 22 5 30 31 14 17 11 
// The longest increasing odd-even subsequence: 11, 2, 5, 30, 31) or 11, 2, 5, 14, 17) 
// The length of odd-even increasing subsequence: 5 
#include <stdio.h>

int longOddEvenIncSeq(int arr[], int n)
{
	int lioes[n];
	int maxLen = 0;
	for (int i = 0; i < n; i++)
		lioes[i] = 1;

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && (arr[i] + arr[j]) % 2 != 0 && lioes[i] < lioes[j] + 1)
                lioes[i] = lioes[j] + 1;

	for (int i = 0; i < n; i++)
		if (maxLen < lioes[i])
			maxLen = lioes[i];

	return maxLen;
}

int main()
{
	int n;
    printf("Enter the number of the elements: ");
	scanf("%d", &n);
	int arr[n];
    printf("Enter the array: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
	printf("Longest Increasing Odd Even Subsequence: ",longOddEvenIncSeq(arr, n));
	return 0;
}