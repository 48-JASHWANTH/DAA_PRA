#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
}

void BFS(vector<int> adj[], int V, int start) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
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

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Nodes reachable from node " << startNode << " are: ";
    BFS(adj, V, startNode);

    return 0;
}
