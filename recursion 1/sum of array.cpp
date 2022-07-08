//Sum of Array

/*

Sample Input 1 :
3
9 8 9
Sample Output 1 :
26

*/

#include<iostream>
using namespace std;

int sum(int input[], int n) 
{
    if(n<=0)
        return 0;
    return sum(input,n-1)+input[n-1];
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}


