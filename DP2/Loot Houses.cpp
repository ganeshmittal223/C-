/*

Loot Houses

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.


*/

#include <iostream>
using namespace std;

int maxMoneyLooted(int *arr,int n,int *dp)
{
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
    }
    return dp[n-1];
}

int maxMoneyLooted(int *arr, int n)
{
    
    int *dp=new int[n];
    return maxMoneyLooted(arr,n,dp);
}
   
   
int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << maxMoneyLooted(arr, n);

	delete[] arr;
}

