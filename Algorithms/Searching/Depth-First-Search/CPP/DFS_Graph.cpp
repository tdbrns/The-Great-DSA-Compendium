/*
Algorithm:          Recursive Depth-First Search (DFS) for a Graph

Task:               Print out the value of each vertex in an undirected graph that is either connnected or disconnected.

Solution:           Use a recursive depth-first search (DFS) algorithm to traverse the graph and print each vertex value. DFS
                    traverses the graph by visiting all the vertices in one path starting from the source vertex, backtracking to
                    previously visited vertices once the path has been fully explored, and visiting all the paths that stem from those
                    vertices until all the vertices in the graph have been visited exactly once.
                    DFS uses a stack to keep track of adjacent unvisited vertices; in this case, a recursive call stack is used. When a 
                    vertex is visited, it is popped from the top of the recursive call stack and marked as "visited" before its adjacent
                    vertices are pushed onto the stack. If the vertex has no unvisited adjacent vertices, the next vertex at the top of 
                    the call stack is checked for any unvisited adjacent vertex. This process will continue until there are no more
		            unvisited vertices in the graph. To prevent a vertex from being visited more than once, an Boolean array is used 
                    to keep track of the visited vertices.

Time complexity:    O(V + E)
                        V = total number of vertices
                        E = total number of edges

Space complexity:   O(V)
                        V = number of vertices in the adjacency list / maximum depth of the recursive call stack

Auxiliary space:    O(V)
                        V = maximum depth of the recursive call stack / size of the visited array

Resources:          https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
                    https://www.youtube.com/watch?v=pcKY4hjDrxk
*/

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// Depth-first search of an entire graph from a given source vertex. This function assumes that the graph is connected.
void recursiveDFS(vector<vector<int>> adjList, vector<bool>& visitedVerts, int current)
{
    // Mark the current source vertex as visited and print it.
    visitedVerts[current] = true;
    cout << current << " ";

    // If an adjacent vertex of the current vertex has not been visited yet, push it onto the function call stack and check if any
    // of its adjacent verteices are unvisited.
    for (auto vertex : adjList[current])
        if (!visitedVerts[vertex])
            recursiveDFS(adjList, visitedVerts, vertex);
}

// Initialize the list of visited vertices before calling the recursive dfs function.
void dfs(vector<vector<int>> adjList, int source)
{
    // Keeps track of vertices that have already been visited; initialize all visited vertices to false (unvisited).
    vector<bool> visitedVerts(adjList.size(), false);
    recursiveDFS(adjList, visitedVerts, source);
}

// Depth-first search of a entire graph that is disconnected.
void disconnectedDFS(vector<vector<int>> adjList)
{
    vector<bool> visitedVerts(adjList.size(), false);

    // Go through each vertex in the graph and set it as the source vertex regardless of whether or not is is connected to anything.
    for (int vertex = 0; vertex < adjList.size(); vertex++)
    {
        if (!visitedVerts[vertex])
            recursiveDFS(adjList, visitedVerts, vertex);
    }
}

// Add edges to the graph by connecting the vertices together.
void addEdge(vector<vector<int>>& adjList, int vertex, int connectedVertex)
{
    // Connect to vetices together in the vector.
    adjList[vertex].push_back(connectedVertex);
    adjList[connectedVertex].push_back(vertex);
}

int main()
{
    /*  Create the graph below.
          1  -  3
         / \
        0   4
         \ /
          2 
    */
   int vertexNum = 5;                               // Number of vertices in the graph.
   int sourceVertex = 0;                            // The very first vertex in the graph that will be visited in the search.
   vector<vector<int>> adjacencyList1(vertexNum);   // 2-D vector holding each vertex and the vertices connected to it via an edge.
    /*  Adjacency list for the graph above.
        vertex_0 -> 1 -> 2
        vertex_1 -> 0 -> 3 -> 4
        vertex_2 -> 0 -> 4
        vertex_3 -> 1
        vertex_4 -> 1 -> 2
    */
   addEdge(adjacencyList1, 0, 1);
   addEdge(adjacencyList1, 0, 2);
   addEdge(adjacencyList1, 1, 3);
   addEdge(adjacencyList1, 1, 4);
   addEdge(adjacencyList1, 2, 4);
   cout << "DFS of Connected Graph from Vertex_0: ";
   dfs(adjacencyList1, sourceVertex);
   cout << endl;


   /*  Create the disconnected graph below.
          1     3
         /       \
        0         4
         \       /
          2     5
    */
   vertexNum = 6;
   vector<vector<int>> adjacencyList2(vertexNum);   // 2-D vector holding each vertex and the vertices connected to it via an edge.
   /*  Adjacency list for the graph above.
       vertex_0 -> 1 -> 2
       vertex_1 -> 0
       vertex_2 -> 0
       vertex_3 -> 1 -> 4
       vertex_4 -> 3 -> 4
       vertex_5 -> 4
   */
   addEdge(adjacencyList2, 0, 1);
   addEdge(adjacencyList2, 0, 2);
   addEdge(adjacencyList2, 3, 4);
   addEdge(adjacencyList2, 4, 5);
   cout << "DFS of Disconnected Graph from Vertex_0: ";
   disconnectedDFS(adjacencyList2);
   cout << endl;

   return 0;
}