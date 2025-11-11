#ifndef H_BFSgraph
#define H_BFSgraph
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

class BFSgraph {
private:
  vector<vector<int>> weightedAdjMatrix {
      {0, 2097, 0, 807, 1331, 0, 0, 0, 0, 0, 0, 0},      // Seattle       (0)
      {2097, 0, 983, 0, 1003, 787, 533, 0, 0, 0, 0, 0},  // Chicago       (1)
      {0, 983, 0, 0, 0, 214, 0, 0, 0, 0, 0, 0},          // Boston        (2)
      {807, 0, 0, 0, 1267, 0, 0, 381, 0, 0, 0, 0},       // San Francisco (3)
      {1331, 1003, 0, 1267, 0, 0, 599, 1015, 0, 0, 0, 0},// Denver        (4)
      {0, 787, 214, 0, 0, 0, 1260, 0, 0, 888, 0, 0},     // New York      (5)
      {0, 533, 0, 0, 599, 1260, 0, 1663, 496, 864, 0, 0},// Kansas City   (6)
      {0, 0, 0, 381, 1015, 0, 1663, 0, 1435, 0, 0, 0},   // Los Angeles   (7)
      {0, 0, 0, 0, 0, 0, 496, 1435, 0, 781, 239, 0},     // Dallas        (8)
      {0, 0, 0, 0, 0, 888, 864, 0, 781, 0, 810, 661},    // Atlanta       (9)
      {0, 0, 0, 0, 0, 0, 0, 0, 239, 810, 0, 1187},       // Houston       (10)
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 661, 1187, 0}          // Miami         (11)
  };// 0  1  2  3  4  5  6  7  8   9    10   11

  vector<string> vertices {"Seattle", "Chicago", "Boston", "San Francisco", "Denver",
                           "New York", "Kansas City", "Los Angeles", "Dallas", "Atlanta",
                           "Houston", "Miami"};

public:
  void BFS_algorithm(int start) {
    int totalDistance = 0;
    int currentVertex;
    int numOfVertices = weightedAdjMatrix.size();
    vector<string> BFScities; // For displaying the traversal order of cities
    BFScities.push_back(vertices[start]); // Add the starting city first

    // Vector to hold all visited vertices
    vector<bool> visited(numOfVertices, false);
    
    // Regular queue for BFS (first in, first out)
    vector<int> queue;
    
    // Store the starting vertex in the queue
    queue.push_back(start);
    
    // Set start as visited
    visited[start] = true;
    
    // While the queue is not empty
    while (!queue.empty()) {
      // Make the first vertex in the queue the current vertex
      currentVertex = queue[0];

      // Remove the vertex you just set as currentVertex
      queue.erase(queue.begin());

      // Collect all unvisited neighbors with their edge weights
      vector<pair<int, int>> neighbors; // pair of <vertex index, edge weight>
      
      // Traversing the adjacency matrix (the neighbors of the current vertex)
      for (int i = 0; i < int(weightedAdjMatrix[currentVertex].size()); i++) {
        // If adjacent vertex is not null & has not been visited
        if (weightedAdjMatrix[currentVertex][i] != 0 && (!visited[i])) {
          neighbors.push_back({i, weightedAdjMatrix[currentVertex][i]});
        }                  // <vertex index, edge weight>
      }

      // Sort neighbors by edge weight (smallest miles first)
      sort(neighbors.begin(), neighbors.end(), 
           [](const pair<int, int>& a, const pair<int, int>& b) {
             return a.second < b.second;
           });

      // Add sorted neighbors to the queue and mark as visited
      for (const auto& neighbor : neighbors) {
        int neighborVertex = neighbor.first; // first -> <vertex index, edge weight>
        int edgeWeight = neighbor.second; // <vertex index, edge weight> <- second

        queue.push_back(neighborVertex);
        visited[neighborVertex] = true;

        totalDistance += edgeWeight; // Add up all miles of the discovery edges

        cout << "**Discovery edge**: ";
        cout << "Origin -> " << vertices[currentVertex] << " , ";
        cout << vertices[neighborVertex] << " <- Destination\n\n";

        // Add the current neighbor vertex to the BFS traversal array
        BFScities.push_back(vertices[neighborVertex]);
      }

      // Check for cross edges
      for (int i = 0; i < int(weightedAdjMatrix[currentVertex].size()); i++) {
        if (weightedAdjMatrix[currentVertex][i] != 0 && visited[i] && i != start) {
          // Only print cross edge if it's not to a neighbor we just added
          bool isNewNeighbor = false;

          for (const auto& neighbor : neighbors) {
            if (neighbor.first == i) {
              isNewNeighbor = true;
              break;
            }
          }// if not a new neighbor,
          if (!isNewNeighbor) {
            cout << "Cross edge: ";
            cout << "Origin -> " << vertices[currentVertex] << " , ";
            cout << vertices[i] << " <- Destination\n\n";
          }
        }
      }
    }
    cout << "\nTotal Distance Traveled (Via Discovery Edges): " << totalDistance << " miles\n";

    // Displaying the BFS traversal order of cities
    for (int i = 0; i < int(BFScities.size()); i++) {
      if (i == 0) { cout << "\nBFS Traversal Order: ";}
      cout << BFScities[i];
      if (i != (int(BFScities.size()) - 1)) { cout << " -> ";}
    }
    cout << endl;
  }
};

#endif