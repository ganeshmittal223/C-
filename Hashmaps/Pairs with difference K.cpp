#include <iostream>
using namespace std;

#include<unordered_map>
int getPairsWithDifferenceK(int *input, int n, int k) 
{
   // Write your code here
    unordered_map<int,int> m;
    for(int i=0 ; i< n ;i++)
    {
        m[input[i]]++;
    }
    int count=0;
    if(k!=0){
    	for(int i=0 ; i<n ;i++)
    	{
     	
        	if(m.count(input[i]-k)>0)
        	{
            	
//             	int j=0;
//             	while(j<m[input[i]-k])
//             	{
//             	count++;
//             	j++;  
//             	}
                count+=m[input[i]-k];
                
        	}
        
    	}

	}
    else if(k==0){
     	for(int i=0;i<n;i++)
        	{
              if(m.count(input[i])>0)
            	{
                  m[input[i]]--;
             		// for(int j=0;j<m[input[i]]-1;j++)
             		// {count++;
             		// }
                count+=m[input[i]];
                  
               
                		//m[input[i]]--;
                }
            }
         }
return count;
}


int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}