/*
Last Index of Number

Given an array of length N and an integer x, you need to find and return the last index of integer x present in the array. Return -1 if it is not present in the array.
Last index means - if x is present multiple times in the array, return the index at which x comes last in the array.
You should start traversing your array from 0, not from (N - 1).
Do this recursively. Indexing in the array starts from 0.

Sample Input :
4
9 8 10 8
8
Sample Output :
3

*/

#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) {  
    if(size == 0)
    {
        return -1;
    }
  
    if(size < 1)
        return -1;

    size--;
    if(input[size] == x) 
        return size;

     lastIndex(input, size,x);
   
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    cout << lastIndex(input, n, x) << endl;

}


