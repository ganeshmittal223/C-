#include <iostream>
using namespace std;

#include<climits>
void findLargest(int **input, int nRows, int mCols)
{
    
    int largest_sum=INT_MIN;
    bool flag=1;
    int index=0;
    for(int i=0;i<nRows;i++)
    {
        int current_sum=0;
        for(int j=0;j<mCols;j++)
        {
            current_sum=current_sum+input[i][j];
        }
        if(current_sum>largest_sum)
        {
           largest_sum=current_sum;
            index=i;
            flag=1;
        }
    }
    
    
    for(int i=0;i<mCols;i++)
    {
        int current_sum=0;
        for(int j=0;j<nRows;j++)
        {
            current_sum=current_sum+input[j][i];
        }
        if(current_sum>largest_sum)
        {
           largest_sum=current_sum;
            index=i;
            flag=0;
        }
    }
    
    
    if(flag==1)
    {
        cout<<"row "<<index<<" "<<largest_sum;
    }
    else
        cout<<"column "<<index<<" "<<largest_sum;
    
    //Write your code here
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}