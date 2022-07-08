#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print anything

void array(char input[],int begin,int end)
{
    if(begin==end)
        return;
    if(input[begin]=='x')
    {
        for(int i=begin;i<end-1;i++)
        {
            input[i]=input[i+1];
        }
        input[end-1]='\0';
         array(input,begin,end);
    }
    array(input,begin+1,end);
}

void removeX(char input[])
{
    // Write your code here

    int len=0;
    for(int i=0;input[i]!='\0';i++)
        len++;
    array(input,0,len);
}


int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
