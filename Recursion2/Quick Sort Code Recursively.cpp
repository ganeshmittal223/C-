#include<iostream>
using namespace std;

	
int pivoting(int input[],int start,int end)
{
    int pivt=input[start];
    int count=0;
    for(int i=start+1;i<=end;i++)
    {
        if(input[i]<=pivt)
            count++;
    }
    int pivotindex=count+start;
    int temp=input[start];
    input[start]=input[pivotindex];
    input[pivotindex]=temp;
    
    int i=start;
    int j=end;
    
    while(i<=pivotindex && j>=pivotindex)
    {
        while(input[i]<=pivt){
            i++;}
        while(input[j]>pivt){
            j--;}
        if(i<pivotindex && j>pivotindex)
        {
            int tem=input[i];
            input[i]=input[j];
            input[j]=tem;
            i++;
            j--;
        }
    }
    return pivotindex;
    
}

void quickSort1(int input[], int start, int end)
	{
    		// your code goes here 
        if(start>=end)
            return;
      int pivot_index=pivoting(input,start,end);
        quickSort1(input,start,pivot_index-1);
        quickSort1(input,pivot_index+1,end);
	}

	void quickSort(int input[], int size)
	{
    		quickSort1(input, 0, size - 1);
	}
		
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


