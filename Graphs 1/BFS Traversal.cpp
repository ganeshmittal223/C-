/*

Code : BFS Traversal
Send Feedback
Given an undirected and disconnected graph G(V, E), print its BFS traversal.
Note:
1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well


Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2


*/

#include <iostream>
#include<queue>
using namespace std;

void bfs(int **mat,int n,int sv,bool *visited)
{
    if(n<=0)
        return;
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int i=0;i<n;i++)
        {
            if(i==sv)
            {
                continue;
            }
            if(mat[node][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void bfs_disconnected(int **mat,int n,bool *visited)
{
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bfs(mat,n,i,visited);
        }
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
    
    bfs_disconnected(mat,v,visited);
    // Write your code here
}
