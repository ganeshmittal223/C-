/*
Coding Ninjas
Send Feedback
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.


Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1


*/

#include <iostream>
#include <vector>
using namespace std;

void initialise(bool **visited,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
}

bool codingNinja(vector<vector<char>> &board,char c[],int i,int j,int n,int m,bool **visited)
{
    if(board[i][j]=='A')
        return true;
    visited[i][j]=true;
    bool ans=false;
    
    if(i-1>=0 && j-1>=0 && board[i-1][j-1]==c[0] && !visited[i-1][j-1])
    {
        ans= codingNinja(board,c+1,i-1,j-1,n,m,visited);
    if(ans==true)
        return true;
    }
    
    if(i-1>=0 && j>=0 && board[i-1][j]==c[0] && !visited[i-1][j])
    {
        ans=codingNinja(board,c+1,i-1,j,n,m,visited);
     if(ans==true)
        return true;
    }
    
     if(i-1>=0 && j+1<m && board[i-1][j+1]==c[0] && !visited[i-1][j+1])
         {
        ans=codingNinja(board,c+1,i-1,j+1,n,m,visited);
 if(ans==true)
        return true;
    }
    
     if( j+1<m && board[i][j+1]==c[0] && !visited[i][j+1])
         {
        ans= codingNinja(board,c+1,i,j+1,n,m,visited);
 if(ans==true)
        return true;
    }
    
     if(i+1<n && j+1<m && board[i+1][j+1]==c[0] && !visited[i+1][j+1])
         {
        ans= codingNinja(board,c+1,i+1,j+1,n,m,visited);
 if(ans==true)
        return true;
    }
    
     if(i+1<n && board[i+1][j]==c[0] && !visited[i+1][j])
         {
        ans=codingNinja(board,c+1,i+1,j,n,m,visited);
 if(ans==true)
        return true;
    }
    
     if(i+1<n && j-1>=0 && board[i+1][j-1]==c[0] && !visited[i+1][j-1])
         {
        ans=codingNinja(board,c+1,i+1,j-1,n,m,visited);
 if(ans==true)
        return true;
    }
    
     if(j-1>=0 && board[i][j-1]==c[0] && !visited[i][j-1])
         {
        ans= codingNinja(board,c+1,i,j-1,n,m,visited);
 if(ans==true)
        return true;
    }
    if(ans==false) visited[i][j] = false;
    return ans;
    
}
    

bool hasPath(vector<vector<char>> &board, int n, int m) 
{
    char c[]="CODINGNINJA";
	bool **visited=new bool*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new bool[m];
    }
    
    initialise(visited,n,m);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            bool ans=false;
            if(board[i][j]=='C')
            {
                ans=codingNinja(board,c+1,i,j,n,m,visited);
            
            if(ans)
                return 1;
           // initialise(visited,n,m);
        }}
    }
    return 0;
    // Write your code here.
}
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0);
}
