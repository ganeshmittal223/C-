/*

3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.

Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1

*/


#include<iostream>
#include<vector>
using namespace std;
int count_cycles(int** arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && arr[i][j]==1)
			{
				for (int k = 0; k < n; k++)
				{
					if (j != k && k != i && arr[j][k]==1)
					{
						if (arr[i][k] == 1)
						{
							count += 1;
						}
					}
				}
			}
		}
	}
	return count;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		arr[u[i]][v[i]] = 1;
		arr[v[i]][u[i]] = 1;
	}
	return count_cycles(arr, n)/6;
}

int main()
{

	int n,m;
	vector<int>u,v;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		u.push_back(x);
        v.push_back(y);
        
    }
	
	cout<<solve(n,m,u,v)<<endl;

}