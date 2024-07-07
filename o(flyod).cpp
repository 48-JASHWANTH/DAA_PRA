#include <iostream>
#include <vector>

using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    // Floyd-Warshall algorithm to find shortest paths between all pairs of vertices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, update dist[i][j]
                if (dist[i][k] != -1 && dist[k][j] != -1) {
                    if (dist[i][j] == -1 || dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
}

void printSolution(const vector<vector<int>>& dist, int V) {
    // Print the shortest distances between every pair of vertices
    cout << "The following matrix shows the shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == -1)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    cout << "Enter the adjacency matrix (-1 for no direct path):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> dist[i][j];
        }
    }

    floydWarshall(dist, V);

    printSolution(dist, V);

    return 0;
}
