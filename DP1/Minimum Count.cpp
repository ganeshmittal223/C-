/*

Code : Minimum Count

Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1

*/

#include <bits/stdc++.h>
using namespace std;

#include<math.h>
#include<climits>
int minCount(int n)
{
    if(sqrt(n)==(float)(sqrt(n)))
        return 1;
    if(n<=3)
        return n;
    int a[n+1];
    a[1]=1;
    a[2]=2;
    a[3]=3;
    int ans;
    for(int i=4;i<=n;i++)
    {
        if(sqrt(i) == (float)(sqrt(i)))
        {
            a[i] = 1;
        }
        else
        {
            int m = INT_MAX;
            for(int j=1;j<sqrt(i);j++)
            {
                // int temp=j*j;
                // if(temp>i)
                //     break;
                // ans=min(a[i],1+a[i-temp]);
                m = min(m, a[i - (j * j)]);
            }
            a[i] = 1 + m;
        }
    }
    return a[n];
	//Write your code here
}


int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}