#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

// A BFS based function to check if there is a path from source 's' to sink 't'.
// It also fills parent[] to store the path
bool bfs(int rGraph[], int V, int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && *(rGraph + u * V + v) > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int graph[], int V, int s, int t) {
    int u, v;

    // Create a residual graph and fill the residual graph with given capacities in the original graph as residual capacities in residual graph
    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = *(graph + u * V + v);

    int parent[V];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while there is path from source to sink
    while (bfs((int*)rGraph, V, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int V, E, s, t;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int graph[V][V];
    memset(graph, 0, sizeof(graph));

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges with capacities (u v capacity) one per line:\n";
    for (int i = 0; i < E; i++) {
        int u, v, capacity;
        cin >> u >> v >> capacity;
        graph[u][v] = capacity;
    }

    cout << "Enter the source vertex: ";
    cin >> s;

    cout << "Enter the sink vertex: ";
    cin >> t;

    cout << "The maximum possible flow is " << fordFulkerson((int*)graph, V, s, t) << endl;

    return 0;
}
