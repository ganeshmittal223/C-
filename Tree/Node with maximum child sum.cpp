/*
Node with maximum child sum
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.

Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1

*/

#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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
template <typename T>
class maxpair{
    
    public:
    
    TreeNode<T> *node;
    int sum;
    
};

maxpair<int> *helper(TreeNode<int> *root){
    
    if( root == NULL ){
        
        maxpair<int> *p1 = new maxpair<int>();
        p1->sum = INT_MIN;
        p1->node = NULL;
        return p1;
        
    }
    
    int sum = root->data;
    for( int i =0 ; i < root->children.size() ; ++i ){
        
        sum += root->children[i]->data;
        
    }
    
    maxpair<int> *ans = new maxpair<int>();
    ans->sum = sum;
    ans->node = root;
    
    for( int i = 0 ;i < root->children.size() ; ++i ){
        
        maxpair<int> *p2 = helper(root->children[i]);
        if( p2->sum > sum ){
            ans = p2;
        }
        
    }
    
    return ans;
    
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {

    return helper(root)->node;
    
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

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}