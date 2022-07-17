/*

Rat In A Maze Problem
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.


Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 


Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
 As described in the Sample Output 2, four paths are possible.


*/


/*
	Note:
	To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
	This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y), 
	down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include<bits/stdc++.h>
using namespace std;

void backtrack(int n, int ** arr, int ** ans, int row, int column){
    if(row == n-1 && column == n-1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << ans[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    
    if(row-1 >= 0 && ans[row-1][column] != 1 && arr[row-1][column] != 0){
        ans[row-1][column] = 1;
        backtrack(n,arr,ans,row-1,column);
        ans[row-1][column] = 0;
    }
    
    if(row+1 < n && ans[row+1][column] != 1 && arr[row+1][column] != 0){
        ans[row+1][column] = 1;
        backtrack(n,arr,ans,row+1,column);
    	ans[row+1][column] = 0;
    }
    
    if(column-1 >= 0 && ans[row][column-1] != 1 && arr[row][column-1] != 0){
        ans[row][column-1] = 1;
        backtrack(n,arr,ans,row,column-1);
        ans[row][column-1] = 0;
    }
    
    if(column+1 < n && ans[row][column+1] != 1 && arr[row][column+1] != 0){
        ans[row][column+1] = 1;
        backtrack(n,arr,ans,row,column+1);
    	ans[row][column+1] = 0;
    }
    
    return;
}

int main() {
	int n;
    cin>>n;
    
    int ** arr = new int*[n];
    int ** ans = new int*[n];
    
    for(int i = 0; i < n; i++){
        arr[i] = new int[n];
        ans[i] = new int[n];
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            ans[i][j] = 0;
        }
    }
    ans[0][0] = 1;
    
    backtrack(n, arr, ans, 0, 0);
    
    for(int i = 0; i < n; i++){
        delete [] arr[i];
        delete [] ans[i];
    }
    delete [] arr;
    delete [] ans;
    
	return 0;
}


