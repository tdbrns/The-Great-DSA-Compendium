'''
Algorithm:          Recursive Depth-First Search (DFS) for a Graph

Task:               Print out the value of each vertex in an undirected graph that is either connnected or disconnected.

Solution:             Use a recursive depth-first search (DFS) algorithm to traverse the graph and print each vertex value. DFS
                    traverses the graph by visiting all the vertices in one path starting from the source vertex, backtracking to
                    previously visited vertices once the path has been fully explored, and visiting all the paths that stem from those
                    vertices until all the vertices in the graph have been visited exactly once. DFS uses a stack to keep track of 
                    adjacent unvisited vertices; in this case, a recursive call stack is used.
                      When a vertex is visited, it is popped from the top of the recursive call stack and marked as "visited" before its 
                    adjacent vertices are visited and pushed onto the stack. If the current vertex has no unvisited adjacent vertices, 
                    the next vertex at the top of the call stack is checked for any unvisited adjacent vertices. This process will 
                    continue until each vertex has been visited exactly once. To prevent a vertex from being visited more than once, 
                    a Boolean array is used to keep track of the visited vertices.
                      If the graph is disconnected, instead of performing DFS from a single source vertex, Go through each unvisited 
                    vertex in the graph and set it as the source vertex regardless of whether or not is is connected to anything.

Time complexity:    O(V + E)
                        V = total number of vertices
                        E = total number of edges

Space complexity:   O(V)
                        V = number of vertices in the adjacency list / maximum depth of the recursive call stack

Auxiliary space:    O(V)
                        V = maximum depth of the recursive call stack / size of the visited array

Resources:          https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
                    https://www.youtube.com/watch?v=pcKY4hjDrxk
'''


def dfs_recursive(adj_list, visited, current):
    # Set the current vertex to true (visited) and print it.
    visited[current] = True
    print(current, end=' ')

    # If an adjacent vertex of the current vertex is unvisited, push it onto the function call stack and check its adjacent vertices.
    for vertex in adj_list[current]:
        if visited[vertex] == False:
            dfs_recursive(adj_list, visited, vertex)

# Depth-first search of a disconnected graph.
def dfs_disconnect(adj_list):
    visited_verts = [False for i in range(len(adj_list))]
    for vertex in range(len(adj_list)):
        if visited_verts[vertex] == False:
            dfs_recursive(adj_list, visited_verts, vertex)
    print()
    
# Depth-first search of a connected graph from a given source vertex.
def dfs(adj_list, source):
    # Records visited vertices as true and unvisited vertices as false; all vertices are initialized to false.
    visited_verts = [False for i in range(len(adj_list))]
    dfs_recursive(adj_list, visited_verts, source)
    print()

# Add edges to the graph by connecting two vertices together.
def add_edge(adj_list, vertex, connected_vertex):
    adj_list[vertex].append(connected_vertex)
    adj_list[connected_vertex].append(vertex)

if __name__ == "__main__":
    # Test case 1.
    ''' Create Graph 1 (see Algorithms\\Searching\\Depth-First-Search\\Graph1.png)
        Graph 1 Adjacency List:
            vertex_0 -> 1 -> 2
            vertex_1 -> 0 -> 3 -> 4
            vertex_2 -> 0 -> 4
            vertex_3 -> 1
            vertex_4 -> 1 -> 2
    '''
    vertex_num = 5                                  # Number of vertices in the graph.
    source_vertex = 0                               # First vertex to be visited in the search.
    adj_list = [[] for i in range(vertex_num)]      # Stores each vertex in a row and each of their edge-connected vertices in a column.
    add_edge(adj_list, 0, 1)
    add_edge(adj_list, 0, 2)
    add_edge(adj_list, 1, 3)
    add_edge(adj_list, 1, 4)
    add_edge(adj_list, 2, 4)
    print("DFS of Connected Graph from Vertex_0:",end=' ')
    dfs(adj_list, source_vertex)


    # Test case 2.
    ''' Create Graph 2 (see Algorithms\\Searching\\Depth-First-Search\\Graph2.png)
        Graph 2 Adjacency List:
            vertex_0 -> 1 -> 2
            vertex_1 -> 0
            vertex_2 -> 0
            vertex_3 -> 4 -> 5
            vertex_4 -> 3
            vertex_5 -> 3
    '''
    vertex_num = 6
    adj_list = adj_list = [[] for i in range(vertex_num)]
    add_edge(adj_list, 0, 1)
    add_edge(adj_list, 0, 2)
    add_edge(adj_list, 3, 4)
    add_edge(adj_list, 3, 5)
    print("DFS of Disconnected Graph:",end=' ')
    dfs_disconnect(adj_list)