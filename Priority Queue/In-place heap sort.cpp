/*

Code : In-place heap sort

Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).

Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2


*/
#include <iostream>
void heapSort(int pq[], int n)
{
    for(int i = 1; i < n; i++) {

        int childIndex = i;
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
    }

    // Remove elements

    int size = n;

    while(size > 1) {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size-1] = temp;

        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndx = 2 * parentIndex + 2;

        while(leftChildIndex < size) {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            }
            if(rightChildIndx < size && pq[rightChildIndx] < pq[minIndex]) {
                minIndex = rightChildIndx;
            }
            if(minIndex == parentIndex) {
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndx = 2 * parentIndex + 2;
        }
    }

    
    // Write your code
}
using namespace std;

int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}