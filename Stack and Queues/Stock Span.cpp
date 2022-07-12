#include <iostream>
#include<stack>
using namespace std;

int*stockSpan(int *price, int n) 
{ 
	
	stack<int> st; 
	st.push(0); 

    int *output = new int[n];
	output[0] = 1; 

	for (int i = 1; i < n; i++) { 
		
		// price[i] 
		while (!st.empty() && price[st.top()] < price[i])   // chote elemnt ko rakhne ka koi fuydan nahi hai alwyas greter elemnt should be on
                                                             //the right
        {
			st.pop();   
        }
        
		output[i] = (st.empty()) ? (i + 1) : (i - st.top());  // stack ke top pe next elent gerter to left ka index hoga .
        
		st.push(i); 
	}
  
    return output;
} 



int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}