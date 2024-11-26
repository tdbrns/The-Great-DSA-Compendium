/*
Algorithm:          Depth-First Search (DFS) for a Matrix

Task:               Print out the value of each element in a matrix.

Solution:           Use a recursive depth-first search (DFS) algorithm to traverse the matrix and print out the element values. DFS
                    works by first visiting a source element and pushing its unvisited adjacent elements onto a stack. In this case, 
                    the DFS function is called recursively to create a call stack that will keep track of any adjacent unvisited
                    elements. Then, the element at the top of the function call stack is removed from the stack and visited, and its 
                    unvisited adjacent elements are pushed onto the stack. If the current element has no unvisited adjacent elements, 
                    then the next element to be removed from the top of the stack will be checked for any unvisited adjacent elements.
                    This process will continue until all elements in the graph have been visited exactly once. To prevent an element
                    from being visited more than once, a vector of boolean values is used to keep track of the elements that have been
                    visited.

Time complexity:    O(M * N)
                        M = number of rows in matrix
                        N = number of columns in matrix

Space complexity:   O(E)
                        E = number of elements in the matrix / maximum depth of the recursive call stack

Auxiliary space:    O(E)
                        E = maximum depth of the recursive call stack

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
    if (r_i < 0 || c_i < 0 || r_i >= rSize || c_i >= cSize)
        return;
    
    int visited_i = r_i * cSize + c_i;          // Position of current matrix element in the visited array.
    if (visited[visited_i] == true)
        return;
    
    cout << matrix[r_i][c_i] << " ";
    visited[visited_i] = true;

    recurDFS(matrix, visited, r_i, c_i - 1, rSize, cSize);      // Left 1 element in matrix.
    recurDFS(matrix, visited, r_i, c_i + 1, rSize, cSize);      // Right 1 element in matrix.
    recurDFS(matrix, visited, r_i - 1, c_i, rSize, cSize);      // Up 1 element in matrix.
    recurDFS(matrix, visited, r_i + 1, c_i, rSize, cSize);      // Down 1 element in matrix.
}

void dfs(vector<vector<char>>& matrix, int r_i, int c_i, int rSize, int cSize)
{
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