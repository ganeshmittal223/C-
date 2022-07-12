#include <iostream>
#include<algorithm>

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


Node* kReverse(Node*head,int n)
{
    
    if(head==NULL || head->next==NULL || n==0 || n==1)
        return head;
    
    Node *current=head;
    Node *tail=NULL;
    Node *xtra=head;
    Node *prev=NULL;
    int i=1;
    while(xtra && i<=n)
    {
        i++;
       xtra=xtra->next;
        Node *temp1=current->next;
        current->next=prev;
        prev=current;
        current=temp1;
        
    }
    tail=kReverse(current,n);
    
    head->next=tail;
    head=prev;
//     xtra->next=NULL;
//     head=reverse_linked_list_rec(head);
    
//     Node *temp=head;
//     while(temp->next!=NULL)
//         temp=temp->next;
//     temp->next=tail;
    
    return head;
}


Node *reverse(Node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node*smallAns=reverse(head->next);
    Node*tail=head->next;
    tail->next=head;
    head->next=NULL;
   return smallAns;
}




Node* kReverse(Node*head,int n)
{
    Node *p,*q,*newStart,*temp;
    int count=1;
    while(count!=n)
    {
        if(p->next==NULL)
        {
            return head;
        }
        p=p->next;
        count++;
    }
    newStart=p;
    q=newStart;
    
    
    while(1)
    {
        p=head;
        temp=q->next;
        
        if(temp==NULL)
        {
            reverse(p);
            return head;
        }
        q->next=NULL;
        q=temp;
        count=1;
        while(count!=n)
        {
            if(temp->next==NULL)
            {
                reverse(p);
                p->next=q;
                return head;
            }
            temp=temp->next;
            count++;
        }
        reverse(p);
        p->next=temp;
        q=temp;
     }
    return head;
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}