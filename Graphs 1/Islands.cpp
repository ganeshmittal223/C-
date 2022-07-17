/*

Islands
Send Feedback
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.

Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 

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
       // cout<<node<<" ";
        
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

int bfs_disconnected(int **mat,int n,bool *visited)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            count++;
            bfs(mat,n,i,visited);
        }
    }
    return count;
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
    
   int count=bfs_disconnected(mat,v,visited);
    cout<<count;
    // Write your code here
}