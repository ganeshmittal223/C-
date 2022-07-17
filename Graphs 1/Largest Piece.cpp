/*

Largest Piece
It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with each other on the cake. Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?

Sample Input 1:
2
1 1
0 1
Sample Output 1:
3

*/

#include <iostream>
#include <vector>
using namespace std;


void dfs(vector<vector<int>> &cake,int n,int &k,int i,int j){
    k++;
    cake[i][j]=0;
    
    if(i+1<n && cake[i+1][j]==1)
        dfs(cake,n,k,i+1,j);
    if(i-1>=0 && cake[i-1][j]==1)
        dfs(cake,n,k,i-1,j);
    if(j+1<n && cake[i][j+1]==1)
        dfs(cake,n,k,i,j+1);
    if(j-1>=0 && cake[i][j-1]==1)
        dfs(cake,n,k,i,j-1);
    
}


int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
     int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(cake[i][j]==1){
                int k=0;
                dfs(cake,n,k,i,j);
                ans=max(ans,k);
            }
        }
    }
    return ans;
    // Write your code here
}
int main() {
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}