'''
Algorithm:          Iterative Breadth-First Search (BFS) for a Graph

Task:               Print out the value of each vertex in an undirected graph that is either connnected or disconnected.

Solution:             Use an iterative breadth-first search (BFS) algorithm to traverse the graph and print each vertex value. BFS 
                    traverses the graph by visiting a source vertex, pushing its adjacent unvisited vertices into a queue, and 
                    visiting the adjacent vertices of the vertices that are popped from the queue; this process is repeated until all 
                    the vertices in the graph have been visited exactly once.
                      BFS uses a queue to keep track of adjacent unvisited vertices. When an vertex is visited, it is flagged as 
                    "visited" and popped from the front of the queue before its adjacent unvisited vertices are pushed into the queue.
                    If the vertex has no adjacent unvisited vertices, the next vertex at the front of the queue is checked for adjacent
                    unvisited vertices. This process will continue until there are no more unvisited vertices in the graph. To prevent 
                    an vertex from being visited more than once, a Boolean array is used to keep track of the visited vertices.

Time complexity:    O(V + E)
                        V = total number of vertices
                        E = total number of edges

Space complexity:   O(V)
                        V = total number of vertices in the adjacency list

Auxiliary space:    O(V)
                        V = number of visited and unvisited vertices stored in the queue and the vector respectively

Resources:          https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
                    https://www.youtube.com/watch?v=pcKY4hjDrxk
'''


from queue import Queue

# BFS of an entire graph from a given source vertex. This function assumes that the graph is connected.
def bfs(adj_list, source):
    # Stores and keeps track of the vertices that will be visited next.
    q = Queue()
    # Keeps track of the indices that have already been visited; initialize all visited vertices to false (unvisited).
    visited = [False for i in range(len(adj_list))]

    # Mark the source vertex as true (visited) and push it into the queue.
    visited[source] = True
    q.put(source)

    while q.empty() == False:
        # Dequeue the frontmost vertex value and print it out.
        current = q.get()
        print(current, end=' ')

        # Check each adjacent vertex of the current vertex. If an adjacent vertex has not been visited, mark it as visited and 
        # push it into the queue.
        for vertex in adj_list[current]:
            if visited[vertex] == False:
                visited[vertex] = True
                q.put(vertex)
    print()

# Breadth first search of a entire graph that is disconnected.
def bfs_disconnected(adj_list):
    # Keeps track of vertices that have already been visited; initialize all visited vertices to false (unvisited).
    visited = [False for i in range(len(adj_list))]

    # Go through each vertex in the graph and set it as the source vertex regardless of whether or not is is connected to anything.
    for vertex in range(len(adj_list)):
        # If the vertex has not been visited, perform a BFS with that vertex as the source vertex.
        if visited[vertex] == False:
            q = Queue()

            visited[vertex] = True
            q.put(vertex)

            while q.empty() == False:
                current = q.get()
                print(current, end=' ')

                for v in adj_list[current]:
                    if visited[v] == False:
                        visited[v] = True
                        q.put(v)
    print()

# Add edges to the graph by connecting the vertices together.
def add_edge(adj_list, vertex, connected_vertex):
    # Connect to vetices together in the vector.
    adj_list[vertex].append(connected_vertex)
    adj_list[connected_vertex].append(vertex)

if __name__ == "__main__":
    # Test case 1.
    # Create Graph 1 (see Algorithms/Searching/Breadth-First-Search/Graph1.png)
    vertex_num = 5                                  # Number of vertices in Graph 1.
    source_vertex = 0                               # First vertex to be visited in the search.
    adj_list = [[] for i in range(vertex_num)]      # Stores each vertex in a row and each of their edge-connected vertices in a column.
    add_edge(adj_list, 0, 1)
    add_edge(adj_list, 0, 2)
    add_edge(adj_list, 1, 3)
    add_edge(adj_list, 1, 4)
    add_edge(adj_list, 2, 4)
    print("BFS of Connected Graph from Vertex_0:",end=' ')
    bfs(adj_list, source_vertex)


    # Test case 2.
    # Create Graph 2 (see Algorithms/Searching/Breadth-First-Search/Graph2.png)
    vertex_num = 6                                  # Number of vertices in Graph 2.
    adj_list = [[] for i in range(vertex_num)]
    add_edge(adj_list, 0, 1)
    add_edge(adj_list, 0, 2)
    add_edge(adj_list, 3, 4)
    add_edge(adj_list, 3, 5)
    print("BFS of Disconnected Graph:",end=' ')
    bfs_disconnected(adj_list)