#include <iostream>
#include <vector>
using namespace std;


#include <vector>
#include<unordered_map>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n){
	unordered_map<int,int> ourmap;
    for(int i=0;i<n;i++){
        ourmap[arr[i]]++;
    }
    int start;
    int length=0;
    int current=1;
    for(int i=0;i<n;i++){
        if(ourmap[arr[i]-1]!=0){
            continue;
        }
        else
            current=1;
            int k=1;
            while(ourmap[arr[i]+k]!=0){
                current++;
                k++;
            }
            if(current>length){
                length=current;
                start=arr[i];
            }
        }
    
    vector <int> as;
    as.push_back(start);
    as.push_back(start+length-1);
    return as;
    //Your Code goes here
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
