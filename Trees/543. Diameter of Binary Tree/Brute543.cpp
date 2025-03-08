/*
------------------------------------------------------------------------------------------------
Solution for the LeetCode Problem 543.
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
public:
    // Global variable to store the diameter
    int diameter = 0;  

    // Function to calculate the height of a subtree
    int calculateHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        // Calculate the diameter at the current node and update the global variable
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Start the recursive traversal from the root
        calculateHeight(root);
        // Return the maximum diameter found during traversal
        return diameter;
    }
};
*/
/*
------------------------------------------------------------------------------------------------
Program for the LeetCode Problem 543.
------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <sstream>
#include <queue>
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
    // Global variable to store the diameter
    int diameter = 0;  

    // Function to calculate the height of a subtree
    int calculateHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        // Calculate the diameter at the current node and update the global variable
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Start the recursive traversal from the root
        calculateHeight(root);
        // Return the maximum diameter found during traversal
        return diameter;
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

// Builds a binary tree from a level-order string input (e.g. "[1,2,3,4,5,null,null]").
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

// Formats the diameter output.
string diameterOutput(int diameter) {
    return to_string(diameter);
}

int main() {
    // Example input: [1,2,3,4,5,null,null]
    cout << "Enter tree input (e.g. [1,2,3,4,5,null,null]): ";
    string input;
    getline(cin, input);

    TreeNode* root = buildTree(input);

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);
    cout << "Diameter of Binary Tree: " << diameterOutput(result) << endl;

    return 0;
}
