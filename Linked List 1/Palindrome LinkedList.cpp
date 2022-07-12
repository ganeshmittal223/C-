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

Node *reverse(Node *head)
{
   if(head==NULL||head->next==NULL)
        return head;
    Node*r=reverse(head->next);
    Node*temp=r;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return r;
}

bool isPalindrome(Node *head)
{
    if(head==NULL || head->next==NULL)
        return true;
    int length=0;
    Node *temp=head;
    while(temp!=NULL)
    {
        length++;
        temp=temp->next;
    }
    temp=head;
    
    int mid=(length-1)/2;
    int count=0;
    while(count<mid)
    {
        count++;
        temp=temp->next;
    }
    Node *head2=temp->next;
    temp->next=NULL;
    head2=reverse(head2);
    
    Node *temp1=head;
    Node *temp2=head2;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
            return false;
        
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
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

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}