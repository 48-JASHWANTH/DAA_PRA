/*7.	Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

// Compare two edges according to their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Union-Find (Disjoint Set Union) data structure
class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

// Function to find the Minimum Cost Spanning Tree using Kruskal's algorithm
pair<vector<Edge>, int> kruskal(int n, vector<Edge>& edges) {
    // Sort the edges by weight
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize Union-Find data structure
    UnionFind uf(n);

    vector<Edge> mst;
    int mstCost = 0;

    // Process each edge in the sorted order
    for (const Edge& edge : edges) {
        if (uf.find(edge.u) != uf.find(edge.v)) {
            uf.unionSets(edge.u, edge.v);
            mst.push_back(edge);
            mstCost += edge.weight;
        }
    }

    return {mst, mstCost};
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<Edge> edges(m);
    cout << "Enter each edge with format (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Find the MST and its total cost
    auto result = kruskal(n, edges);
    auto& mst = result.first;
    int mstCost = result.second;

    // Display the result
    cout << "Edges in the Minimum Cost Spanning Tree:" << endl;
    for (const Edge& edge : mst) {
        cout << "Edge: (" << edge.u << ", " << edge.v << ") Weight: " << edge.weight << endl;
    }
    cout << "Total cost of the Minimum Cost Spanning Tree: " << mstCost << endl;

    return 0;
}
