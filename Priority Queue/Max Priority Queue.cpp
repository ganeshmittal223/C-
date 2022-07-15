/*

Code : Max Priority Queue

Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.



*/
#include <iostream>
using namespace std;

#include<climits>	
#include<vector>
class PriorityQueue {
    // Declare the data members here

    vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        
        int ci=pq.size()-1;
        int pi=(ci-1)/2;
        
        while(pi>=0 && pq[pi]<pq[ci])
        {
           // swap
            int temp=pq[ci];
            pq[ci]=pq[pi];
            pq[pi]=temp;
            
            ci=pi;
            pi=(ci-1)/2;
        }

        
        // Implement the insert() function here
    }

    int getMax() {
        if(pq.size()==0)
            return INT_MIN;
        return pq[0];
        // Implement the getMax() function here
    }

    int removeMax() 
    {
//         if(pq.size()==0)
//             return INT_MIN;
//         int ans=pq[0];
//         int temp1=pq[0];
//         pq[0]=pq[pq.size()-1];
//         pq[pq.size()-1]=temp1;
        
//         pq.pop_back();
//         int i=0;
//         while(i<pq.size())
//         {
//             if(2*i+1>pq.size())
//                 break;
//             else
//             {
//                 if(2*i+2>pq.size())
//                 {
//                     if(pq[i]<pq[2*i+1])
//                     {
//                         int temp=pq[i];
//                         pq[i]=pq[2*i+1];
//                         pq[2*i+1]=pq[i];
//                         i=2*i+1;
//                     }
//                     else
//                     {
//                         break;
//                     }
//                 }
//                 else
//                 {
//                  	if((pq[2*i+1]>pq[2*i+2]) && (pq[i]<pq[2*i+1]))   
//                     {
//                         int temp=pq[2*i+1];
//                         pq[2*i+1]=pq[i];
//                         pq[i]=temp;
//                         i=2*i+1;
//                     }
//                     else if((pq[2*i+1]>pq[2*i+2]) && (pq[i]<pq[2*i+1]))
//                     {
//                         int temp=pq[2*i+2];
//                         pq[2*i+2]=pq[i];
//                         pq[i]=temp;
//                         i=2*i+2;
//                     }
//                 }
                
//             }
//         }
        
//         return ans;
        // Implement the removeMax() function here
        
        if(isEmpty()) return INT_MIN;
        
        int ans = pq[0];
        
        pq[0]=pq[pq.size()-1];
        
        pq.pop_back();
        
        int i=0;
        while (i<pq.size())
        {
            if(2*i+1 >= pq.size()) break; //absence of left child
            else
            {
                if(2*i+2 >= pq.size()) //no right chiid
                {
                    if(pq[i]<pq[2*i+1])
                    {
                        int temp =pq[i];
                        pq[i]=pq[2*i+1];
                        pq[i]=temp;
                        i=2*i+1;
                    }
                    else break;
                }
                else
                {
                    if(pq[2*i+1]>pq[2*i+2]) //left child is max
                    {
                        int temp =pq[i];
                        pq[i]=pq[2*i+1];
                        pq[2*i+1]=temp;
                        i=2*i+1;
                    }
                    else  //right xhild is max
                    {
                       int temp =pq[i];
                        pq[i]=pq[2*i+2];
                        pq[2*i+2]=temp;
                        i=2*i+2; 
                    }
                }
            }
        }
        
        
        
        return ans;

    }

    int getSize() { 
        return pq.size();
        // Implement the getSize() function here
    }

    bool isEmpty() {
        if(pq.size()==0)
            return true;
        else 
            return false;
        // Implement the isEmpty() function here
    }
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        
        cin >> choice;
    }
}