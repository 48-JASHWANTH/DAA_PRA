#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void topologicalSortUtil(int v, vector<int> adj[], vector<bool>& visited, stack<int>& Stack) {
    visited[v] = true;
    
    for (int i : adj[v]) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }
    
    Stack.push(v);
}

void topologicalSort(vector<int> adj[], int V) {
    stack<int> Stack;
    vector<bool> visited(V, false);
    
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, adj, visited, Stack);
        }
    }
    
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
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
    
    cout << "Topological ordering of the vertices:\n";
    topologicalSort(adj, V);
    
    return 0;
}
