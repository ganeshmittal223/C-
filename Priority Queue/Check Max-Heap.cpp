/*

Check Max-Heap
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

Sample Input 1:
8
42 20 18 6 14 11 9 4
Sample Output 1:
true


*/

#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n) 
{
   for(int child=1; child<n ;child++)
    {
        int parent = (child-1)/2;
        if(arr[parent]<arr[child])
            return false;
    }

    return true;
    // Write your code here
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}