'''
Algorithm:          Recursive Depth-First Search (DFS) for a Matrix

Task:               Print out the value of each element in a matrix of size m * n.

Solution:             Use a recursive depth-first search (DFS) algorithm to traverse the matrix and print each element value. DFS
                    traverses the matrix by visiting all the elements in one path starting from the source element, backtracking to
                    previously visited elements once the path has been fully explored, and visiting all the paths that stem from those
                    elements until all the elements in the matrix have been visited exactly once.
                      DFS uses a stack to keep track of adjacent unvisited elements; in this case, a recursive call stack is used. When an 
                    element is visited, it is popped from the top of the recursive call stack and marked as "visited" before its adjacent
                    elements are pushed onto the stack. If the element has no unvisited adjacent elements, the next element at the top of 
                    the call stack is checked for any unvisited adjacent elements. This process will continue until there are no more
		            unvisited elements in the matrix. To prevent an element from being visited more than once, an 2-D Boolean array of 
                    size m * n is used to keep track of the visited elements.

Time complexity:    O(M * N)
                        M = number of rows in matrix
                        N = number of columns in matrix

Space complexity:   O(E)
                        E = number of elements in the matrix / maximum depth of the recursive call stack

Auxiliary space:    O(E)
                        E = maximum depth of the recursive call stack / size of the visited array

Resources:          https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
                    https://www.youtube.com/watch?v=pcKY4hjDrxk
'''


def dfs_recursive(matrix, visited, r_i, c_i, row_num, column_num):
    ''' Directions for adjacent elements:
         [r_i][c_i - 1] = 1 left from current element
         [r_i][c_i + 1] = 1 right from current element
         [r_i - 1][c_i] = 1 up from current element
         [r_i + 1][c_i] = 1 down from current element
    '''

    # Base case; if either the row or column index is out of range, return.
    if r_i < 0 or c_i < 0 or r_i >= row_num or c_i >= column_num:
        return

    # Index of the current element in the visited array.
    visited_i = r_i * column_num + c_i

    # Base case; if the current element has already been visited, return. This pops the current element from the recursive call stack.
    if visited[visited_i] == True:
        return
    
    # Print the current element and flag it as visited.
    print(matrix[r_i][c_i], end=' ')
    visited[visited_i] = True

    # Recursively visit the elements adjacent to the current element.
    dfs_recursive(matrix, visited, r_i, c_i - 1, row_num, column_num)       # Push element 1 left from current element onto call stack.
    dfs_recursive(matrix, visited, r_i, c_i + 1, row_num, column_num)       # Push element 1 right from current element onto call stack.
    dfs_recursive(matrix, visited, r_i - 1, c_i, row_num, column_num)       # Push element 1 up from current element onto call stack.
    dfs_recursive(matrix, visited, r_i + 1, c_i, row_num, column_num)       # Push element 1 down from current element onto call stack.

# Helper function for dfs_recursive().
def dfs(matrix, r_i, c_i, row_num, column_num):
    # Stores the status (visited or unvisited) of each element in the matrix. All elements are initialized as unvisited (false).
    visited_verts = [False for i in range(row_num * column_num)]
    dfs_recursive(matrix, visited_verts, r_i, c_i, row_num, column_num)

if __name__ == "__main__":
    # Test case 1.
    matrix = [['0', '1', '2', '3'],             # 4x4 matrix of hex characters.
              ['4', '5', '6', '7'],
              ['8', '9', 'A', 'B'],
              ['C', 'D', 'E', 'F']]
    row_num = len(matrix)                       # Number of rows in matrix.
    column_num = len(matrix[0])                 # Number of columns in matrix.
    r_i = 0                                     # Row index of the source element.
    c_i = 0                                     # Column index of the source element.
    print("DFS of Hexadecimal Matrix:", end=' ')
    dfs(matrix, r_i, c_i, row_num, column_num)