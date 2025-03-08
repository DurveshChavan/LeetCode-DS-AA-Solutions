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
    int diameterOfBinaryTree(TreeNode* root) {
        // Map to store the height of each node
        unordered_map<TreeNode*, int> heightMap;
        
        // First pass: Calculate and store heights
        calculateHeights(root, heightMap);
        
        // Second pass: Compute the maximum diameter
        return findMaxDiameter(root, heightMap);
    }

private:
    // Function to calculate and store heights in the map
    void calculateHeights(TreeNode* node, unordered_map<TreeNode*, int>& heightMap) {
        if (node == nullptr) {
            return;
        }
        // Post-order traversal: process left, then right, then current node
        calculateHeights(node->left, heightMap);
        calculateHeights(node->right, heightMap);
        int leftHeight = (node->left ? heightMap[node->left] : 0);
        int rightHeight = (node->right ? heightMap[node->right] : 0);
        heightMap[node] = 1 + max(leftHeight, rightHeight);
    }
    
    // Function to find the maximum diameter using precomputed heights
    int findMaxDiameter(TreeNode* node, unordered_map<TreeNode*, int>& heightMap) {
        if (node == nullptr) {
            return 0;
        }
        // Get heights of left and right subtrees from the map
        int leftHeight = (node->left ? heightMap[node->left] : 0);
        int rightHeight = (node->right ? heightMap[node->right] : 0);
        // Diameter passing through the current node
        int diameterThroughNode = leftHeight + rightHeight;
        // Recursively find maximum diameter in left and right subtrees
        int leftMax = findMaxDiameter(node->left, heightMap);
        int rightMax = findMaxDiameter(node->right, heightMap);
        // Return the maximum of the three possibilities
        return max({diameterThroughNode, leftMax, rightMax});
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
#include <unordered_map>

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
    int diameterOfBinaryTree(TreeNode* root) {
        // Map to store the height of each node
        unordered_map<TreeNode*, int> heightMap;
        
        // First pass: Calculate and store heights
        calculateHeights(root, heightMap);
        
        // Second pass: Compute the maximum diameter
        return findMaxDiameter(root, heightMap);
    }

private:
    // Function to calculate and store heights in the map
    void calculateHeights(TreeNode* node, unordered_map<TreeNode*, int>& heightMap) {
        if (node == nullptr) {
            return;
        }
        // Post-order traversal: process left, then right, then current node
        calculateHeights(node->left, heightMap);
        calculateHeights(node->right, heightMap);
        int leftHeight = (node->left ? heightMap[node->left] : 0);
        int rightHeight = (node->right ? heightMap[node->right] : 0);
        heightMap[node] = 1 + max(leftHeight, rightHeight);
    }
    
    // Function to find the maximum diameter using precomputed heights
    int findMaxDiameter(TreeNode* node, unordered_map<TreeNode*, int>& heightMap) {
        if (node == nullptr) {
            return 0;
        }
        // Get heights of left and right subtrees from the map
        int leftHeight = (node->left ? heightMap[node->left] : 0);
        int rightHeight = (node->right ? heightMap[node->right] : 0);
        // Diameter passing through the current node
        int diameterThroughNode = leftHeight + rightHeight;
        // Recursively find maximum diameter in left and right subtrees
        int leftMax = findMaxDiameter(node->left, heightMap);
        int rightMax = findMaxDiameter(node->right, heightMap);
        // Return the maximum of the three possibilities
        return max({diameterThroughNode, leftMax, rightMax});
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
