/*
Largest BST
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2

*/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;


#include<climits>
#include<cmath>

class Pair
{
    public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
};

Pair BST(BinaryTreeNode<int> *root)
{
    if(root==NULL)
    {
       Pair obj;
        obj.minimum =INT_MAX;
        obj.maximum = INT_MIN;
        obj.isBST = true;
        obj.height=0;
    return obj;

    }
    
    Pair left=BST(root->left);
    Pair right=BST(root->right);
    
    int minimum=min(root->data,min(left.minimum,right.minimum));
    int maximum=max(root->data,max(left.maximum,right.maximum));
    bool isBSTfinal=(root->data>left.maximum) && (root->data<right.minimum) && left.isBST && right.isBST;
    
    Pair object;
    object.minimum=minimum;
    object.maximum=maximum;
    object.isBST=isBSTfinal;
    
    if(isBSTfinal)
        object.height=1+max(left.height,right.height);
    else
        object.height=max(left.height,right.height);
    
    return object;
    
}



int largestBSTSubtree(BinaryTreeNode<int> *root) 
{
    
    return BST(root).height;
    
    // Write your code here
}


BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
