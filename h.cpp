/*8.	Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm.*/

//https://youtu.be/4ZlRH0eK-qQ?si=5ewdGAehfZQEYYML
//https://youtu.be/mJcZjjKzeqk?si=1p7ONV6oGD74Wvhy

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent an edge
struct Edge {
    int to;
    int weight;
};

// Comparator to prioritize edges with smaller weights
struct CompareWeight {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

// Function to find the Minimum Cost Spanning Tree using Prim's algorithm
pair<vector<Edge>, int> prim(int n, vector<vector<Edge>>& graph, int start = 0) {
    // Initialize min heap (priority queue)
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareWeight> pq;
    vector<bool> inMST(n, false); // To keep track of vertices included in the MST
    vector<int> parent(n, -1);    // To store the parent of each vertex in the MST
    vector<int> key(n, INT_MAX);  // To store the minimum weight to add each vertex to the MST
    vector<Edge> mstEdges;        // To store the edges in the MST
    int totalCost = 0;

    // Start with the start vertex (default is 0)
    pq.push({start, 0});
    key[start] = 0;

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();

        // Skip if this vertex is already in the MST
        if (inMST[u]) continue;

        // Include vertex u in MST
        inMST[u] = true;
        totalCost += key[u];

        // If u is not the start vertex, add the edge to the MST result
        if (parent[u] != -1) {
            mstEdges.push_back({parent[u], key[u]});
        }

        // Update keys and parent indices for adjacent vertices
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            // If v is not in MST and the weight of (u, v) is smaller than the current key of v
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({v, weight});
                parent[v] = u;
            }
        }
    }

    return {mstEdges, totalCost};
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Adjacency list representation of the graph
    vector<vector<Edge>> graph(n);
    cout << "Enter each edge with format (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight}); // Since the graph is undirected
    }

    // Find the MST and its total cost using Prim's algorithm starting from vertex 0
    auto result = prim(n, graph);
    auto& mstEdges = result.first;
    int mstCost = result.second;

    // Display the result
    cout << "Edges in the Minimum Cost Spanning Tree:" << endl;
    for (const Edge& edge : mstEdges) {
        cout << "Edge: (" << edge.to << ", " << edge.weight << ")" << endl;
    }
    cout << "Total cost of the Minimum Cost Spanning Tree: " << mstCost << endl;

    return 0;
}
