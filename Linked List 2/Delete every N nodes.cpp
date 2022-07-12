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

Node *skipMdeleteN(Node *head, int M, int N)
{
    
    if(head==NULL || M==0)
        return NULL;
    
    Node *head1=NULL,*tail1=NULL;
    
    while(head)
    {
       for(int i=0;i<M && head!=NULL;i++)
       {
           if(head1==NULL)
           {
               head1=head;
               tail1=head;
               head=head->next;
           }
           else
           {
               tail1->next=head;
               tail1=head;
               head=head->next;
               tail1->next=NULL;
           }
       }
        for(int i=0;i<N && head!=NULL;i++)
        {
            head=head->next;
        }
    }
    
    return head1;
    
    
	// Write your code here
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
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}