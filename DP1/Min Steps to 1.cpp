/*

Code : Min Steps to 1

Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Write brute-force recursive solution for this.



Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3


*/


#include <bits/stdc++.h>
using namespace std;

#include<climits>

int countMinStepsToOne(int n,int *arr)
{
    if(n==1)
    {
        arr[n]=0;
        return arr[n];
    }
    int a=INT_MAX,b=a,c=b;
    if(arr[n]!=-1)
        return 1+arr[n];
    
    a=countMinStepsToOne(n-1,arr);
    if(n%2==0)
    	b=countMinStepsToOne(n/2,arr);
        
    if(n%3==0)
        c=countMinStepsToOne(n/3,arr);
    
    arr[n]=min(a,min(b,c));
    return 1+arr[n];
}

int countMinStepsToOne(int n)
{
    if(n==1)
        return 0;
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++)
        arr[i]=-1;
    
    return countMinStepsToOne(n,arr);
}



int main()
{
	int n;
	cin >> n;
	cout << countMinStepsToOne(n);
}
