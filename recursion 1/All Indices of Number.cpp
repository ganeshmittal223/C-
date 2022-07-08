/*

All Indices of Number
Send Feedback
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.

Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4
*/

#include<iostream>
using namespace std;
void findIndexes(int input[],int startIndex, int size, int x, int output[],int &k) {
if(startIndex==size)
return;
if(input[startIndex]==x)
{
output[k]=startIndex;
k++;
}
findIndexes(input,startIndex+1,size,x,output,k);
}


int allIndexes(int input[], int size, int x, int output[]) {

int k=0;
findIndexes(input,0,size,x,output,k);
return k;
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
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


