/*

Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.


*/
#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


class BST 
{
    BinaryTreeNode<int>* root;
    // Define the data members
   public:
    BST() { 
        root=NULL;
        // Implement the Constructor
    }

	/*----------------- Public Functions of BST -----------------*/

    private:
    BinaryTreeNode<int> *remove(BinaryTreeNode<int>* root,int data)
    {
        if(root==NULL)
            return NULL;
        if(root->data==data)
        {
            if(root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }
            else if(root->left==NULL)
            {
                BinaryTreeNode<int>* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                BinaryTreeNode<int>* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int>* temp=root->right;
                while(temp->left!=NULL)
                    temp=temp->left;
                int rightNode=temp->data;
                root->data=rightNode;
                root->right=remove(root->right,rightNode);
                return root;
            }
        }
        else if(data>root->data)
        {
            root->right=remove(root->right,data);
            return root;
        }
       else 
       {
            root->left=remove(root->left,data);
           return root;
    }
    }
    public:
    void remove(int data) 
    { 
        this->root=remove(root,data);
        // Implement the remove() function 
    }

    private:
    void print(BinaryTreeNode<int>*root)
    {
        if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L:" << root->left->data<<",";
		}

		if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		print(root->left);
		print(root->right);
    }
    public:
    void print()
    { 
        print(root);
        // Implement the print() function
    }

    private:
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *root,int data)
    {
        if(root==NULL)
        {
            BinaryTreeNode<int> *newNode=new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if(data<=root->data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
        return root;
    }
    public:
    void insert(int data) 
    { 
       this->root=insert(root,data);
        // Implement the insert() function 
    }

    private:
    bool search(BinaryTreeNode<int>* root,int data)
    {
        if(root==NULL)
        return false;
        if(root->data==data)
            return true;
        if(root->data>data)
            return search(root->left,data);
        else
            return search(root->right,data);
    }
    public:
    bool search(int data)
    {
        return search(root,data);
		// Implement the search() function 
    }
};


int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}