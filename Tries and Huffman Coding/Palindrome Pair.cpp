/*

Palindrome Pair
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything

Sample Input 1 :
4
abc def ghi cba
Sample Output 1 :
true
Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome
Sample Input 2 :
2
abc def
Sample Output 2 :
false
Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'


*/


#include <bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

//     bool isPalindromePair(vector<string> words) {
//         // Write your code here
//     }
    
    
    
    string reverse(string in){
        string out="";
        for(int i=in.size()-1;i>=0;i--)
            out+=in[i];
        return out;
    }
    
    bool search(TrieNode* root,string word){
        
        if(word.size()==0 ){
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        
        bool ans;
        if(root->children[index]!=NULL)
            ans=search(root->children[index],word.substr(1));
        else
            ans=false;
        return ans;
    }
	

	bool isPalindromePair(vector<string> arr) {
		// Complete this function
		// Return true or false.
        
        //Store all the words first before searching it's reverse
        for(int i=0;i<arr.size();i++)
            this->add(arr[i]);
        bool ans;
        for(int i=0;i<arr.size();i++){
            string out=reverse(arr[i]);
            
            ans=search(root,out) || search(root,out.substr(1)); //Pallindrom can have odd number of letters
            if(ans)
                break;
            if(search(root,reverse(arr[i].substr(1))))
                return true;
        }
        return ans;
           
        
	}
    
};
int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}