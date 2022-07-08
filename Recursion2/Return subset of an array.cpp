/*

Return subset of an array
Given an integer array (of length n), find and return all the subsets of input array.

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

int subset(int input[], int n, int output[][20]) 
{
    // Write your code here

    if(n<=0)
    {
        output[0][0]=0;
        return 1;
    }
    int size=subset(input+1,n-1,output);
    for (int i = 0 ; i < size ; i++){
        output[i + size][0] = output[i][0] + 1;
        output[i + size][1] = input[0];
        for (int j = 1 ; j <= output[i][0] ; j++){
            output[i + size][j + 1] = output[i][j];
        }
    }
    return 2 * size;
}

int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}

//    0    1    2   3   4   5  6
// 0  0
// 1  1    12
// 2  1    20
// 3  2    20   12
// 4  1    15
// 5  2    15   12
// 6  2    15   20
// 7  3    15   20   12
//     2 * size;   
// size = 4
//      i = 1     0 < size

