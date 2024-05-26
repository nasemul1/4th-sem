#include <iostream>
using namespace std;


#define nV 4
#define INF 999


void printShortestDistances(int distances[][nV]);


void floydWarshall(int graph[][nV]) {
  int distances[nV][nV], i, j, k;


  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      distances[i][j] = graph[i][j];


  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (distances[i][k] + distances[k][j] < distances[i][j])
          distances[i][j] = distances[i][k] + distances[k][j];
      }
    }
  }
  printShortestDistances(distances);
}


void printShortestDistances(int distances[][nV]) {
  cout << "Shortest Distances:\n";
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (distances[i][j] == INF)
        cout << "INF\t";
      else
        cout << distances[i][j] << "\t";
    }
    cout << endl;
  }
}


int main() {
  int graph[nV][nV] = {{0, 3, INF, 5},
                       {2, 0, INF, 4},
                       {INF, 1, 0, INF},
                       {INF, INF, 2, 0}};
  floydWarshall(graph);


  return 0;
}
