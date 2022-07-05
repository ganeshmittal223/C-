#include <iostream>
#include <cstring>
using namespace std;

#include<string.h>
#include <bits/stdc++.h>
bool isPermutation(char input1[], char input2[]) 
{
    int len1=0;
    int len2=0;
     for(int i=0;input1[i]!='\0';i++)
     {
         len1++;
     }
     for(int j=0;input2[j]!='\0';j++)
     {
         len2++;
      }
    
  /*  int found=0;
    if(len1==len2)
    {
        for(int i=0;i<len1;i++)
        {
            
            for(int j=0;j<len2;j++)
            {
                found=0;
                if(input1[i]==input2[j]) 
                {
                    found=1;
                    break;
                 }   
            }
            
             if(found==0)
            return false;
         }
    }
        if(found==0)
            return false;
        
       else if(found==1)
              return true;
    }
    // Write your code here*/
    
    
      if(len1==len2)
    {
          sort(input1,input1+len1);
     sort(input2,input2+len2);
    for(int i=0;i<len1;i++)
    {
        if(input1[i]!=input2[i])
            return false;
    }
return true;
    }
    else
        return false;}

int main() {
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}