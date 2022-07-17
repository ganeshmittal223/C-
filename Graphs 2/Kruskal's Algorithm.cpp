/*

Code : Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
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
1 2 1
0 1 3
0 3 5

*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class edge
{
    public:
    int source;
    int destination;
    int weight;
    edge()
    {
    }
    edge(int source,int destination,int weight)
    {
        this->source=source;
        this->destination=destination;
        this->weight=weight;
    }  
};

bool comp(edge a,edge b)
{
    return a.weight<b.weight;
}

int findParent(int *parent,int v)
{
    if(parent[v]==v)
        return v;
    return findParent(parent,parent[v]);
}

void kruskalAlgo(edge *input,int v,int e)
{
    sort(input,input+e,comp);
    int *parent=new int[v];
    for(int i=0;i<v;i++)
            parent[i]=i;
    edge *output=new edge[v-1];
    int count=0;
    int i=0;
    while(count!=v-1)
    {
        edge currentEdge=input[i];
        
        int parent_source=findParent(parent,currentEdge.source);
        int parent_destination=findParent(parent,currentEdge.destination);
        
        if(parent_source!=parent_destination)
        {
            output[count]=currentEdge;
            count++;
            parent[parent_source]=parent_destination;
        }
        i++;
    }
    for(int i=0;i<v-1;i++)
    {
        if(output[i].source<output[i].destination)
        {
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
       else
           cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
               
        }
    
    
     delete []output;

    delete []parent;

    }
    


int main() 
{
    int v,e;
    cin>>v>>e;
    edge *input=new edge[e];
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i]=edge(s,d,w);
    }
    
    kruskalAlgo(input,v,e);
    delete []input;
    return 0;
    // Write your code here
}

