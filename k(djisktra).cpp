#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int from;
    int dest;
    int weight;
};

void dijkstra(vector<vector<Edge>>& graph, int source) {
    int n = graph.size(); // number of vertices
    
    // Priority queue to store {distance, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    // Distance array to store shortest path distances from source
    vector<int> dist(n,INT_MAX);
    
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
        for (auto &edge : graph[u]) {
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
    
    vector<Edge> edges;
    
    cout << "Enter " << m << " edges (from, to, weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
    }
    
    // Create adjacency list from edges
    vector<vector<Edge>> graph(n);
    for(auto &edge:edges){
        graph[edge.from].push_back(edge);
    }
    
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    
    dijkstra(graph, source);
    
    return 0;
}
