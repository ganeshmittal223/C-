/*

Subset Sum
You are given an array of integers and a target K. You have to find the count of subsets of the given array that sum up to K.

Sample Input 1:
1
5 6
2 4 4 3 1
Sample Output 1:
3
Explanation:
Following are the three subsets, that sum upto K=6:
1. [2, 4], Element 4 in this subset is the one at index 1
2. [2, 4], Element 4 in this subset is the one at index 2
3. [2, 3, 1]  
Sample Input 2:
2
8 8
1 4 1 3 1 1 2 3 
8 2
4 1 4 4 2 4 1 1
Sample Output 2:
30
4

*/

#include<bits/stdc++.h>
using namespace std;

int subset(int arr[],int n,int index, int target){
    if(index==n){
        if(target==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    int count= 0;
    if(target- arr[index] >= 0){
        count += subset(arr,n,index+1,target-arr[index]);
    }
    count += subset(arr,n,index+1,target);
    return count;
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<subset(arr,n,0,k)<<endl;
    }
    
    // write your code here
    return 0;
}