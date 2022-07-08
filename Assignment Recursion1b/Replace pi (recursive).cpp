#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print anything

void arraypass(char input[],int begin,int end)
{
    if(begin==end)
        return;

    if(input[begin]=='p'&& input[begin+1]=='i')
    {
     input[end]='\0';
        end=end+2;
        for(int i=end-1;i>=begin+2;i--)
            input[i+2]=input[i];
        input[begin]='3';
        input[begin+1]='.';
        input[begin+2]='1';
        input[begin+3]='4';
    }
    arraypass(input,begin+1,end);
      
        
    
}

void replacePi(char input[])
{
    int len=0;
    for(int i=0;input[i]!='\0';i++)
        len++;
    arraypass(input,0,len);
	// Write your code here

}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
