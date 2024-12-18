/*
Algorithm:          Iterative Breadth-First Search (BFS) for a Graph

Task:               Print out the value of each vertex in an undirected graph that is either connnected or disconnected.

Solution:           Use an iterative breadth-first search (BFS) algorithm to traverse the graph and print each vertex value. BFS 
                    traverses the graph by visiting a source vertex, pushing its adjacent unvisited vertices into a queue, and 
                    visiting the adjacent vertices of the vertices that are popped from the queue; this process is repeated until all 
                    the vertices in the graph have been visited exactly once.
                    BFS uses a queue to keep track of adjacent unvisited vertices. When an vertex is visited, it is flagged as "visited"
                    and popped from the front of the queue before its adjacent unvisited vertices are pushed into the queue. If the
                    vertex has no adjacent unvisited vertices, the next vertex at the front of the queue is checked for adjacent
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
*/

#include <iostream>
#include <queue>
#include <vector>
using std::cout;
using std:: endl;
using std::vector;
using std::queue;

// Breadth first search of an entire graph from a given source vertex. This function assumes that the graph is connected.
void bfs(vector<vector<int>> adjList, int source)
{
    // A queue to store and keep track of the vertices that will be visited next.
    queue<int> q; 
    // A vector to keep track of the indices that have already been visited; initialize all visited vertices to false (unvisited).
    vector<bool> visitedVerts(adjList.size(), false);

    // If the graph is connected, mark the source vertex as true (visited) and push it onto the queue.
    visitedVerts[source] = true;
    q.push(source);
    
    while (!q.empty())
    {
        int current = q.front();        // Current frontmost vertex of the queue.
        // Dequeue the frontmost vertex and print it out.
        q.pop();
        cout << current << " ";

        // Check each adjacent vertex of the current vertex. If an adjacent vertex has not been visited, mark it as visited and 
        // push it into the queue.
        for (auto vertex : adjList[current])
        {
            if (!visitedVerts[vertex])
            {
                visitedVerts[vertex] = true;
                q.push(vertex);
            }
        }
    }
}

// Breadth first search of a entire graph that is disconnected.
void disconnectedBFS(vector<vector<int>> adjList)
{
    // Keeps track of vertices that have already been visited; initialize all visited vertices to false (unvisited).
    vector<bool> visitedVerts(adjList.size(), false);

    // Go through each vertex in the graph and set it as the source vertex regardless of whether or not is is connected to anything.
    for (int vertex = 0; vertex < adjList.size(); vertex++)
    {
        // If the vertex has not been visited, perform a BFS with that vertex as the source vertex.
        if (!visitedVerts[vertex])
        {
            queue<int> q; 

            visitedVerts[vertex] = true;
            q.push(vertex);

            while (!q.empty())
            {
                int current = q.front();
                q.pop();
                cout << current << " ";

                for (int v : adjList[current])
                {
                    if (!visitedVerts[v])
                    {
                        visitedVerts[v] = true;
                        q.push(v);
                    }
                }
            }
        }
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
    cout << "BFS of Connected Graph from Vertex_0: ";
    bfs(adjacencyList1, sourceVertex);
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
        vertex_3 -> 4
        vertex_4 -> 3 -> 5
        vertex_5 -> 4
    */
    addEdge(adjacencyList2, 0, 1);
    addEdge(adjacencyList2, 0, 2);
    addEdge(adjacencyList2, 3, 4);
    addEdge(adjacencyList2, 4, 5);
    cout << "BFS of Disconnected Graph from Vertex_0: ";
    disconnectedBFS(adjacencyList2);
    cout << endl;

    return 0;
}