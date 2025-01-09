/*
Algorithm:          Maximum Depth of Binary Tree (LeetCode Problem #104)

Task:               Given the root of a binary tree, return its maximum depth. A binary tree's maximum depth is the number of nodes 
                    along the longest path from the root node down to the farthest leaf node.

Solution:           Use the recursive depth-first search (DFS) algorithm to traverse from the root node to the farthest leaf node in the
                    left and right subtrees. Use recursion to count the number of nodes that are visited during the traversal of the 
                    subtrees, then return the highest node count. 

Time complexity:    O(log(N))
                        N = number of nodes in the binary tree

Space complexity:   O(N)
                        N = number of nodes in the binary tree / maximum depth of the recursive call stack

Auxiliary space:    O(N)
                        N = maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
                    https://leetcode.com/problems/maximum-depth-of-binary-tree/solutions/
*/


#include <iostream>
using std::cout;
using std::endl;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) 
{
    if (root == nullptr)
        return 0;
    
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return std::max(leftDepth, rightDepth) + 1;
}

int main() 
{

    return 0;
}