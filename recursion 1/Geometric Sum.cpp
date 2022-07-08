#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double geometricSum(int k)
{
    if(k==0)
        return 1;
    else
        return 1+0.5*(geometricSum(k-1));
    // Write your code here

}



int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
