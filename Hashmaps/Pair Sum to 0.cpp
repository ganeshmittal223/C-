#include <iostream>
using namespace std;

#include<unordered_map>
int pairSum(int *arr, int n) 
{
    unordered_map<int,int> m;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(m.find(-arr[i]) != m.end())
        {
            count += m[-arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
    
    // 0 0 0 0 0 
    
    // map:
    // 0->5
    
    // idx = 5

    // ans = 1 + 2 = 3 + 3 = 6 + 4 = 10
    
    
}
int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}