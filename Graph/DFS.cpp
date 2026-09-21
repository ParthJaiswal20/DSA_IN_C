#include <iostream>
#include <vector>
using namespace std;


void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
    cout << node << " "; // Print the current node
    visited[node] = true; // Mark this node as visited

    // Visit all adjacent nodes that are not visited
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}
int main() {
    int n = 5; // Number of nodes (0 to 4)
    vector<vector<int>> graph(n); // Adjacency list representation

    // Adding edges
    graph[0] = {1, 2}; // Node 0 is connected to 1 and 2
    graph[1] = {0, 3, 4}; // Node 1 is connected to 0, 3, and 4
    graph[2] = {0}; // Node 2 is connected to 0
    graph[3] = {1}; // Node 3 is connected to 1
    graph[4] = {1}; // Node 4 is connected to 1

    vector<bool> visited(n, false); // To keep track of visited nodes

    cout << "DFS Traversal: ";
    dfs(0, graph, visited); // Start DFS from node 0

    return 0;
}
