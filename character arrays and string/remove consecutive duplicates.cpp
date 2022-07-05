#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
    int j=0;
    input[j]=input[0];
    j++;
    int count=0;
    for(int i=1;input[i]!='\0';i++)
    {
        count++;
    }
    for(int i=1;i<=count;i++)
    {
        if(input[i]!=input[j-1])
        {
            input[j]=input[i];
            j++;
        }
    }
    int i= j;
    for(i;i<=count;i++)
    {
        input[i]=' ';
    }
    // Write your code here
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}