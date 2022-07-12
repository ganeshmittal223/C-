/*

Code : Polynomial Class
Send Feedback
Implement a polynomial class, with the following properties and functions.
Properties :
1. An integer array (lets say A) which holds the coefficient and degrees. Use array indices as degree and A[i] as coefficient of ith degree.
2. An integer holding total size of array A.
Functions :
1. Default constructor
2. Copy constructor
3. setCoefficient -
This function sets coefficient for a particular degree value. If the given degree is greater than the current capacity of polynomial, increase the capacity accordingly and add then set the required coefficient. If the degree is within limits, then previous coefficient value is replaced by given coefficient value
4. Overload "+" operator (P3 = P1 + P2) :
Adds two polynomials and returns a new polynomial which has result.
5. Overload "-" operator (P3 = p1 - p2) :
Subtracts two polynomials and returns a new polynomial which has result
6. Overload * operator (P3 = P1 * P2) :
Multiplies two polynomials and returns a new polynomial which has result
7. Overload "=" operator (Copy assignment operator) -
Assigns all values of one polynomial to other.
8. print() -
Prints all the terms (only terms with non zero coefficients are to be printed) in increasing order of degree.
Print pattern for a single term : <coefficient>"x"<degree>
And multiple terms should be printed separated by space. And after printing one polynomial, print new line. For more clarity, refer sample test cases


Sample Input 1 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
1
Sample Output 1 :
4x0 3x1 -3x2 3x3 -4x5
Sample Input 2 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
2
Sample Output 2 :
-4x0 -1x1 3x2 1x3 -4x5
Sample Input 3 :
3
1 3 5
1 2 -4
4
0 1 2 3
4 2 -3 1
3
Sample Output 3 :
4x1 2x2 5x3 5x4 -22x5 -6x6 12x7 -4x8

*/



#include <vector>
#include <climits>
#include <iostream>
using namespace std;


class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    public:
    
    //default constructor
    Polynomial()
    {
        degCoeff=new int[5];
        capacity=5;
        for(int i=0;i<capacity;i++)
            degCoeff[i]=0;
    }
    
    ///copy constructor
    Polynomial(Polynomial const &p1)
    {
        this->degCoeff=new int[p1.capacity];
        for(int i=0;i<p1.capacity;i++)
           this->degCoeff[i]=p1.degCoeff[i];
        this->capacity=p1.capacity;
    }
    //print 
     void print() const
    {
        for(int i=0 ;i<capacity;i++)
        {
            if(this->degCoeff[i]==0)
                continue;
            else
            {
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    
    
    //set coefficient
    void setCoefficient(int degree,int coeff)
    {
        while(capacity<=degree)
        {
            int *newArray=new int[2*capacity];
            for(int i=0;i<capacity;i++)
                newArray[i]=degCoeff[i];
            
            for(int i=capacity;i<2*capacity;i++)
                newArray[i]=0;
            
            delete degCoeff;
            degCoeff=newArray;
            capacity*=2;
        }
        degCoeff[degree]=coeff;
    }
    
    
    Polynomial operator+(Polynomial &p2)
    {
        int m=max(capacity,p2.capacity);
        
        if(m==capacity)
        {
            for(int i=p2.capacity;i<m;i++)
                p2.setCoefficient(i,0);
        }
        
        if(m==p2.capacity)
        {
            for(int i=capacity;i<m;i++)
                setCoefficient(i,0);
        }
        
        Polynomial p3;
        for(int i=0;i<m;i++)
        {
            p3.setCoefficient(i,(degCoeff[i]+p2.degCoeff[i]));
        }
        return p3;
    }
    
    
    Polynomial operator-(Polynomial &p2)
    {
        int m=max(capacity,p2.capacity);
        
          if(m==capacity)
        {
            for(int i=p2.capacity;i<m;i++)
                p2.setCoefficient(i,0);
        }
        
        if(m==p2.capacity)
        {
            for(int i=capacity;i<m;i++)
                setCoefficient(i,0);
        }
        
        Polynomial p3;
        for(int i=0;i<m;i++)
        {
            p3.setCoefficient(i,(degCoeff[i]-p2.degCoeff[i]));
        }
        return p3;
    }
    
    
    Polynomial operator=(Polynomial &p2)
    {
        this->degCoeff=new int[p2.capacity];
        this->capacity=p2.capacity;
        for(int i=0;i<capacity;i++)
            this->degCoeff[i]=p2.degCoeff[i];
    }
    
    
    Polynomial operator*(Polynomial const &p2)
    {
        Polynomial p3;
         for(int i=0;i<capacity+p2.capacity;i++)
          p3.setCoefficient(i,0);
        
        for(int i=0;i<capacity;i++)
        {
            for(int j=0;j<p2.capacity;j++)
            {
                p3.setCoefficient(i+j,(p3.degCoeff[i+j]+(degCoeff[i]*p2.degCoeff[j])));
            }
        }
        
        return p3;
    }
};




//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
