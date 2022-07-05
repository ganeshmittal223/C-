/*

Minimum Length Word
Send Feedback
Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.


Sample Input 1 :
this is test string
Sample Output 1 :
is
Sample Input 2 :
abc de ghihjk a uvw h j
Sample Output 2 :
a

*/


#include<iostream>
#include <climits>
using namespace std;
void minLengthWord(char input[], char output[])
{
    int minLength=INT_MAX;
    for(int i=0;input[i]!='\0';i++)
    {
        if(input[i]==32 || input[i]=='\0')
        {
            
        }
    }
}


int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
