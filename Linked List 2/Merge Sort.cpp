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
int length(Node *head)
{
    int count=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

Node *mergeSort2(Node *head1,Node *head2)
{
    
    if(head1==NULL && head2==NULL)
        return NULL;
    if(head1==NULL && head2!=NULL)
        return head2;
    else if(head2==NULL && head1!=NULL)
        return head1;
    
    Node *final_head=NULL, *final_tail=NULL;
    
    if(head1->data < head2->data)
    {
        final_head=head1;
        final_tail=head1;
        head1=head1->next;
    }
    
    else if(head1->data >= head2->data)
    {
        final_head=head2;
        final_tail=head2;
        head2=head2->next;
    }
    
    while(head1 && head2)
    {
        
        if(head1->data < head2->data)
        {
            final_tail->next=head1;
            final_tail=final_tail->next;
            head1=head1->next;
            // final_tail->next=NULL;
        }
        
        else if(head1->data >= head2->data)
        {
             final_tail->next=head2;
            final_tail=final_tail->next;
            // final_tail=head2;
            head2=head2->next;
           //  final_tail->next=NULL;
        }
        
    }
    
    if(head1)
        final_tail->next=head1;
    if(head2)
        final_tail->next=head2;
    
    return final_head;
    
}

Node *mergeSort(Node *head)
{
	//Write your code here
    
    if(head==NULL || head->next==NULL)
        return head;
    
    /*
    Node *mid=head;
    for(int i=1;i<length(head)/2;i++)
        mid=mid->next;
    
    Node *head1=mid->next;
    mid->next=NULL;
    */
    
    Node* slow = head;
    Node* fast = head-> next;
    
    while( fast != NULL && fast -> next != NULL)
    {
        
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    
    Node* mid1 = slow;
    Node* head1 = mid1 -> next;
    mid1 -> next = NULL;
    
    head=mergeSort(head);
    head1=mergeSort(head1);
    
    return mergeSort2(head,head1);

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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}