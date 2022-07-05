#include <bits/stdc++.h>
using namespace std;

void printRow(int **matrix,int itr,int &RT,int &RB,int &CL,int &CR)
{
	if(RT>RB)
	return;
	if(itr==RT)
	{
		int c=CL;
		while(c<=CR)
		{
			cout<<matrix[itr][c]<<" ";
			c++;
		}
		RT++;
	}
	else
	{
		int c=CR;
		while(c>=CL)
		{
			cout<<matrix[itr][c]<<" ";
			c--;
		}
		RB--;
	}
}

void printCol(int **matrix,int itr,int &RT,int &RB,int &CL,int &CR)
{
	if(CL>CR)
	return;
	if(itr==CR)
	{
		int r=RT;
		while(r<=RB)
		{
			cout<<matrix[r][itr]<<" ";
			r++;
		}
		CR--;
	}
	else
	{
		int r=RB;
		while(r>=RT)
		{
			cout<<matrix[r][itr]<<" ";
			r--;
		}
		CL++;
	}
}

void spiralPrint(int **matrix,int row,int col)
{
	int RT=0,RB=row-1,CL=0,CR=col-1;
	while(RT<=RB || CL<=CR)
	{
	printRow(matrix,RT,RT,RB,CL,CR);
	printCol(matrix,CR,RT,RB,CL,CR);
	printRow(matrix,RB,RT,RB,CL,CR);
	printCol(matrix,CL,RT,RB,CL,CR);
	}
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}