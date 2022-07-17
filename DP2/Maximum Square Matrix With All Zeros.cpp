/*

Maximum Square Matrix With All Zeros
Send Feedback
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.


Sample Input 1:
3 3
1 1 0
1 1 1
1 1 1
Sample Output 1:
1
Sample Input 2:
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
Sample Output 2:
4

*/

#include <iostream>
using namespace std;


int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    if(row==0 || col==0)
        return 0;
    int dp[row][col]={0};
    
    //Initialization
    int ans=0;
    for(int i=0;i<row;i++){
        dp[i][0]=(arr[i][0])?0:1;
        ans=max(ans,dp[i][0]);
    }
    for(int i=0;i<col;i++){
        dp[0][i]=(arr[0][i])?0:1;
        ans=max(ans,dp[0][i]);
    }
    
    //Filling up dp table. Where each entry at (i,j) tells of largest size of the subsquare possible
    //ending at (i,j);
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            
            if(arr[i][j]==1)
                dp[i][j]=0;
            else
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
  }


int main()
{
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;

	delete[] arr;

	return 0;
}