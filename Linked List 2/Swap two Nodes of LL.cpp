#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;

Node *swapNodes(Node *head, int i, int j)
{
    
    if(head==NULL || head->next==NULL || i==j)
        return head;
    
    Node *current1=NULL,*prev1=NULL,*current2=NULL,*prev2=NULL;
     int i1= i;
     int i2=j;
     i=min(i1,i2);
     j=max(i1,i2);
    Node *temp=head,*prev=NULL;
    int count=0;
    while(temp)
    {
     
        if(count==i)
        {
            current1=temp;
            prev1=prev;
            
        }
        
        else if(count==j)
        {
            current2=temp;
            prev2=prev;
           
        }
        
        prev=temp;
        temp=temp->next;
        count++;
    }
    // Node *temp2=current2->next;
    // current2->next=current1->next;
    // current1->next=temp2;
    
    if(prev1==NULL)
    {
        //  if(abs(i-j)==1)
        // {
        //     Node *forward1=current2->next;
        //     current2->next=current1;
        //     current1->next=forward1;
        //     prev1->next=current2;
        //        head=current2;
        // }
        // else
        {
         Node *temp2=current2->next;
    current2->next=current1->next;
    current1->next=temp2;
        prev2->next=current1;
          head=current2;
    }}
    
    // else if(prev2==NULL)
    // {
    //      if(abs(i-j)==1)
    //     {
    //         Node *forward1=current2->next;
    //         current2->next=current1;
    //         current1->next=forward1;
    //         prev1->next=current2;
    //            head=current1;
    //     }
    //     else
    //     {
    //      Node*extra = current1->next;
    //    current1->next = current2->next;
    //   current2->next = extra;
    //    prev1->next = current2;
    //    head=current1;
    // }
    // }
    else if(prev1!=NULL && prev2!=NULL)
    {
        
        if(abs(i-j)==1)
        {
            Node *forward1=current2->next;
            current2->next=current1;
            current1->next=forward1;
            prev1->next=current2;
        }
        else
        {
        Node *temp2=current2->next;
    current2->next=current1->next;
     current1->next=temp2;
            prev1->next=current2;
            prev2->next=current1;         
        }
    }
    
    return head;
	//Write your code here
}


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}