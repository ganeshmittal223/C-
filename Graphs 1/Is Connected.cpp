/*
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.

Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 

*/

#include <iostream>
using namespace std;

void connected(int **mat,int n,int sv,bool *visited)
{
    visited[sv]=true;
    
    for(int i=0;i<n;i++)
    {
        if(mat[sv][i]==1 && !visited[i])
            connected(mat,n,i,visited);
    }
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
    
    connected(mat,v,0,visited);
    bool ans=true;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
        {
            cout<<"false";
            return 0;
        }
    }
    cout<<"true";
    return 0;
    // Write your code here
}