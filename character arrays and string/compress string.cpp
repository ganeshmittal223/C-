/*
Compress the String

Write a program to do basic string compression. For a character which is consecutively repeated more than once, replace consecutive duplicate occurrences with the count of repetitions.

Sample Input 1:
aaabbccdsa
Sample Output 1:
a3b2c2dsa

Explanation for Sample Output 1:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is repeated 2 times and 'd', 's' and 'a' and occuring 1 time hence no compression for last 3 characters.

Sample Input 2:
aaabbcddeeeee
Sample Output 2:
a3b2cd2e5
Explanation for Sample Output 2:
In the given string 'a' is repeated 3 times, 'b' is repeated 2 times, 'c' is occuring single time, 'd' is repeating 2 times and 'e' is repeating 25times.


*/

#include <iostream>
#include <cstring>
#include<string>
using namespace std;
string getCompressedString(string &input) {
    // Write your code here.
    int k=input.length();
    int last=input[0];
    char n='1';
    for(int i=1;input[i]!='\0';i++)
    {
        if(input[i]==last)
        {
            input[i]=' ';
            n++;
            if(n>'1'&&i==k-1)
            {
            	input[i]=n;
			}
        }
        else
        {
            last=input[i];
            if(n!='1')
            {
                input[i-1]=n;
                n='1';
            }
        }
    }
    int z=1;
    for(int i=1;input[i]!='\0';i++)
    {
        if(input[i]!=' ')
        {
            input[z]=input[i];
            z++;
        }
    }
    input.resize(z);
    return input;
}

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}
