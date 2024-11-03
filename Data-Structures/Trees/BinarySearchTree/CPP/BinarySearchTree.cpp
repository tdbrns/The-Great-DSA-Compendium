/*
Structure:          Binary Search Tree 
Task:               Create a binary tree that is organized so that the integers on the left side of the tree are less than the 
                    integers on the right side of the tree.
Solution:           Create a binary search tree.
Resources:          https://www.geeksforgeeks.org/introduction-to-binary-search-tree/
*/

#include <iostream>
#include <queue>
using std::cout;
using std::endl;

// A struct with the attributes of a node in a binary search tree.
struct TreeNode
{
    int data;               // Integer value of a TreeNode.
    TreeNode* left;         // The left child of a TreeNode.
    TreeNode* right;        // The right child of a TreeNode.

    TreeNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// A class for performing binary search tree operations on a node.
class BinarySearchTree
{
private:
    TreeNode* _root;        // The root node of the tree.
    int _size;              // The number of nodes in the tree.

    // Find and return the node that succeeds the current node in an inorder traversal.
    TreeNode* _getSuccessor(TreeNode* current)
    {
        current = current->right;
        while (current != nullptr && current->left != nullptr)
            current = current->left;
        
        return current;
    }

    // Find and return a node with the target value using recursion.
    TreeNode* _findNode(TreeNode* current, int target)
    {
        // If the current node is null, the target value could not be found; if the data of the current node matches the
        // target value, the target has been found.
        if (current == nullptr || current->data == target)
            return current;
        
        // If the data of the current node is greater than the target value, check the current node's left child.
        if (current->data > target)
            return _findNode(current->left, target);
        
        // If the data of the current node if less than the target value, check the current node's right child.
        return _findNode(current->right, target);
    }

    // Insert a new node with data into the tree using recursion.
    TreeNode* _insertNode(TreeNode* current, int newData)
    {
        // Once an empty spot has been found, insert the new node in that spot by returning the node. If _insertNode() was called
        // recursively, all the previously visited nodes will be updated to accommodate the new node. 
        if (current == nullptr)
        {
            // If the tree is empty, insert the new node as the root of the tree.
            if (_root == nullptr)
            {
                _root = new TreeNode(newData);
                return _root;
            }
            return new TreeNode(newData);
        }

        // Reject any values that are already in the tree. The insert() method already does this.
        // if (current->data == newData)
        //     return nullptr;
        
        // If the new data is less than the data of the current node, insert the data as the left child of the current node.
        if (current->data > newData)
            current->left = _insertNode(current->left, newData);
        // If the new data is greater than the data of the current node, insert the data as the right child of the current node.
        else
            current->right = _insertNode(current->right, newData);
        
        // Return the current node and its updated pointers
        return current;
    }

    // Remove a node with the target value from the tree.
    TreeNode* _removeNode(TreeNode* current, int target)
    {
        // If _removeNode() was called recursively and the target node exists, the final recursive pass will delete the target node
        // and return the node that will replace it. Then, all the nodes visited in the previous recursive passses will be updated
        // to accommodate the replacement node.
        // NOTE: the node that replaces the target node will the one that succeeds it in an inorder traversal.

        // Base case.
        if (current == nullptr)
            return current;
        
        // If the data of the current node is greater than or less than the target value, move down the left or right branch to
        // find the node that matches the target value.
        if (current->data > target)
            current->left = _removeNode(current->left, target);
        else if (current->data < target)
            current->right = _removeNode(current->right, target);

        // When the data of the current node matches the target value...
        else
        {
            // If the current node has no left child or has no children at all...
            if (current->left == nullptr)
            {
                // If the current node has a right child, replacement = right child.
                // If the current node has 0 children, replacement = nullptr.
                TreeNode* replacement = current->right;
                // Delete the current node.
                delete current;
                _size--;

                // Return the replacement node.
                return replacement;
            }
            else if (current->right == nullptr)
            {
                // If the current node has a left child, replacement = left child.
                TreeNode* replacement = current->left;
                // Delete the current node.
                delete current;
                _size--;

                // Return the replacement node.
                return replacement;
            }
            // If the current node has both children...

            // Copy the data of the successor node to the current node and then delete the successor node.
            current->data = _getSuccessor(current)->data;
            current->right = _removeNode(current->right, current->data);
        }

        // Return the current node with its updated left and right children.
        return current;
    }

    // Recursively invert binary tree
    TreeNode* _invertTree(TreeNode* current)
    {
        if (current == nullptr)
            return nullptr;

        TreeNode* leftChild = _invertTree(current->left);        // Left node of the current node after all its children are inverted.
        TreeNode* rightChild = _invertTree(current->right);      // Right node of the current node after all its children are inverted.

        // Swap the left the left child and the right child.
        current->left = rightChild;
        current->right = leftChild;

        // Return the current node with its updated left and right children.
        return current;
    }

    // Recursively delete every node in the tree through a postorder traversal.
    void _clearTree(TreeNode* current)
    {
        if (current != nullptr)
        {
            _clearTree(current->left);
            _clearTree(current->right);
            delete current;
        }
    }

public:
    // Constructors
    BinarySearchTree() : _root(nullptr), _size(0) {}
    BinarySearchTree(TreeNode* root) : _root(root), _size(0) {}

    // Destructor
    ~BinarySearchTree() { _clearTree(_root); }

    // Wrapper for the _findNode method.
    bool find(TreeNode* current, int target)
    {
        // If a node with the target data exists in the tree, return true; otherwise, return false.
        if (_findNode(current, target) != nullptr)
            return true;
        return false;
    }

    // Wrapper for the _inserNode method.
    bool insert(TreeNode* current, int newData)
    {
        // If there isn't already a node with newData, insert a new node with the data and return true; otherwise, return false.
        if (_findNode(current, newData) == nullptr)
        {
            _insertNode(current, newData);
            return true;
        }
        return false;
    }

    // Wrapper for the _removeNode method.
    bool remove(TreeNode* current, int target)
    {
        // If a node with the target data exists in the tree, remove the node and return true; otherwise, return false.
        if (_findNode(current, target) != nullptr)
        {
            _removeNode(current, target);
            return true;
        }
        return false;
    }

    bool invert(TreeNode* current)
    {
        // If the inverted tree exists, return true; otherwise, return false.
        if (_invertTree(current) != nullptr)
            return true;
        return false;
    }

    // Print out all the values in the tree through an inorder traversal.
    void traverseInOrder(TreeNode* current)
    {
        if (current != nullptr)
        {
            traverseInOrder(current->left);
            cout << current->data << " ";
            traverseInOrder(current->right);
        }
    }

    /*  Steps for Recursive Inorder Traversal
        1.  curr = 50; traverse(curr->left)
        2.  curr = 30; traverse(curr->left)
        3.  curr = 20; traverse(curr->left)
        4.  curr = null; return
        5.  curr = 20; print(20); traverse(curr->right)
        6.  curr = null; return
        7.  curr = 20; return
        8.  curr = 30; print(30); traverse(curr-right)
        9.  curr = 40; traverse(curr-left)
        10. curr = null; return
        11. curr = 40; print(40); traverse(curr->right)
        12. curr = null; return
        13. curr = 40; return
        14. curr = 30; return
        15. curr = 50; print(50); traverse(curr->right)
        16. curr = 70; traverse(curr->left)
        17. curr = 60; traverse(curr->left)
        18. curr = null; return
        19. curr = 60; print(60); traverse(curr->right)
        20. curr = null; return
        21. curr = 60; return
        22. curr = 70; print(70); traverse(curr->right)
        23. curr = null; return
        24. curr = 70; return
    */

    // Print out all the values in the tree through a preorder traversal (depth-first search).
    void traversePreOrder(TreeNode* current)
    {
        if (current != nullptr)
        {
            cout << current->data << " ";
            traversePreOrder(current->left);
            traversePreOrder(current->right);
        }
    }

    // Print out all the values in the tree through a postorder traversal.
    void traversePostOrder(TreeNode* current)
    {
        if (current != nullptr)
        {
            traversePostOrder(current->left);
            traversePostOrder(current->right);
            cout << current->data << " ";
        }
    }

    // Print out all the values in the tree through a level order traversal (breadth-first search) using a queue.
    void traverseLevelOrder(TreeNode* current)
    {
        // If the current node is null, print nothing.
        if (current == nullptr)
            return;
        
        // Create a queue and push the current node into it.
        std::queue<TreeNode*> q;
        q.push(current);

        while (!q.empty())
        {
            // Retrieve the node at the front of the queue and assign it to frontNode.
            TreeNode* frontNode = q.front();

            // Print the data of frontNode before popping it from the queue.
            cout << frontNode->data << " ";
            q.pop();
            
            // If the left child of frontNode exists, push it into the queue.
            if (frontNode->left != nullptr)
                q.push(frontNode->left);
            
            // If the right child of frontNode exists, push it into the queue.
            if (frontNode->right != nullptr)
                q.push(frontNode->right);
        }
    }

    // Return the current height of the tree.
    int getMaxDepth(TreeNode* current)
    {
        // Base case; if the current node is null, 
        if (current == nullptr)
            return 0;
        
        int leftDepth = getMaxDepth(current->left);
        int rightDepth = getMaxDepth(current->right);

        return std::max(leftDepth, rightDepth) + 1;
    }

    /*  Steps for for Finding maximum depth of the tree.
        1.  curr = 50; lDepth = maxDepth(curr->left)
        2.  curr = 30; lDepth = maxDepth(curr->left)
        3.  curr = 20; lDepth = maxDepth(curr->left)
        4.  curr = nullptr; return 0
        5.  curr = 20; rDepth = maxDepth(curr->right)
        6.  curr = nullptr; return 0
        7.  curr = 20; return max(0, 0) + 1 = 1
        8.  curr = 30; rDepth = maxDepth(curr->right)
        9.  curr = 40; lDepth = maxDepth(curr->left)
        10. curr = nullptr; return 0
        11. curr = 40; rDepth = maxDepth(curr->right)
        12. curr = nullptr; return 0
        13. curr = 40; return max(0, 0) + 1 = 1
        14. curr = 30; 
    */

    // Return the current size of the tree.
    int getSize() { return _size; }

    // Return the current root of the tree.
    TreeNode* getRoot() { return _root; }
};

int main()
{
    /*  Create the binary search tree below.
                       50
                    /     \
                  30       70
                /    \    /
               20    40  60   
    */
    TreeNode* root = new TreeNode(50);
    BinarySearchTree numBST(root);
    (numBST.insert(numBST.getRoot(), 30)) ? printf("Insert 30 successful\n") : printf("Insert 30 failed\n");
    (numBST.insert(numBST.getRoot(), 30)) ? printf("Insert 30 successful\n") : printf("Insert 30 failed\n");
    (numBST.insert(numBST.getRoot(), 20)) ? printf("Insert 20 successful\n") : printf("Insert 20 failed\n");
    (numBST.insert(numBST.getRoot(), 40)) ? printf("Insert 40 successful\n") : printf("Insert 40 failed\n");
    (numBST.insert(numBST.getRoot(), 70)) ? printf("Insert 70 successful\n") : printf("Insert 70 failed\n");
    (numBST.insert(numBST.getRoot(), 60)) ? printf("Insert 60 successful\n") : printf("Insert 60 failed\n");

    cout << endl;
    cout << "Inorder Traversal: ";
    numBST.traverseInOrder(numBST.getRoot());
    cout << endl;
    cout << "Preorder Traversal: ";
    numBST.traversePreOrder(numBST.getRoot());
    cout << endl;
    cout << "Postorder Traversal: ";
    numBST.traversePostOrder(numBST.getRoot());
    cout << endl;
    cout << "Level Order Traversal: ";
    numBST.traverseLevelOrder(numBST.getRoot());
    cout << endl << endl;

    (numBST.invert(numBST.getRoot())) ? printf("Tree inversion successful") : printf("Tree inversion failed.\n");

    cout << endl;
    cout << "Inorder Traversal: ";
    numBST.traverseInOrder(numBST.getRoot());
    cout << endl;
    cout << "Preorder Traversal: ";
    numBST.traversePreOrder(numBST.getRoot());
    cout << endl;
    cout << "Postorder Traversal: ";
    numBST.traversePostOrder(numBST.getRoot());
    cout << endl;
    cout << "Level Order Traversal: ";
    numBST.traverseLevelOrder(numBST.getRoot());
    cout << endl << endl;

    (numBST.find(numBST.getRoot(), 70)) ? printf("Value 70 found!\n") : printf("Value 70 not found.\n");

    (numBST.remove(numBST.getRoot(), 55)) ? printf("Remove 55 successful\n") : printf("Remove 55 failed\n");
    (numBST.remove(numBST.getRoot(), 70)) ? printf("Remove 70 successful\n") : printf("Remove 70 failed\n");

    cout << "Maximum Depth: " <<numBST.getMaxDepth(numBST.getRoot()) << endl;

    return 0;
}