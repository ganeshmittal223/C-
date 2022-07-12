#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


class Queue {
	// Define the data mmbers
    Node *head;
    Node *tail;
    int size;
   public:
    Queue() {
        head=NULL;
        tail=head;
        size=0;
		// Implement the Constructor
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
        return size;
		// Implement the getSize() function
	}

    bool isEmpty() 
    {
        if(head==NULL)
            return true;
        else 
            return false;
		// Implement the isEmpty() function
	}

    void enqueue(int data)
    {
        if(head==NULL)
        {
            Node *temp=new Node(data);
            head=temp;
            tail=head;
            size++;
        }
        else
        {
             Node *temp=new Node(data);
            tail->next=temp;
            tail=temp;
            size++;
        }
		// Implement the enqueue() function
	}

    int dequeue()
    {
        if(head==NULL)
            return -1;
        else
        {
            int t=head->data;
            head=head->next;
            size--;
            return t;
        }
        // Implement the dequeue() function
    }

    int front() 
    {
        if(head==NULL)
            return -1;
        else
        return head->data;
        // Implement the front() function
    }
};


int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}