/*

Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
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

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>>adj;
    for(int i=0;i<n;i++){
        vector<int>t;
        for(int j=0;j<n;j++){
            t.push_back(0);
        }
        adj.push_back(t);
    }
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        adj[f][s]=1;
        adj[s][f]=1;
    }
    int v1,v2;
    cin>>v1>>v2;
    vector<bool>visited(n,false);
    vector<int>res;
    queue<int>q;
    q.push(v1);
    unordered_map<int,int>mp;
    bool ans=false;
    while(!q.empty()){
        int f=q.front();
        q.pop();
        visited[f]=true;
        for(int i=0;i<n;i++){    
            if(adj[f][i]==1 && visited[i]==false){
                mp[i]=f;
                q.push(i);
                if(i==v2){
                    ans=true;
                    break;
                }
            }
        }
        if(ans) break;
    }
    if(ans){
        int prev=v2;
        while(prev!=v1){
            res.push_back(prev);
            prev=mp[prev];
        }
        res.push_back(prev);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
    }
    
}
