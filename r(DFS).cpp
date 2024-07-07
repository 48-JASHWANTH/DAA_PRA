#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Since the graph is undirected
}

void DFSUtil(int v, vector<int> adj[], bool visited[]) {
    visited[v] = true;
    
    for (int i : adj[v]) {
        if (!visited[i]) {
            DFSUtil(i, adj, visited);
        }
    }
}

bool isConnected(vector<int> adj[], int V) {
    bool visited[V];
    memset(visited, false, sizeof(visited));
    
    // Perform DFS from the first vertex (assuming vertex numbering starts from 0)
    DFSUtil(0, adj, visited);
    
    // Check if all vertices are visited
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    vector<int> adj[V];
    
    cout << "Enter the number of edges: ";
    cin >> E;
    
    cout << "Enter the edges (u v) one per line:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }
    
    if (isConnected(adj, V)) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }
    
    return 0;
}
