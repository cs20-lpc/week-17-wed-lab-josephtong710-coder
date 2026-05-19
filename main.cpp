// Implement main program.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minDistance(vector<int>& dist, vector<bool>& visited, int n) {
    int minDist = INT_MAX, minIndex = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Step 2: Dijkstra's algorithm
void dijkstra(vector<vector<int>>& graph, int src, int n) {
    vector<int>  dist(n, INT_MAX);   // all distances start as infinity
    vector<bool> visited(n, false);  // no nodes visited yet

    dist[src] = 0;  // distance from source to itself is 0

    // Process all nodes
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);  // pick closest unvisited node
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    // Print results
    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "  Node " << i << ": " << dist[i] << "\n";
    }
}

int main() {
    int n = 6;  // number of vertices (0 through 5)
    vector<vector<int>> graph = {
      // 0  1  2  3  4  5
        {0, 4, 9, 0, 2, 0},  // from 0
        {0, 0, 2, 1, 0, 0},  // from 1
        {0, 0, 0, 7, 0, 4},  // from 2
        {0, 0, 0, 0, 0, 1},  // from 3
        {0, 0, 3, 0, 0, 8},  // from 4
        {0, 0, 0, 0, 0, 0},  // from 5
    };

    dijkstra(graph, 0, n);  // Part 1: source = node 0
    cout << "\n";
    dijkstra(graph, 1, n);  // Part 2: source = node 1
    return 0;
}