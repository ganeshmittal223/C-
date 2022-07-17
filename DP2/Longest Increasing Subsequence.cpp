/*

Longest Increasing Subsequence
Send Feedback
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

Sample Input 1 :
6
5 4 11 1 16 8
Sample Output 1 :
3
Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).
Sample Input 2 :
3
1 2 2
Sample Output 2 :
2


*/
#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int* arr, int n) 
{
    int *dp=new int[n];
    dp[0]=1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=0;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i])
            ans=max(dp[j],ans);
        }
        dp[i]=ans+1;
    }
    int result=0;
    for(int i=0;i<n;i++)
        result=max(dp[i],result);
    
    return result;
	// Write your code here
}


int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}