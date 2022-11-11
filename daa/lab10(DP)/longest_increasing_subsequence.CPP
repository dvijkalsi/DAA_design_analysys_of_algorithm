// 7.4 Given n elements input through keyboard, write a program that prints the length of the longest 
// increasing subsequence whose adjacent element difference is one. 
// Exact Input/output Sample-1 Enter maximum size of array: 10 
// Enter 10 integers (separated by space): 3 10 3 11 4 5 6 7 8 12 
// The longest increasing subsequence whose adjacent element differs by one: {3, 4, 5, 6, 7, 8} 
// The length of increasing subsequence: 6 Exact Input/output Sample-2 Enter maximum size of array: 8 
// Enter 8 integers (separated by space): 6 7 8 3 4 5 9 10 
// The longest increasing subsequence whose adjacent element differs by one: { 6, 7, 8, 9, 10} 
// The length of increasing subsequence: 5 
#include <bits/stdc++.h>
using namespace std;
int longestSubseqWithDiffOne(int arr[], int n)
{
	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if ((arr[i] == arr[j] + 1) || (arr[i] == arr[j] - 1))

				dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	int result = 1;
	for (int i = 0; i < n; i++)
		if (result < dp[i])
			result = dp[i];
	return result;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 3, 2 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << longestSubseqWithDiffOne(arr, n);
	return 0;
}