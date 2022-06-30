/*

Check Array Rotation

You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.

*/


#include <iostream>
using namespace std;
int arrayRotateCheck(int *input, int size)
{
    int count=0;
    for(int i=0;i<size-1;i++)
    {
        if(input[i]>input[i+1])
        {
            return (i+1);
        }
        else if(input[i]<input[i+1])
            continue;
    }
    return count;
    //Write your code here
}

int main()
{

	int t;
	cin >> t;
	while (t--)
	{

		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << arrayRotateCheck(input, size) << endl;
		delete[] input;
	}
	
	return 0;
}

/*
Sample Input 1:
1
6
5 6 1 2 3 4
Sample Output 1:
2

*/