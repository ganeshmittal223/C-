/*

Code : Remove Min
Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.

*/

#include <iostream>
#include <climits>
using namespace std;

#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
//         if(pq.size()==0)
//             return -1;
//         int ans=pq[0];
//         int s=pq.size()-1;
        
//         //swap last and first element
        
//         int temp=pq[0];
//         pq[0]=pq[s];
//         pq[s]=temp;
//         pq.pop_back();
//         //delete pq[s];
        
//         int i=0;
//         while(i<pq.size())
//         {
//             if(2*i+1>=pq.size())
//                 break;
//             else
//             {
//                 if(2*i+2>=pq.size())
//                 {
//                     if(pq[i]>pq[2*i+1])
//                     {
//                         int temp=pq[i];
//                         pq[i]=pq[2*i+2];
//                         pq[2*i+2]=temp;
//                         i=2*i+1;
//                     }
//                     else 
//                         break;
//                 }
//                 else
//                 {
//                     if(pq[0]>min(pq[2*i+1],pq[2*i+2]))
//                     {
//                         if(pq[2*i+1]<pq[2*i+2])
//                         {
//                             int temp=pq[i];
//                             pq[i]=pq[2*i+1];
//                             pq[2*i+1]=temp;
//                             i=i*2+1;
//                         }
//                         else
//                         {
//                             int temp=pq[i];
//                             pq[i]=pq[2*i+2];
//                             pq[2*i+2]=temp;
//                             i=2*i+2;
//                         }
//                     }
//                     else 
//                         break;
//                 }
//             }
//         }
//         // Write your code here
//         return ans;
//     }
        
        if(pq.size()==0)
            return -1;
        int m =pq[0]; //return m in end
        
        int lastindex=pq.size()-1;
        
        int temp = pq[0]; //swap to last for CBT
            pq[0] = pq[lastindex];
            pq[lastindex] = temp;
        
        pq.pop_back();
     //   delete pq[lastindex];
        
    int i =0;  
  while(i<pq.size())   // min heap property
    {   if(2*i+1>=pq.size())
         break;
        
       else
       {
           if(2*i+2>=pq.size())
               if(pq[i]>pq[2*i+1])
                   {     int temp = pq[i];
          			 	 pq[i] =pq[2*i+1];
          			     pq[2*i+1]= temp;
                            i=2*i+1;
                   }
   				else break;
           else
           {
       
            	if( pq[i]> min(pq[2*i+1],pq[2*i+2]))
       
          	  {    //storing idex of smallest children
          		   	if(pq[2*i+1]>pq[2*i+2])
                    {int temp = pq[i];
            		pq[i] =pq[2*i+2];
           			pq[2*i+2]= temp;
                        i=2*i+2;
                    }
                        
            	    else 
                    {
            	 
             	   int temp = pq[i];
            		pq[i] =pq[2*i+1];
           			 pq[2*i+1]= temp;
           			i=2*i+1;
                        
                   
                 	}
                }
               else break;
         	}
    
        }
      }
        return m;
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
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMin() << "\n";
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