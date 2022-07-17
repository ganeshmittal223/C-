/*

Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.

Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1

*/

#include <iostream>
#include<vector>
using namespace std;


bool getPath(int **mat,int a,int b,int n,bool *visited,vector<int> &vect)
{
    if(a==b)
    {
        vect.push_back(b);
        return true;
    }
    bool ans=false;
    visited[a]=true;
    for(int i=0;i<n;i++)
    {
        
        if(mat[a][i]==1 && !visited[i] && a!=i)
        {
          ans=getPath(mat,i,b,n,visited,vect);
        }
        if(ans==true)
        {
            vect.push_back(a);
            return true;
        }
    }
    return ans;
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
    
    int v1,v2;
    cin>>v1>>v2;
    vector<int> vect;
    if(getPath(mat,v1,v2,v,visited,vect))
    {
        for(auto i:vect)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    // Write your code here
}