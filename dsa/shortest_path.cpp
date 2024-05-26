#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;


// Structure to represent an edge
struct Edge {
    int destination;
    int weight;
};


// Function to find the single source shortest path using Dijkstra's algorithm
void dijkstraShortestPath(vector<vector<Edge>>& graph, int source) {
    int numVertices = graph.size();


    // Create a vector to store the distances from the source vertex
    vector<int> distance(numVertices, numeric_limits<int>::max());


    // Create a priority queue to store the vertices based on their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


    // Start with the source vertex
    distance[source] = 0;
    pq.push(make_pair(0, source));


    // Loop through all vertices
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();


        // Update the distances for the adjacent vertices
        for (const auto& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;


            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push(make_pair(distance[v], v));
            }
        }
    }


    // Print the shortest distances from the source vertex
    cout << "Shortest Distances from Source Vertex " << source << ":\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << distance[i] << endl;
    }
}


// Main function
int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;


    // Create a vector of vectors to represent the graph
    vector<vector<Edge>> graph(numVertices);


    cout << "Enter the number of edges: ";
    int numEdges;
    cin >> numEdges;


    cout << "Enter the edges and their weights:\n";
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }


    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;


    dijkstraShortestPath(graph, sourceVertex);


    return 0;
}
