#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


// Structure to represent an edge
struct Edge {
    int source;
    int destination;
    int weight;
};


// Function to find the minimum cost spanning tree using Prim's algorithm
void primMST(vector<vector<int>>& graph) {
    int numVertices = graph.size();


    // Create a vector to store the parent of each vertex in the MST
    vector<int> parent(numVertices, -1);


    // Create a vector to store the minimum weight of each vertex in the MST
    vector<int> minWeight(numVertices, numeric_limits<int>::max());


    // Create a vector to store whether a vertex is included in the MST
    vector<bool> inMST(numVertices, false);


    // Start with the first vertex as the root
    int root = 0;
    minWeight[root] = 0;


    // Create a priority queue to store the vertices based on their minimum weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    // Insert the root vertex into the priority queue
    pq.push(make_pair(0, root));


    // Loop through all vertices
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();


        // Include the vertex in the MST
        inMST[u] = true;


        // Update the minimum weight and parent for its adjacent vertices
        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < minWeight[v]) {
                parent[v] = u;
                minWeight[v] = graph[u][v];
                pq.push(make_pair(minWeight[v], v));
            }
        }
    }


    // Print the minimum cost spanning tree
    cout << "Minimum Cost Spanning Tree:\n";
    for (int i = 1; i < numVertices; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " \tWeight: " << graph[parent[i]][i] << endl;
    }
}


// Main function
int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;


    // Create an adjacency matrix to represent the graph
    vector<vector<int>> graph(numVertices, vector<int>(numVertices));


    cout << "Enter the weight of the edges:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }


    primMST(graph);


    return 0;
}
