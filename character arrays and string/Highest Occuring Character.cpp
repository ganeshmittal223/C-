#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[]) {
    // Write your code here
    int characters=256;
    int count[characters]={0};
    
    for(int i=0;input[i]!='\0';i++){
        count[input[i]]++;
    }
    
    char ans=input[0];
    for(int i=1;input[i]!='\0';i++){
        if(count[ans]<=count[input[i]]){
            ans=input[i];
        }
    }
    
    return ans;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}