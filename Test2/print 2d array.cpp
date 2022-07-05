/*


Print 2D Array
Send Feedback
Given a 2D integer array with n rows and m columns. Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.

Sample Input 1:
3 3
1 2 3
4 5 6
7 8 9
Sample Output 1 :
1 2 3
1 2 3
1 2 3
4 5 6
4 5 6
7 8 9

*/


#include <iostream>

using namespace std;

void print2DArray(int **input, int row, int col) 
{
 
	// Write your code here

   for(int i=0;i<row;i++)
   {
       int rep=row-i;
       while(rep>0)
       {
       for(int j=0;j<col;j++)
       {
           cout<<input[i][j]<<" ";
       }
       cout<<endl;
           rep--;
       }
   }
    
}



using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    int **input = new int*[row];
    for(int i = 0; i < row; i++) {
	    input[i] = new int[col];
	    for(int j = 0; j < col; j++) {
	        cin >> input[i][j];
	    }
    }
    print2DArray(input, row, col);
}
