/*

Code : Edit Distance
Send Feedback
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance
Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character


Sample Input 1 :
abc
dc
Sample Output 1 :
2


*/




#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2) 
{
    
    if( s1.size()==0 || s2.size()==0)
        return max(s1.size() ,s2.size());

    if(s1[0]==s2[0])
      return editDistance(s1.substr(1),s2.substr(1));
    
    //recursive calls
    
    int x,y,z;
    
    
    x=editDistance(s1.substr(1) ,s2); //insert
    y=editDistance(s1, s2.substr(1));// delete
    z=editDistance(s1.substr(1), s2.substr(1));// replace
    
    return min(z,min(x,y))+1;
	// Write your code here
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}