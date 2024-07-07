#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


void DFS(int node, vector<vector<int>> adj, vector<bool> visited) {
    visited[node] = true;
    
    for (int i : adj[node]) {
        if (visited[i] == false) {
            DFS(i, adj, visited);
        }
    }
}

bool isConnected(vector<vector<int>> adj, int V) {
    vector<bool> visited(V,false);
    
    DFS(0, adj, visited);
    
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
    
    vector<vector<int>> adj;
    
    cout << "Enter the number of edges: ";
    cin >> E;
    
    cout << "Enter the edges (u v) one per line:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    if (isConnected(adj, V)) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }
    
    return 0;
}
