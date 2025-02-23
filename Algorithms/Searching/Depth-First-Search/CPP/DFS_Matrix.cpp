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

void dfsRecursive(vector<vector<char>>& matrix, vector<bool>& visited, int r_i, int c_i, int rowNum, int columnNum) {
    /* Directions of adjacent elements:
        [r_i][c_i - 1] = 1 left from current element
        [r_i][c_i + 1] = 1 right from current element
        [r_i - 1][c_i] = 1 up from current element
        [r_i + 1][c_i] = 1 down from current element
    */

    // Base case; if either the row or column index is out of range, return.
    if (r_i < 0 || c_i < 0 || r_i >= rowNum || c_i >= columnNum)
        return;
    
    // Index of current matrix element in the visited array.
    int visited_i = r_i * columnNum + c_i;

    // Base case; if the current element has already been visited once, return. This "pops" the element from the recursive call stack.
    if (visited[visited_i] == true)
        return;
    
    // Print the current element and flag it as visited.
    cout << matrix[r_i][c_i] << " ";
    visited[visited_i] = true;

    // Recursively visit the elements adjacent to the current element.
    dfsRecursive(matrix, visited, r_i, c_i - 1, rowNum, columnNum);      // Push element 1 left from current element onto call stack.
    dfsRecursive(matrix, visited, r_i, c_i + 1, rowNum, columnNum);      // Push element 1 right from current element onto call stack.
    dfsRecursive(matrix, visited, r_i - 1, c_i, rowNum, columnNum);      // Push element 1 up from current element onto call stack.
    dfsRecursive(matrix, visited, r_i + 1, c_i, rowNum, columnNum);      // Push element 1 down from current element onto call stack.
}

// Helper function for dfsRecursive().
void dfs(vector<vector<char>>& matrix, int r_i, int c_i, int rowNum, int columnNum) {
    // Stores the status (visited or unvisited) of each element in the matrix. All elements are initialized as unvisited (false).
    vector<bool> visited(rowNum * columnNum, false);
    dfsRecursive(matrix, visited, r_i, c_i, rowNum, columnNum);
}

int main() {
    // Test case 1.
    vector<vector<char>> matrix = {{'0', '1', '2', '3'},       // 4x4 matrix of hex characters.
                                   {'4', '5', '6', '7'},
                                   {'8', '9', 'A', 'B'},
                                   {'C', 'D', 'E', 'F'}};
    int rowNum = matrix.size();             // Number of rows in matrix.
    int columnNum = matrix[0].size();       // Number of columns in matrix.
    int r_i = 0;                            // Row index of the source element.
    int c_i = 0;                            // Column index of the source element.
    dfs(matrix, r_i, c_i, rowNum, columnNum);

    return 0;
}