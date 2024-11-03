/*
Algorithm:          Iterative Breadth-First Search (BFS) for a graph
Characteristics:    
Time complexity:    O(V + E); V = total number of vertices, E = total number of edges
Space complexity:   O(V); V = total number of vertices
Task:               Print out all the vertex values of an undirected graph that is either connnected or disconnected.
Solution:           Use an iterative breadth-first search (BFS) algorithm to traverse the graph and print out the vertex values. BFS
                    works by first visiting a source vertex and then visiting the vertex's adjacent vertices before moving to the
                    next level of the graph and doing the same thing until all vertices has been visited once. This implementation 
                    of BFS pushes visited vertices into a queue and uses the queue to determine which vertex will be the next source
                    vertex. Since graphs can contain cycles, a vector is used to keep track of the visited vertices so that each
                    vertex is only visited once.
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
void BFS(vector<vector<int>> adjList, int source)
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
        for (int vertex : adjList[current])
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
        // If the vertex has not been visited, perform BFS with that vertex as the source vertex.
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
         /
        0    \
         \
          2  -  4
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
    BFS(adjacencyList1, sourceVertex);
    cout << endl;

    /*  Create the disconnected graph below.
          1     3
         /       \
        0         4
         \       /
          2     5
    */
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
    cout << "BFS of Disconnected Graph from Vertex_0: ";
    disconnectedBFS(adjacencyList2);
    cout << endl;

    return 0;
}