#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


int getHeight(TreeNode<int>* root) 
{
    if(root==NULL)
        return 0;
    // Write your code here
    int maximum=0;
    for(int i=0;i<root->children.size();i++)
    {
        int childMax=getHeight(root->children[i]);
        maximum=max(maximum,childMax);
    }
    return maximum+1;
    
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << getHeight(root);
}

/*

Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3

*/