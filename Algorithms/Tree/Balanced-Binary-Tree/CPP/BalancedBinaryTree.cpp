/*
Algorithm:          Balanced Binary Tree (LeetCode Problem #110)

Task:               Given a binary tree, determine if it is height-balanced. A height-balanced binary tree is a binary tree in which the 
                    depth of the two subtrees of every node never differs by more than one.

Solution:           Use recursion to determine if each node in the given binary tree produces a height-balanced binary tree. To do this, 
                    we first must find the depth of the current node's left and right subtree and calculate the absolute difference of the 
                    depth values. If the absolute difference is 0 or 1, the current node creates a height-balanced tree, which means we can
                    move on to determine if the current node's child nodes also create height-balanced trees via recursion. If the absolute
                    difference is ever greater than 1, then the tree cannot be considered height-balanced and false is returned; otherwise, 
                    true is returned.

Time complexity:    O(N * log(N))
                        N = number of nodes in binary tree

Space complexity:   O(N)
                        N = number of nodes in binary tree / maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https://leetcode.com/problems/balanced-binary-tree/solutions/
*/


#include <iostream>
#include <cmath>
using std::cout;
using std::endl;
using std::max;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Calculate the depth of the current subtree.
int getDepth(TreeNode* current)
{
    // Base case; If current node is null, return 0.
    if (!current)
        return 0;
    
    int left = getDepth(current->left);
    int right = getDepth(current->right);

    return max(left, right) + 1;
}

// Recursively check each node in the tree to see if its subtrees are balanced.
bool isBalanced(TreeNode* root) 
{
    // Base case; if the current node is null, return.
    if (!root)
        return true;
    
    // Find the depth of the left and right subtrees and find their absolute difference.
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);
    int difference = abs(leftDepth - rightDepth);

    // If difference <= 1, the tree created with root is height-balanced. Move on to check if the left child and right child of root are
    // also height-balanced.
    if (difference <= 1)
    {
        if (isBalanced(root->left) && isBalanced(root->right))
            return true;
        else
            return false;
    }
    // If difference > 1, the current tree created with root is not height-balanced. Return false.
    else
        return false;
}

// Delete all nodes in a tree.
void clearTree(TreeNode* root)
{
    if (root != nullptr)
    {
        clearTree(root->left);
        clearTree(root->right);
        delete root;
    }
}

int main()
{
    // Test case 1. Empty tree.
    (isBalanced(nullptr)) ? cout << "Tree is height-balanced.\n" : cout << "Tree is not height-balanced.\n";
    

    /* Test case 2. Create the binary tree below:
                  3
                /   \
               9     20
                    /  \
                   15   7
    */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    (isBalanced(root)) ? cout << "Tree is height-balanced.\n" : cout << "Tree is not height-balanced.\n";
    clearTree(root);


    /* Test case 3. Create the binary tree below:
                1
               / \
              2   2
             / \
            3   3
           / \
          4   4
    */
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    (isBalanced(root)) ? cout << "Tree is height-balanced.\n" : cout << "Tree is not height-balanced.\n";
    clearTree(root);


    /* Test case 4. Create the binary tree below:
                1
               / \
              2   2
             /     \
            3       3
           /         \
          4           4
    */
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->right->right->right = new TreeNode(4);
    (isBalanced(root)) ? cout << "Tree is height-balanced.\n" : cout << "Tree is not height-balanced.\n";
    clearTree(root);

    return 0;
}