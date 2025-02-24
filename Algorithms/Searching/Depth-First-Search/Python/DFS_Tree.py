'''
Algorithm:          Recursive Depth-First Search (DFS) for a Tree

Task:               Print out the value of each node in a binary tree.

Solution:             Use a recursive depth-first search (DFS) algorithm to traverse the tree and print each node value. DFS
                    traverses the tree by visiting all the nodes in one path starting from the source node, backtracking to
                    previously visited nodes once the path has been fully explored, and visiting all the paths that stem from those
                    nodes until all the nodes in the graph have been visited exactly once. DFS uses a stack to keep track of 
                    adjacent unvisited nodes; in this case, a recursive call stack is used.
                      When a node is visited, it is popped from the top of the recursive call stack before its adjacent nodes are 
                    visited and pushed onto the stack. If the current node has no unvisited adjacent nodes, the next node at the top of 
                    the call stack is checked for any adjacent nodes. This process will continue until each node has been visited 
                    exactly once. Since binary trees do not have cycles or disconnected nodes, a node can never be visited more than
                    once during the traversal. So, there is no need keep track of the nodes that have been visited.

Time complexity:    O(N)
                        N = number of nodes in the tree

Space complexity:   O(N)
                        N = number of nodes in the tree / maximum depth of the recursive call stack

Auxiliary space:    O(log(N))
                        N = number of nodes in the tree
                        NOTE: log(N) just represents the maximum depth of the recursive call stack

Resources:          https://www.geeksforgeeks.org/dfs-traversal-of-a-tree-using-recursion/
                    https://www.youtube.com/watch?v=Urx87-NMm6c
'''

# A struct with the attributes of a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def dfs(current):
    # Base case; if the current node is null, return.
    if current == None:
        return
    
    # Print the value of the current node.
    print(current.val, end=' ')
    
    # Recursively traverse the tree in DFS fashion.
    dfs(current.left)
    dfs(current.right)

if __name__ == "__main__":
    # Test case 1.
    # Create Tree 1 (see Algorithms/Searching/Depth-First-Search/Tree1.png).
    root = TreeNode()
    root.left = TreeNode(1)
    root.right = TreeNode(2)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(5)
    print("DFS of Binary Tree 1:", end=' ')
    dfs(root)