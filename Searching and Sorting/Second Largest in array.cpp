/*

Second Largest in array

You have been given a random integer array/list(ARR) of size N. You are required to find and return the second largest element present in the array/list.
If N <= 1 or all the elements are same in the array/list then return -2147483648 or -2 ^ 31(It is the smallest value for the range of Integer)

*/


#include <iostream>
using namespace std;

#include<climits>
int findSecondLargest(int *input, int n)
{
    int largest=INT_MIN;
    int second_largest=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(input[i]>largest)
        {
            second_largest=largest;
            largest=input[i];
         }
        else if(input[i]>second_largest && input[i]!=largest)
        {
            second_largest=input[i];
        }
    }
    return second_largest;
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

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}

/*

Sample Input 1:
1
7
2 13 4 1 3 6 28
Sample Output 1:
13

*/