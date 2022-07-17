#include <iostream>
using namespace std;

#include<unordered_map>

int highestFrequency(int a[], int n) {
 
unordered_map<int,int>p;
    int maxfreq=0;
    for(int i=0;i<n;i++)
    {
        p[a[i]]++;
        maxfreq=max(maxfreq,p[a[i]]);
    }
    int ans;
    for(int i=0;i<n;i++)
    {
        if(p[a[i]]==maxfreq)
        {
            ans=a[i];
            break;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}