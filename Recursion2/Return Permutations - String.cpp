/*
Return Permutations - String
Given a string S, find and return all the possible permutations of the input string.

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
  if(input.empty()){
    output[0]="";
    return 1;
  }
  int len = input.length();
 // int ans;
  int k=0;
  string newout[10000];
  for(int i=0;i<len;i++){
    int ans=returnPermutations(input.substr(0,i)+input.substr(i+1),newout);
    for(int j=0;j<ans;j++){
      output[k++] = input[i] + newout[j];
    }
  }         
  return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
