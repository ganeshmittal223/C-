#include <iostream>
using namespace std;


void mergeFunction(int input[],int begin,int mid,int end)
{
    int temp[end-begin+1];
    
    int i=begin;
    int j=mid+1;
    int k=0;
    
    while(i<=mid && j<=end)
    {
        if(input[i]>=input[j])
        {
            temp[k]=input[j];
            j++;
            k++;
        }
        else
        {
            temp[k]=input[i];
            i++;
            k++;
        }
    }
    while(i<=mid)
    {
        
        temp[k]=input[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        temp[k]=input[j];
        j++;
        k++;
    }
    for(int d=begin;d<=end;d++)
    {
        input[d]=temp[d-begin];
    }
}

void mergeSort1(int input[],int begin,int end)
{
     if(begin>=end)
       return;
    else{
    int mid=(begin+end)/2;
    mergeSort1(input,begin,mid);
    mergeSort1(input,mid+1,end);
    mergeFunction(input,begin,mid,end);
    }
}   


void mergeSort(int input[], int size)
{
	// Write your code here
    
  if(size-1<0)
      return;
    
   mergeSort1(input,0,size-1);
}



int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}