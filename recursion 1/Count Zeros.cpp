#include <iostream>
using namespace std;
int countZeros(int num) {
    // Write your code here
    if(num<10){
    if(num == 0)
       return 1;
       else 
       return 0;
       }

    if(num %10 ==0)
        return 1 + countZeros(num / 10);
    else
        return countZeros(num/10); 
}
int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
