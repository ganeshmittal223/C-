#include <iostream>
#include<string.h>
using namespace std;


void reverse(char input[],int begin,int end)
{
    for(int i=begin;i<end;i++)
    {
    char temp=input[i];
    input[i]=input[end];
    input[end]=temp;
        end--;
    }   
}
void reverseStringWordWise(char input[])
{
    int len=strlen(input);
    int p=len-1;
    int begin=0; 
    int end=0;
    reverse(input,begin,len-1);
    for(int j=0;j<=len+1;j++)
    {
        if(input[j]==' ' || input[j]=='\0')
        {
            end=j-1;
            reverse(input,begin,end);
            begin=j+1;
        }
    }
    // Write your code here
}
int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringWordWise(input);
    cout << input << endl;
}
