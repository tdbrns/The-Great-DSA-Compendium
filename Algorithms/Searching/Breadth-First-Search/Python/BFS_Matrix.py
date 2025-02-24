'''
Algorithm:          Iterative Breadth-First Search (BFS) for a Matrix

Task:               Print out the value of each element in a matrix of size m * n.

Solution:             Use an iterative breadth-first search (BFS) algorithm to traverse the matrix and print each element value. BFS 
                    traverses the matrix by visiting a source element, pushing its adjacent unvisited elements into a queue, and 
                    visiting the adjacent elements of the elements that are popped from the queue; this process is repeated until all 
                    the elements in the matrix have been visited exactly once.
                      BFS uses a queue to keep track of adjacent unvisited elements. When an element is visited, it is flagged as 
                    "visited" and popped from the front of the queue before its adjacent unvisited elements are pushed into the queue. 
                    If the element has no adjacent unvisited elements, the next element at the front of the queue is checked for adjacent
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

Resources:          https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/
                    https://www.youtube.com/watch?v=pcKY4hjDrxk
'''


from queue import Queue
NUM_DIRECTIONS = 4

def bfs(matrix, ri, ci, row_num, column_num):
    return

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
    print("BFS of Hexadecimal Matrix:", end=' ')
    bfs(matrix, r_i, c_i, row_num, column_num)