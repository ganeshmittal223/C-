/*


Rotate array

You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).

*/

#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    int p=n-1;
	for(int i=0;i<n/2;i++)
	{
		int temp=input[i];
		input[i]=input[p];
		input[p]=temp;
		p--;
	}
	 p=n-d-1;
	for(int i=0;i<(n-d)/2;i++)
	{
		int temp=input[i];
		input[i]=input[p];
		input[p]=temp;
		p--;
	}
       p=n-1;
       int k=n-d;
	for(int j=1;j<=d/2;j++)
	{
		int temp=input[k];
		input[k]=input[p];
		input[p]=temp;
		p--;
		k++;
}  
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
/*
Sample Input 1:
1
7
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2