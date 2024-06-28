#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

// Define a structure for the edges in the graph
struct Edge {
    string destination;
    int weight;
};

// Define a structure to compare the nodes in the priority queue
struct Compare {
    bool operator()(pair<string, int> a, pair<string, int> b) {
        return a.second > b.second;
    }
};

// Function to perform Dijkstra's algorithm
void dijkstra(unordered_map<string, vector<Edge>> &graph, const string &start, const string &end) {
    // Priority queue to store the nodes to be explored
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    
    // Distance table to store the shortest distance from the start node
    unordered_map<string, int> distances;
    unordered_map<string, string> previous;

    // Initialize distances with infinity
    for (const auto &node : graph) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;

    // Start with the initial node
    pq.push({start, 0});

    // Explore the graph
    while (!pq.empty()) {
        string current = pq.top().first;
        int current_dist = pq.top().second;
        pq.pop();

        // Explore the neighbors of the current node
        for (const Edge &edge : graph[current]) {
            int new_dist = current_dist + edge.weight;

            // If a shorter path is found
            if (new_dist < distances[edge.destination]) {
                distances[edge.destination] = new_dist;
                pq.push({edge.destination, new_dist});
                previous[edge.destination] = current;
            }
        }
    }

    // Output the shortest path
    vector<string> path;
    for (string at = end; at != start; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(start);

    reverse(path.begin(), path.end());

    cout << "Shortest path: ";
    for (const string &node : path) {
        cout << node << " ";
    }
    cout << "\nTotal distance: " << distances[end] << " units" << endl;
}

int main() {
    // Define the graph
    unordered_map<string, vector<Edge>> graph;

    // Add nodes and edges
    int num_edges;
    cout << "Enter the number of routes: ";
    cin >> num_edges;

    cout << "Enter the routes in the format (city1 city2 distance):" << endl;
    for (int i = 0; i < num_edges; ++i) {
        string from, to;
        int weight;
        cout << "Route " << i + 1 << ": ";
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});  // If the graph is undirected
    }

    // Get user input for the start and end cities
    string start, end;
    cout << "Enter the starting city: ";
    cin >> start;
    cout << "Enter the destination city: ";
    cin >> end;

    // Perform Dijkstra's algorithm
    dijkstra(graph, start, end);

    return 0;
}
