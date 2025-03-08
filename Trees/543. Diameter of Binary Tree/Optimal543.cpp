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
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the variable to store the diameter of the tree
        int diameter = 0;
        // Call the height function to traverse the tree and calculate diameter
        height(root, diameter);
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of the tree and update the diameter
    int height(TreeNode* node, int& diameter) {
        // Base case: If the node is null, return 0 indicating the height of an empty tree
        if (!node) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum of current diameter or sum of left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of the current node's subtree
        return 1 + max(lh, rh);
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
    // Function to find the diameter of a binary tree
    int diameterOfBinaryTree(TreeNode* root) {
        // Initialize the variable to store the diameter of the tree
        int diameter = 0;
        // Call the height function to traverse the tree and calculate diameter
        height(root, diameter);
        // Return the calculated diameter
        return diameter;
    }

private:
    // Function to calculate the height of the tree and update the diameter
    int height(TreeNode* node, int& diameter) {
        // Base case: If the node is null, return 0 indicating the height of an empty tree
        if (!node) {
            return 0;
        }

        // Recursively calculate the height of left and right subtrees
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        // Update the diameter with the maximum of current diameter or sum of left and right heights
        diameter = max(diameter, lh + rh);

        // Return the height of the current node's subtree
        return 1 + max(lh, rh);
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
