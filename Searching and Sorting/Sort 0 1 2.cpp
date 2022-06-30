#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int *arr, int n)
{
    int i=0;
    int zero=0;
    int two=n-1;
    while(i<n)
    {    
        if(arr[i]==0)
        {
            int temp=arr[zero];
            arr[zero]=arr[i];
            arr[i]=temp;
            i++;
            zero++;
        }
        else if(arr[i]==2)
        {
            int temp=arr[two];
            arr[two]=arr[i];
            arr[i]=temp;
            two--;
            n--;
            continue;
        }
        else
        {
            i++;
            continue;
        }
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
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}

/*

Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2 
*/

