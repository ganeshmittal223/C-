/*

Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2

*/

#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void allConnected(int **mat,int n,int sv,bool *visited,vector<int> &ans)
{
    ans.push_back(sv);
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(mat[sv][i]==1 && !visited[i])
            allConnected(mat,n,i,visited,ans);
    }
}

void allConnected(int **mat,int n,int sv,bool *visited)
{
    vector<int> ans;
   allConnected(mat,n,sv,visited,ans);
    
  sort(ans.begin() , ans.end());
        
    for( auto i :ans )
        cout << i<<" ";
    cout<<endl;
}

int main()
{
	 int v,e;
    cin>>v>>e;
    int **mat=new int*[v];
    
    for(int i=0;i<v;i++)
    {
         mat[i]=new int[v];
        for(int j=0;j<v;j++)
        {
            mat[i][j]=0;
        }
    }
    
    int x,y;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        mat[x][y]=1;
        mat[y][x]=1;
    }
    
    bool *visited=new bool[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
    		allConnected(mat,v,i,visited);
            cout<<endl;
        }
        
    }
    // Write your code here
}