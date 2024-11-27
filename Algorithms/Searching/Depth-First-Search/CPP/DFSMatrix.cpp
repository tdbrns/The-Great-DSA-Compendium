/*
Algorithm:          Recursive Depth-First Search (DFS) for a Matrix

Task:               Print out the value of each element in a matrix of size m * n.

Solution:           Use a recursive depth-first search (DFS) algorithm to traverse the matrix and print each element value. DFS
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
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void recurDFS(vector<vector<char>>& matrix, vector<bool>& visited, int r_i, int c_i, int rSize, int cSize)
{
    /* Directions of adjacent elements:
        [ri][ci - 1] = 1 left from current element
        [ri][ci + 1] = 1 right from current element
        [ri - 1][ci] = 1 up from current element
        [ri + 1][ci] = 1 down from current element
    */

    // Base case; if either the row or column index is out of range, return.
    if (r_i < 0 || c_i < 0 || r_i >= rSize || c_i >= cSize)
        return;
    
    int visited_i = r_i * cSize + c_i;          // Index of current matrix element in the visited array.

    // Base case; if the current element has already been visited once, return. This "pops" the element from the recursive call stack.
    if (visited[visited_i] == true)
        return;
    
    // Print the current element and flag it as visited.
    cout << matrix[r_i][c_i] << " ";
    visited[visited_i] = true;

    // Recursively visit the elements adjacent to the current element. Each function call represents a path that can be taken from the
    // current element. The order in which the functions calls are listed determines how adjacent elements are pushed onto the recursive
    // stack.
    recurDFS(matrix, visited, r_i, c_i - 1, rSize, cSize);      // Push element 1 left from current element onto call stack.
    recurDFS(matrix, visited, r_i, c_i + 1, rSize, cSize);      // Push element 1 right from current element onto call stack.
    recurDFS(matrix, visited, r_i - 1, c_i, rSize, cSize);      // Push element 1 up from current element onto call stack.
    recurDFS(matrix, visited, r_i + 1, c_i, rSize, cSize);      // Push element 1 down from current element onto call stack.
}

// Wrapper function for recurDFS()
void dfs(vector<vector<char>>& matrix, int r_i, int c_i, int rSize, int cSize)
{
    // Stores the status (visited or unvisited) of each element in the matrix. All elements are initialized as unvisited (false).
    vector<bool> visited(rSize * cSize, false);
    recurDFS(matrix, visited, r_i, c_i, rSize, cSize);
}

int main()
{
    vector<vector<char>> matrix = {{'0', '1', '2', '3'},       // 4x4 matrix of hex characters.
                                   {'4', '5', '6', '7'},
                                   {'8', '9', 'A', 'B'},
                                   {'C', 'D', 'E', 'F'}};
    int rowSize = matrix.size();            // Number of rows in matrix.
    int columnSize = matrix[0].size();      // Number of columns in matrix.
    int row_i = 0, column_i = 0;            // Indices of the source element.
    dfs(matrix, row_i, column_i, rowSize, columnSize);

    return 0;
}