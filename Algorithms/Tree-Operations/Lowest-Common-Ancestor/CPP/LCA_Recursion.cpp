/*
Algorithm:          Lowest Common Ancestor of a Binary Search Tree using Recursion (Leetcode Problem #235)

Task:               Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes p and q in the BST. 
                    Assume that p and q will always exist in the BST. The lowest common ancestor is defined between two nodes p and q as 
                    the lowest node in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself).

Solution:           When traversing a binary tree from the root to find a node, multiple nodes are typically visited before the target 
                    node is found. To solve this problem, we can traverse the binary tree from the root to find nodes p and q. Any node 
                    that must be visited when searching for both p and q can be considered a common ancestor of the two nodes. We can 
                    keep track of each common ancestor during the traversal; the last node common ancestor node that is visited during
                    the traversal is considered the lowest common ancestor.

Time complexity:     O(log(N))
                        N = number of nodes in the binary search tree

Space complexity:   O(N)
                        N = number of nodes in the binary search tree / maximum depth of the recursive call stack
                     
Auxiliary space:    O(N)
                        N = number of nodes in the binary search tree

Resources:          https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/solutions/
                    https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
*/

#include <iostream>
using std::cout;
using std::endl;

//Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
{
    // If the BST is empty, return nullptr.
    if (root == nullptr)
        return nullptr;

    // If root is greater than both p and q, move to the left node.
    if (root->val > p->val && root->val > q->val)
        return lowestCommonAncestor(root->left, p, q);
    // If root is less than both p and q, move to the right node.
    else if (root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);

    // Base case; if either p->val or q-> is equal to root->val, return root.
    return root;
}

int main()
{
    /*  Create the binary tree below:
                     6
                   /   \
                  2     8
                 / \   / \
                0   4 7   9
               / \
              3   5
    */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != nullptr)
        cout << "Lowest common ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;
    delete p;
    delete q;

    p = new TreeNode(2);
    q = new TreeNode(4);
    lca = lowestCommonAncestor(root, p, q);
    if (lca != nullptr)
        cout << "Lowest common ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;
    delete p;
    delete q;

    return 0;
}