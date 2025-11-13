/*******************************************************************************
 * Name: Aaron, Dakota, and Cynthia
 * Assignment: Assignment 10
 * Description:
 * 	This program implements graph using the Adjacency List and Adjacency Matrix
 * 	structure, and performs a BFS and DFS traversal on those graphs.
 *
 * ****************************************************************************/
#include "Header.h"
#include "BFSdigraph.hpp"

int main()
{
    cout << "This program takes a graph of the United States with 12 cities\n"
        << "highlighted and performs both a DFS and BFS traversal of the map.\n"
        << "It then displays all of the edges' types per traversal and the\n"
        << "final ordering per traversal.\n\n";
    Map UnitedStates;
    UnitedStates.DisplayMap();
    cout << "______________________________________________________\n";
    cout << "\nPart A: DFS Traversal\n";
    //UnitedStates.DFS();

    cout << "\n______________________________________________________\n";
    cout << "\nPart B: BFS Traversal\n";
    BFSdigraph adjMatrix;

    // Perform a BFS traversal on the adjacency matrix starting at Denver (4)
    adjMatrix.BFS_algorithm(4);


    return 0;

}
