#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& adjList, int startNode, vector<bool>& visited) {
    queue<int> q;

    // Mark the current node as visited and enqueue it
    visited[startNode] = true;
    q.push(startNode);

    // Iterate over the queue
    while (!q.empty()) {
        // Dequeue a vertex from queue and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Get all adjacent vertices of the dequeued vertex
        // currentNode. If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int neighbor : adjList[currentNode]) {
            if (visited[neighbor] == false) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}


int main() {
    int vertices, edges;
    
    // Read number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices);

    // Read edges from the user
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    // Mark all the vertices as not visited
    vector<bool> visited(vertices, false);

    // Perform BFS traversal starting from a user-specified vertex
    int startNode;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startNode;
    
    cout << "Breadth First Traversal starting from vertex " << startNode << ": ";
    bfs(adjList, startNode, visited);

    return 0;
}
