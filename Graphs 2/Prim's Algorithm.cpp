/*

Code : Prim's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.

Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 1 3
1 2 1
0 3 5

*/


#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int findMinVertex(int *weight,bool *visited,int v)
{
    int minVertex=-1;
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex]))
            minVertex=i;
    }
    return minVertex;
}

void primAlgo(int **mat,int v,int e)
{
    int *parent=new int[v];
    bool* visited=new bool[v];
    int *weight=new int[v];
    
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
        weight[i]=INT_MAX;
    }
    
    parent[0]=-1;
    weight[0]=0;
    
    for(int i=0;i<v-1;i++)
    {
        int minVertex=findMinVertex(weight,visited,v);
        visited[minVertex]=true;
        
        for(int j=0;j<v;j++)
        {
            if(mat[minVertex][j] && !visited[j] && mat[minVertex][j]<weight[j])
            {
                weight[j]=mat[minVertex][j];
                parent[j]=minVertex;
            }
        }
    }
    
   
    
    for(int i=1;i<v;i++)
    {
        if(parent[i]<i)
        {
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else
        {
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
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
    
    for(int i=0;i<e;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mat[a][b]=c;
        mat[b][a]=c;    
    }
    
    primAlgo(mat,v,e);
    
    return 0;
    // Write your code here
}
