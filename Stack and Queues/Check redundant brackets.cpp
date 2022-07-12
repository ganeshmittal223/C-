#include <iostream>
#include <string>
#include<stack>

using namespace std;

bool checkRedundantBrackets(string expression) 
{
    stack<char>s;
    for(int i=0;expression[i]!='\0';i++)
    {
       
        if(expression[i]==')')
        { if(!s.empty())
        {
            int count=0;
            while(s.top()!='(')
            {
                s.pop();
                count++;
            }
            s.pop();
            if(count<=1)
                return true;
            else 
                continue;
        }}
        
        else
            s.push(expression[i]);
    }
    return false;
	// Write your code here
}
int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}