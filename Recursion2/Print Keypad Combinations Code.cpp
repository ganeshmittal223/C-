/*

Print Keypad Combinations Code

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

void print_subs(int num,string output,string key[])
{
    if(num==0)
    {
        cout<<output<<endl;
        return;
    }
    int x=num%10;
    int i = 0;
    while(i<key[x].length()){
        print_subs(num/10,key[x][i]+output,key);
        i++;
    }
    return;
}

void printKeypad(int num)
{
    string key[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    string output="";
    print_subs(num,output,key);
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
