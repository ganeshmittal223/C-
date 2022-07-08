/*


Pair Star
Send Feedback
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/


#include <iostream>
using namespace std;

void array(char input[],int begin,int end)
{
    
    if(begin>end)
        return;
      
    
    if(input[begin]==input[begin+1])
    {
       
        for(int i=end;i>=begin+1;i--)
        {
            input[i+1]=input[i];
        }
        input[begin+1]='*';
        
        end++;
        input[end+1]='\0';
        // array(input,begin+1,end);
    }
      array(input,begin+1,end);
}

void pairStar(char input[])
{
    // Write your code here

    int len=0;
    // changes 
    for(int i=0;input[i]!='\0';i++)
        len++;
    array(input,0,len);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
