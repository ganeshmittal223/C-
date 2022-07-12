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

Node *deleteNode(Node *head, int pos)
{
    if(head==NULL)
        return head;
    Node *temp=head;
    Node *prev=head;
    int i=0;
    while(temp && i!=pos)
    {
        i++;
        prev=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=temp->next;
        temp->next=NULL;
        delete temp;
    return head;
    }
     else if(temp==NULL)
     {
         prev->next=NULL;
         delete temp;
    return head;
     }
    else
    {
        prev->next=temp->next;
        delete temp;
    return head;
    }
    
    // Write your code here.
}


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
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
		int pos;
		cin >> pos;
		head = deleteNode(head, pos);
		print(head);
	}

	return 0;
}