#include <iostream>
using namespace std;
void removeConsecutiveDuplicates(char *input) {
    if(input[0]=='\0')
    return;
    else if(input[0]==input[1])
    {
        int i=0;
        for(;input[i]!='\0';i++)
        {
             input[i]=input[i+1];
        }
        input[i]='\0'; 
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input+1);

}
int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}