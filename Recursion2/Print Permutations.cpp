/*

Print Permutations
Given an input string (STR), print all possible permutations of the input string.

Sample Input 1:
cba
Sample Output 1:
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

void swap(char &x,char &y)
{
    char temp;
    temp=x;
    x=y;
    y=temp;
}
void printPermutationsHelper(string s,int i,int n){
    int j;
    if (i == n)
        cout << s <<endl;
    else
    {
        for (j = i; j < s.length(); j++)

        {
            swap(s[i],s[j]);

            printPermutationsHelper(s, i + 1, n);

            swap(s[i],s[j]);
        }
    }
}
void printPermutations(string input)
{
    int n=input.size();
    printPermutationsHelper(input,0,n-1);
}


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}