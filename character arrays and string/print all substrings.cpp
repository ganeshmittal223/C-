#include <iostream>
#include <cstring>
using namespace std;

#include<bits/stdc++.h>
void printSubstrings(char input[]) 
{
    int n=strlen(input);
   //  for (int len = 1; len <= n; len++){
   //    for (int i = 0; i <= n - len; i++){
   //       int j = i + len - 1;
   //       for (int k = i; k <= j; k++)
   //       cout << input[k];
   //       cout << endl;
   //    }
   // }
    for(int i=0;i<n;i++)
    {
        for(int len=1;len<=n-i;len++)
        {
            for(int j=i;j<len;j++)
            {
            cout<<input[j];
            }
             cout<<endl;
        }
       
    }
    
    // Write your code here
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}