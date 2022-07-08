/*

Number of Digits

Given the number 'n', find out and return the number of digits present in a number recursively.

Sample Input 1 :
 156
Sample Output 1 :
3
Sample Input 2 :
 7
Sample Output 2 :
1
*/

#include<iostream>

using namespace std;
int count(int n){
   static int sum=0;
    if(n>0)
    {
          sum++;
        count(n/10);      
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


