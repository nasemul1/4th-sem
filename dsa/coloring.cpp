#include <iostream>
#include <vector>
using namespace std;


// Function to check if it's safe to color a vertex with a particular color
bool isSafe(vector<vector<int>>& graph, vector<int>& colors, int vertex, int color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false;
        }
    }
    return true;
}


// Function to color the graph using backtracking
bool colorGraphUtil(vector<vector<int>>& graph, vector<int>& colors, int vertex, int numColors) {
    if (vertex == graph.size()) {
        return true; // All vertices have been colored successfully
    }


    for (int color = 1; color <= numColors; color++) {
        if (isSafe(graph, colors, vertex, color)) {
            colors[vertex] = color; // Assign color to the vertex


            if (colorGraphUtil(graph, colors, vertex + 1, numColors)) {
                return true;
            }


            colors[vertex] = 0; // Backtrack and try a different color
        }
    }


    return false; // No valid coloring found
}


// Function to color the graph and print the colors assigned to each vertex
void colorGraph(vector<vector<int>>& graph, int numColors) {
    vector<int> colors(graph.size(), 0);


    if (colorGraphUtil(graph, colors, 0, numColors)) {
        cout << "Graph can be colored using " << numColors << " colors." << endl;
        cout << "Colors assigned to vertices:" << endl;
        for (int i = 0; i < colors.size(); i++) {
            cout << "Vertex " << i << ": Color " << colors[i] << endl;
        }
    } else {
        cout << "Graph cannot be colored using " << numColors << " colors." << endl;
    }
}


int main() {
    int numVertices, numColors;


    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;


    cout << "Enter the number of colors available: ";
    cin >> numColors;


    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));


    cout << "Enter the adjacency matrix representing the graph:" << endl;
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }


    colorGraph(graph, numColors);


    return 0;
}