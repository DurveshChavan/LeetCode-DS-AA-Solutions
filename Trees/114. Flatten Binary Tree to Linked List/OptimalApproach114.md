# 🌳 Optimal Approach: Flatten Binary Tree to Linked List 📝

This document outlines the optimal approach to flatten a binary tree into a linked list in-place. This problem is commonly known as "114. Flatten Binary Tree to Linked List" on LeetCode. The goal is to transform the tree so that it resembles a linked list, where each node's right child points to the next node in a preorder traversal sequence, and the left child is always set to null.

## 🎯 Problem Recap

You are given the root of a binary tree, and your task is to flatten it into a "linked list" with the following rules:
- The right child pointer of each node should point to the next node in the list.
- The left child pointer of each node should be set to null.
- The order of nodes in the flattened list must match the preorder traversal of the original tree (root, left subtree, right subtree).

### 📊 Example

Consider the following binary tree as input:
```
    1
   / \
  2   5
 / \   \
3   4   6
```

After flattening, the tree should look like this (shown as a linked list):
```
1 -> 2 -> 3 -> 4 -> 5 -> 6
```

In terms of tree representation, it becomes:
```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```

When represented as an array (ignoring null left pointers), it is:
```
[1, null, 2, null, 3, null, 4, null, 5, null, 6]
```

## 🚀 Optimal Approach: Iterative In-Place Flattening

The optimal solution uses an iterative method to rearrange the tree's pointers in-place, meaning no extra data structures (like stacks or arrays) are needed beyond a few pointer variables. The approach modifies the tree step-by-step while preserving the preorder traversal order.

### 🧩 Algorithm Overview

Here's how the algorithm works:

1. **Start at the Root** 🌱: Use a pointer called `curr` initialized to the root of the tree.
2. **Loop Until Done** 🔄: Continue processing nodes until `curr` becomes null.
3. **Handle the Left Subtree** ⬅️: For each node:
   - If the current node has a left child:
     - Find the rightmost node in the left subtree.
     - Attach the current node's right subtree to this rightmost node's right pointer.
     - Move the entire left subtree to the current node's right pointer.
     - Set the current node's left pointer to null.
4. **Move Forward** ➡️: Advance `curr` to the right child, which now points to the next node in the flattened list.
5. **Repeat** 🔁: Continue this process until all nodes are processed.

This approach ensures that the tree is flattened in-place, following the preorder sequence, without requiring recursion or additional memory.

### 💻 Pseudocode

Here's the complete pseudocode in C++:

```cpp
TreeNode* curr = root;  // Start at the root of the tree
while (curr != NULL) {  // Continue until all nodes are processed
    if (curr->left != NULL) {  // If there's a left child
        // Step 1: Find the rightmost node in the left subtree
        TreeNode* pre = curr->left;
        while (pre->right != NULL) {
            pre = pre->right;
        }
        // Step 2: Connect the original right subtree to the rightmost node
        pre->right = curr->right;
        // Step 3: Move the left subtree to the right side
        curr->right = curr->left;
        // Step 4: Set the left child to null
        curr->left = NULL;
    }
    // Step 5: Move to the next node in the flattened list
    curr = curr->right;
}
```

### 🔍 How It Works Step-by-Step (Using the Example)

Let's walk through the example tree:
```
    1
   / \
  2   5
 / \   \
3   4   6
```

#### Step 1: Start with Root Node 🌱
**Initial State**: `curr = 1`
   - 1 has a left child (2).
   - Find the rightmost node in the left subtree (2 -> 4).
   - Connect 4->right = 5 (the original right child of 1).
   - Move 2 to 1->right.
   - Set 1->left = null.
   - Tree becomes:
     ```
     1
      \
       2
      / \
     3   4
          \
           5
            \
             6
     ```
   - Move `curr = 2`.

#### Step 2: Process Node 2 🔄
**Next Iteration**: `curr = 2`
   - 2 has a left child (3).
   - Rightmost node in left subtree is 3 (no right child).
   - Connect 3->right = 4 (the original right child of 2).
   - Move 3 to 2->right.
   - Set 2->left = null.
   - Tree becomes:
     ```
     1
      \
       2
        \
         3
          \
           4
            \
             5
              \
               6
     ```
   - Move `curr = 3`.

#### Step 3: Finish Processing ✅
**Next Iterations**: `curr = 3, 4, 5, 6`
   - None of these nodes have a left child, so `curr` simply moves to the right each time.
   - Eventually, `curr = null`, and the loop ends.
   - The tree is now fully flattened into 1 -> 2 -> 3 -> 4 -> 5 -> 6.

## 📊 Complexity Analysis

### ⏱️ Time Complexity:
Each node in the tree is visited exactly once. For each node with a left child, we also traverse its left subtree to find the rightmost node, but this is still proportional to the number of nodes. Thus, the total time complexity is **O(n)**, where n is the number of nodes in the tree.

### 🧠 Space Complexity:
The algorithm only uses a constant amount of extra space for the `curr` and `pre` pointers, regardless of the tree's size. No recursion or additional data structures are used, so the space complexity is **O(1)**.

## 👍 Advantages of This Approach

### 💪 In-Place Modification:
The tree is restructured directly by adjusting pointers, without requiring extra memory for storing nodes or a traversal sequence. This makes it highly memory-efficient.

### 🔄 Iterative Solution:
Unlike recursive approaches, which could risk stack overflow for very deep trees, this iterative method uses a simple loop, making it more robust and scalable.

### 🧩 Simplicity and Clarity:
The logic is straightforward—rearrange subtrees one node at a time—making it easy to implement and debug.

## 🏁 Conclusion

This iterative in-place approach provides an efficient and elegant solution to flatten a binary tree into a linked list. With a time complexity of O(n) and a space complexity of O(1), it meets the problem's requirements while minimizing resource usage. The method's iterative nature also ensures reliability, even for large or unbalanced trees. This makes it an excellent choice for both learning and practical implementation.

Happy Coding! 🎉
