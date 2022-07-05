#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char str[]) 
{
    int count=0;
    for (int i=0;str[i]!='\0';i++)
    { 
        count++;
    }
    int i=0;
    int p=count-1;
    while(i!=p && i<p)
    {
        if(str[i]==str[p])
        {
            i++;
            p--;
            continue;
        }
        else
            return false;
    }
    return true;
    // Write your code here
}


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << (checkPalindrome(str) ? "true" : "false");
}