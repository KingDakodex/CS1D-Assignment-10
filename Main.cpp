/*******************************************************************************
 * Name: Aaron, Dakota, and Cynthia
 * Assignment: Assignment 10
 * Description:
 * 	This program implements a directed graph using the Adjacency List and
 * 	Adjacency Matrix structures, performs a BFS and DFS traversal on the graph,
 * 	 and determines if the graph is strongly connected.
 *
 * ****************************************************************************/
#include "Header.h"
#include "BFSdigraph.hpp"

int main()
{
    cout << "This program takes a directed graph of the United States with 12 cities\n"
         << "highlighted and performs both a DFS and BFS traversal of the map.\n"
         << "It then displays all of the edges' types per traversal and the\n"
         << "final ordering per traversal. Additionally, it also classifies\n"
         << "whether or not the graph in question is strongly connected. \n\n";

    Map UnitedStates;
    UnitedStates.DisplayMap();
    cout << "______________________________________________________\n";
    cout << "\nPart A: DFS Traversal\n";
    UnitedStates.DFS(UnitedStates.getAdjList());

    cout << "\n______________________________________________________\n";
    cout << "\nPart B: BFS Traversal\n";
    BFSdigraph adjMatrix;

    // Perform a BFS traversal on the adjacency matrix starting at Denver (4)
    adjMatrix.BFS_algorithm(4);

    cout << "\n______________________________________________________\n";
    cout << "\nPart C: Reversed Edge DFS Traversal\n";
    UnitedStates.DFS(UnitedStates.getReverseAdjList());
    cout << "\n\nSince all vertices are reachable by way of DFS in both in\n"
         <<	"the original graph and the same graph with all of its edges reversed,\n"
         << "this graph is considered strongly connected.";

    return 0;

}
