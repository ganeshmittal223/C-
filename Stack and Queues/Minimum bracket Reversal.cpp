#include <iostream>
#include <string>
#include <stack>

using namespace std;
int countBracketReversals(string input){
	// Write your code here
    stack <char> s;
    for(int i=0;input[i]!='\0';i++){
        if(input[i]=='{')
            s.push('{');
        else{
            if(!s.empty() && s.top()=='{')
                s.pop();
            else
                s.push('}');
        }
    }
    int c=s.size();
    //cout<<ans<<endl;
    if(c%2!=0)
        return -1;
    else
    {
    int ans=0;
    
    while(!s.empty())
    {
        char c1=s.top();
        s.pop();
        char c2=s.top();
        s.pop();
        
        if( c2=='}' && c1=='{')
            ans+=2;
        else
            ans+=1;
    }
    return ans;
    }
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}