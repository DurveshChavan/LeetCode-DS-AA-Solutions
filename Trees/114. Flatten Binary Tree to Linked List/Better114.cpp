/*
------------------------------------------------------------------------------------------------
Solution for the LeetCode Problem 114.
------------------------------------------------------------------------------------------------
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
class Solution {
    // Using Stack
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        stack<TreeNode*> St;
        St.push(root);
        while(!St.empty()){
            TreeNode* Cur = St.top(); 
            St.pop();

            if(Cur->right)
                St.push(Cur->right);
                
            if(Cur->left)
                St.push(Cur->left);
            
            if(!St.empty())
                Cur->right = St.top();

            Cur->left = nullptr;
        }
    }
};
*/
/*
------------------------------------------------------------------------------------------------
Program for the LeetCode Problem 114.
------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
    // Using Stack
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;

        stack<TreeNode*> St;
        St.push(root);
        while(!St.empty()){
            TreeNode* Cur = St.top();
            St.pop();

            if(Cur->right)
                St.push(Cur->right);
                
            if(Cur->left)
                St.push(Cur->left);
            
            if(!St.empty())
                Cur->right = St.top();

            Cur->left = nullptr;
        }
    }
};

// Utility function to split a string by a delimiter.
vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        // Remove any spaces.
        token.erase(remove(token.begin(), token.end(), ' '), token.end());
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}

// Builds a binary tree from a level-order string input (e.g. "[1,2,5,3,4,null,6]").
TreeNode* buildTree(const string &input) {
    // Remove the leading '[' and trailing ']'
    string s = input;
    s.erase(remove(s.begin(), s.end(), '['), s.end());
    s.erase(remove(s.begin(), s.end(), ']'), s.end());

    vector<string> tokens = split(s, ',');
    if (tokens.empty() || tokens[0] == "null")
        return nullptr;

    TreeNode* root = new TreeNode(stoi(tokens[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;

    while (!q.empty() && index < tokens.size()) {
        TreeNode* node = q.front();
        q.pop();

        // Process left child.
        if (index < tokens.size() && tokens[index] != "null") {
            node->left = new TreeNode(stoi(tokens[index]));
            q.push(node->left);
        }
        index++;

        // Process right child.
        if (index < tokens.size() && tokens[index] != "null") {
            node->right = new TreeNode(stoi(tokens[index]));
            q.push(node->right);
        }
        index++;
    }
    return root;
}

// Formats the flattened tree into the required output format.
// Output: [1,null,2,null,3,null,4,null,5,null,6]
string flattenOutput(TreeNode* root) {
    string output = "[";
    TreeNode* curr = root;
    while (curr) {
        output += to_string(curr->val);
        // Append ",null," between nodes except after the last one.
        if (curr->right)
            output += ",null,";
        curr = curr->right;
    }
    output += "]";
    return output;
}

int main() {
    // Input: [1,2,5,3,4,null,6]
    cout << "Enter tree input (e.g. [1,2,5,3,4,null,6]): ";
    string input;
    getline(cin, input);

    TreeNode* root = buildTree(input);

    Solution sol;
    sol.flatten(root);

    // Output the flattened tree.
    string result = flattenOutput(root);
    cout << "Flattened Tree: " << result << endl;

    return 0;
}
