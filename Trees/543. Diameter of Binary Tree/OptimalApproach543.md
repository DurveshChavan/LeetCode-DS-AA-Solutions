# 🌳 Optimal Approach: Diameter of a Binary Tree 📝

This document outlines the optimal approach to find the diameter of a binary tree. The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

## 🎯 Problem Recap

Given the root of a binary tree, the task is to compute its diameter. The diameter of a tree is the number of nodes on the longest path between any two nodes. More specifically, for each node, the longest path that passes through that node is the sum of the heights of its left and right subtrees. The final answer is the maximum such sum for all nodes in the tree.

### 📊 Example

Consider the following binary tree:
```
      1
     / \
    2   3
   / \
  4   5
```

- The height of the left subtree of node `1` (root) is 2 (from node 2 down to node 4 or 5).
- The height of the right subtree of node `1` is 1 (node 3).

For node `1`, the path through it would have a length of `2 + 1 = 3` (number of edges, or 4 nodes if counting nodes). However, depending on the problem statement, you might define diameter in terms of edges or nodes. In our implementation, the diameter is represented by the sum of heights (i.e., the number of edges).

## 🚀 Optimal Approach: Recursive Height Calculation

The optimal solution leverages a recursive approach that computes the height of each subtree while simultaneously updating the maximum diameter found. This allows the algorithm to run in a single pass over the tree.

### 🧩 Algorithm Overview

Here's how the algorithm works:

1. **Recursive Height Function** 🌱: Define a helper function `height` that:
   - Returns 0 for a null node.
   - Recursively computes the heights of the left and right subtrees.
   - Updates the global `diameter` with the maximum value between the current diameter and the sum of left and right heights.
   - Returns the height of the current node, which is `1 + max(left_height, right_height)`.

2. **Calculate Diameter** 🔍:
   - Start the recursion from the root node.
   - The recursive calls will traverse every node, ensuring that every potential diameter (longest path through each node) is evaluated.
   - After the recursion completes, the global `diameter` variable contains the maximum diameter of the tree.

### 💻 Pseudocode

Below is the complete pseudocode in C++:

```cpp
int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int height(TreeNode* node, int& diameter) {
    if (!node) return 0;  // Base case: empty tree has height 0

    // Recursively calculate the heights of the left and right subtrees
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    // Update the diameter: the sum of left and right heights
    diameter = max(diameter, lh + rh);

    // Return the height of the current node
    return 1 + max(lh, rh);
}
```

### 🔍 How It Works Step-by-Step (Using the Example)

Let's walk through the example tree:
```
      1
     / \
    2   3
   / \
  4   5
```

1. **Starting at Node 4 and Node 5**:
   - Both nodes are leaves, so their heights are 0.
   - Their parent's (node 2) left and right heights are computed as 1 each (1 + 0).

2. **At Node 2**:
   - The left height is 1 (from node 4) and the right height is 1 (from node 5).
   - The path through node 2 is `1 + 1 = 2`, and `diameter` is updated accordingly.
   - The height of node 2 becomes `1 + max(1, 1) = 2`.

3. **At Node 3**:
   - Being a leaf, its height is 1.

4. **At the Root Node (1)**:
   - The left height is 2 (from node 2) and the right height is 1 (from node 3).
   - The path through node 1 is `2 + 1 = 3`, so `diameter` is updated to 3.
   - The final height of the tree is `1 + max(2, 1) = 3`.

## 📊 Complexity Analysis

### ⏱️ Time Complexity:
Each node in the tree is visited exactly once. The recursive function performs a constant amount of work for each node, leading to a time complexity of **O(n)**, where `n` is the number of nodes.

### 🧠 Space Complexity:
The space complexity is determined by the recursion stack. In the worst-case scenario (a skewed tree), the recursion depth could be `n`, resulting in **O(n)** space. For balanced trees, the height of the tree is **O(log n)**.

## 👍 Advantages of This Approach

### 💪 Single-Pass Computation:
The algorithm calculates both the height of the tree and the diameter in one traversal, which is both time-efficient and elegant.

### 🔄 Simplicity:
The recursive approach is straightforward to implement and understand, reducing potential bugs and making the code easier to maintain.

### 🧩 Robustness:
This method naturally handles trees of various shapes and sizes, from balanced trees to degenerate (skewed) trees, ensuring correctness in all cases.

## 🏁 Conclusion

This recursive approach provides an efficient and clear solution to calculate the diameter of a binary tree. By computing the height and updating the diameter in a single pass, the solution achieves a time complexity of **O(n)** while keeping the code simple and intuitive. This makes it a robust method for both learning and practical implementations.

Happy Coding! 🎉
