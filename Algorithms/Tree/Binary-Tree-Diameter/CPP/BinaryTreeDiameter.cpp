/*
Algorithm:          Diameter of Binary Tree (LeetCode Problem #543)

Task:               Given the root of a binary tree, return the length of the diameter of the tree. The diameter of a binary tree is the
                    length of the longest path between any two nodes in a tree. This path may or may not pass through the root. The 
                    length of a path between two nodes is represented by the number of edges between them.

Solution:           

Time complexity:    

Space complexity:   

Auxiliary space:    

Resources:          
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

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}

int maxDepth(TreeNode* root, int& diameter){
    if (root == nullptr)
        return 0;
    
    int leftDepth = maxDepth(root->left, diameter);
    int rightDepth = maxDepth(root->right, diameter);

    diameter = std::max(diameter, leftDepth + rightDepth);

    return std::max(leftDepth, rightDepth) + 1;
}

int main()
{
    
    return 0;
}