#include <iostream>
 #include<math.h>
 int array(char input[],int begin,int end)
 {
     if(begin>end)
         return 0;
     else
     {
         return ((input[begin]-'0')*pow(10,end-begin)+array(input,begin+1,end));
     }
    

 }

 int stringToNumber(char input[]) 
 {
     int len=0;
    for(int i=0;input[i]!='\0';i++)
         len++;
     return array(input,0,len-1);
     // Write your code here

 }
using namespace std;

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
