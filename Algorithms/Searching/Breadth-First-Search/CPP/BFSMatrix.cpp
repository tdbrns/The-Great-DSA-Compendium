/*
Algorithm:          Iterative Breadth-First Search (BFS) for a Matrix

Task:               Print out the value of each element in a matrix of size m * n.

Solution:           Use an iterative breadth-first search (BFS) algorithm to traverse the matrix and print each element value. BFS 
                    traverses the matrix by visiting a source element, pushing its adjacent unvisited elements into a queue, and 
                    visiting the adjacent elements of the elements that are popped from the queue; this process is repeated until all 
                    the elements in the matrix have been visited exactly once.
                    BFS uses a queue to keep track of adjacent unvisited elements. When an element is visited, it is flagged as "visited"
                    and popped from the front of the queue before its adjacent unvisited elements are pushed into the queue. If the
                    element has no adjacent unvisited elements, the next element at the front of the queue is checked for adjacent
                    unvisited elements. This process will continue until there are no more unvisited elements in the matrix. To prevent 
                    an element from being visited more than once, a 2-D Boolean array of size m * n is used to keep track of the visited 
                    elements.

Time complexity:    O(M * N)
                        M = number of rows in the matrix
                        N = number of columns in the matrix

Space complexity:   O(E)
                        E = number of elements in the matrix

Auxiliary space:    O(E)
                        E = number of elements in the queue / size of the visited array

Resources:          https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
                    https://www.youtube.com/watch?v=pcKY4hjDrxk
*/

#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::pair;

const int NUM_DIRECTIONS = 4;   // There are 4 possible adjacent elements that can be visited from the current element.

void bfs(vector<vector<char>>& matrix, int ri, int ci, int rSize, int cSize)
{
    /* Directions of adjacent elements:
        [ri][ci - 1] = 1 left from current element
        [ri][ci + 1] = 1 right from current element
        [ri - 1][ci] = 1 up from current element
        [ri + 1][ci] = 1 down from current element
    */
    int rDirection[NUM_DIRECTIONS] = {0, 0, -1, 1};     // Direction vector for row.
    int cDirection[NUM_DIRECTIONS] = {-1, 1, 0, 0};     // Direction vector for column.

    // Stores the indices of elements that will be visited next.
    queue<pair<int, int>> q;                     

    // 2-D vector that stores the status (visited or unvisited) of each element in the matrix. All elements are initialized to false 
    // (unvisited).
    vector<vector<bool>> visited(rSize, vector<bool>(cSize, false));    // 2-D vector 

    // Push indices of current element into q; flag current element as visited.
    q.push({ri, ci});
    visited[ri][ci] = true;

    while (!q.empty())
    {
        // Print the element at the front of the queue, then pop it from the queue.
        pair<int, int> current = q.front();
        ri = current.first;
        ci = current.second;
        cout << matrix[ri][ci] << " ";
        q.pop();

        // Iteratively visit the adjacent elements of the current element.
        for (int i = 0; i < NUM_DIRECTIONS; i++)
        {
            int adj_ri = ri + rDirection[i];        // Row index of adjacent element.
            int adj_ci = ci + cDirection[i];        // Column index of adjacent element.

            // If either the row or column index of the adjacent element is out of range, continue.
            if (adj_ri < 0 || adj_ci < 0 || adj_ri >= rSize || adj_ci >= cSize)
                continue;

            // If the current adjacent element has already been visited, continue.
            if (visited[adj_ri][adj_ci] == true)
                continue;
            
            // Push the unvisited adjacent element into the queue.
            q.push({adj_ri, adj_ci});
            visited[adj_ri][adj_ci] = true;
        }
    }
}

int main()
{
    vector<vector<char>> matrix = {{'0', '1', '2', '3'},       // 4x4 matrix of characters.
                                   {'4', '5', '6', '7'},
                                   {'8', '9', 'A', 'B'},
                                   {'C', 'D', 'E', 'F'}};
    int rowSize = matrix.size();            // Number of rows in matrix.
    int columnSize = matrix[0].size();      // Number of columns in matrix.
    int row_i = 0, column_i = 0;            // Indices of the source element.
    bfs(matrix, row_i, column_i, rowSize, columnSize);
    return 0;
}