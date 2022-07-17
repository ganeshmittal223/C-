/*

Code : No. of balanced BTs using DP

Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Time complexity should be O(h).


Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315


*/

#include <iostream>
using namespace std;

#include<math.h>

int balancedBTs(int h) 
{
    
    int dp[h+1];
    
    dp[0]=1;
    dp[1]=1;
    
    int mod = (int) (pow(10,9)+ 7);
    for(int i=2 ;i<=h; i++)
    {
        dp[i]=(int)( ( (long)(dp[i-1])*dp[i-1] )%mod + (2*(long)(dp[i-1])*dp[i-2])%mod  ) % mod;
        
    }
        
return dp[h];

    // Write your code here
}


int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
