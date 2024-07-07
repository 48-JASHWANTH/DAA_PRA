#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int TSP(const vector<vector<int>>& graph, int pos, int visited, vector<vector<int>>& dp) {
    int n = graph.size();

    // Base case: all cities have been visited
    if (visited == (1 << n) - 1) {
        return graph[pos][0]; // Return to starting city
    }

    // If already computed, return the stored value
    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }

    int minCost = numeric_limits<int>::max();

    // Try visiting the unvisited cities
    for (int city = 0; city < n; ++city) {
        if ((visited & (1 << city)) == 0) {
            int newVisited = visited | (1 << city);
            int cost = graph[pos][city] + TSP(graph, city, newVisited, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[pos][visited] = minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix (distances between cities):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    // DP table to store the minimum cost of visiting all cities from a given position
    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int minCost = TSP(graph, 0, 1, dp);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}
