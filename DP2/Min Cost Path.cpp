/*

Code : Min Cost Path
Send Feedback
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"
The cost of a path is defined as the sum of each cell's values through which the route passes.


Sample Input 1 :
3 4
3 4 1 2
2 1 8 9
4 7 8 1
Sample Output 1 :
13
Sample Input 2 :
3 4
10 6 9 0
-23 8 9 90
-200 0 89 200
Sample Output 2 :
76
Sample Input 3 :
5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7
Sample Output 3 :
18


*/


#include <bits/stdc++.h>
using namespace std;

int minCostPath(int **input, int m, int n)
{
    int **ans=new int*[m];
    for(int i=0;i<m;i++)
    {
        ans[i]=new int[n];
    }
    
    ans[m-1][n-1]=input[m-1][n-1];
    
    //last row
    
    for(int j=n-2;j>=0;j--)
    {
        ans[m-1][j]=input[m-1][j]+ans[m-1][j+1];
    }
    
    //last col
    
    for(int i=m-2;i>=0;i--)
    {
     	ans[i][n-1]=input[i][n-1]+ans[i+1][n-1];   
    }
    
    for(int i=m-2;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            ans[i][j]=input[i][j]+min(ans[i][j+1],min(ans[i+1][j+1],ans[i+1][j]));
        }
    }
    
    return ans[0][0];
	//Write your code here
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath(arr, n, m) << endl;
}

