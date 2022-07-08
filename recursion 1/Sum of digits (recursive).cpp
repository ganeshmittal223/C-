#include <iostream>
using namespace std;
int sumOfDigits(int n) 
{
    if(n==0)
        return 0;
    else if(n>0)
        return (n%10)+sumOfDigits(n/10);
    // Write your code here

}



int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
