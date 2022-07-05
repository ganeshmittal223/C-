#include <iostream>
#include <cstring>
using namespace std;

void reverseEachWord(char input[]) 
{
    int j=0;
    for(int i=0;i<=strlen(input);i++)
    {
        if(input[i]==32 || input[i]=='\0')
        {
            int p=i-1;
            for(j;j<=p;j++)
            {
                int temp=input[p];
                input[p]=input[j];
                input[j]=temp;
                p--;
            }
            j=i+1;
        }
    }
    // Write your code here
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}