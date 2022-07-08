#include <iostream>
using namespace std;

// input - input array
// size - length of input array
// element - value to be searched

int search(int input[],int start,int end,int element)
{
  int middle=(start+end)/2;
    if(end-start<=1)
    {
        return -1;
    }
    if(input[middle]==element)
    {
        return middle;
    }
    else if(input[middle]>element)
    {
        end=middle-1;
        search(input,start,end,element);
    }
    else if(input[middle]<element)
    {
        start=middle+1;
        search(input,start,end,element);
    }
}


int binarySearch(int input[], int size, int element) {
    // Write your code here

    int start=0;
    int last=size-1;
    return search(input,start,last,element);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
