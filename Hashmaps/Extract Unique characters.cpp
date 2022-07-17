#include <iostream>
#include <string>
using namespace std;

#include<unordered_map>
#include<string>
string uniqueChar(string str) 
{
    unordered_map< char , int > m;
    int index=0;
    for(int i=0;i<str.length();i++)
    {
        if( m[str[i]] > 0)
            continue;
        else
        {
            m[str[i]]++;
            str[index]=str[i];
            index++;
        }
    }
    // for(index;index<str.length();index++)
    // str[index]='\0';
    
    return str.substr(0,index);
	// Write your code here
}

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}