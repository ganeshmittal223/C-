#include <iostream>
using namespace std;
bool Palindrome(char input[],int start,int end)
{
if(start==end || start>end)
        return true;
    if(input[start]!=input[end])
    {
        return false;
    }
    else 
    {
        Palindrome(input,start+1,end-1);
    }
    
}


bool checkPalindrome(char input[]) {
    // Write your code here
    
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) { 
        len++; 
    }

  return  Palindrome(input,0,len-1);
    
}



int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
