#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
    int first=0;
    int last=n-1;
    int middle=(first+last)/2;
    while(first<=last)
    {
        if(val<input[middle])
        {
            last=middle-1;
        }
        else if(input[middle]==val)
            return middle;
        else if(input[middle]<val)
            first=middle+1;
        
        middle=(first+last)/2;
    }
     if(first>last)
         return -1;
    //Write your code here
}

int main()
{

	int size;
	cin >> size;
	int *input = new int[size];

	for(int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}
	
	int t;
	cin >> t;

	while (t--)
	{
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}
	
	delete [] input;
	return 0;
}