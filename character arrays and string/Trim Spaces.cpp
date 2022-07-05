#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[]) 
{
    int count=0;
    for (int i=0;input[i]!='\0';i++)
    {
        count++;
    }
    for(int i=0;i<=count;)
    {
        if(input[i]==32)
        {
            for(int j=i;j<count;j++)
            {
                input[j]=input[j+1];
                
            }
            count--;
        }
        else
        {
            i++;
        }
    }
    input[count]='\0';
    // Write your code here
}

int main() {
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}

