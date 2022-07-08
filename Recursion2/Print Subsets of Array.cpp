/*
Print Subsets of Array
Given an integer array (of length n), find and print all the subsets of input array.

Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12

*/

#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int size,int output[],int n) {
	// Write your code here
    if(size==0){
        for(int i=0;i<n;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    printSubsetsOfArray(input+1,size-1,output,n);
    output[n]=input[0];
    printSubsetsOfArray(input+1,size-1,output,n+1); 
}
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[10000];
    printSubsetsOfArray(input,size,output,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
