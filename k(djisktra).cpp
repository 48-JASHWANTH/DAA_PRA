#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a graph edge
struct Edge {
    int dest;
    int weight;
};

// Function to perform Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int source) {
    int n = graph.size(); // number of vertices
    
    // Priority queue to store {distance, vertex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Distance array to store shortest path distances from source
    vector<int> dist(n, numeric_limits<int>::max());
    
    // Mark source distance as 0 and push it to the priority queue
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();
        
        // If the extracted vertex 'u' has already been finalized, skip it
        if (u_dist > dist[u]) continue;
        
        // Iterate through all adjacent vertices of u
        for (const Edge& edge : graph[u]) {
            int v = edge.dest;
            int weight = edge.weight;
            
            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    // Print shortest distances from source vertex
    for (int i = 0; i < n; ++i) {
        cout << "Shortest distance from source to vertex " << i << " is: " << dist[i] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    
    vector<vector<Edge>> graph(n);
    
    cout << "Enter " << m << " edges (from, to, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
    }
    
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    
    dijkstra(graph, source);
    
    return 0;
}
