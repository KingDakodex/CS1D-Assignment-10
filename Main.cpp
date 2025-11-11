/*******************************************************************************
 * Name: Aaron, Dakota, and Cindy
 * Assignment: Assignment 10
 * Description:
 * 	This program implements graph using the Adjacency List and Adjacency Matrix
 * 	structure, and performs a BFS and DFS traversal on those graphs.
 *
 * ****************************************************************************/
#include "Header.h"

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
    // call BFS search of the directed map below
    //BFS();


    return 0;
}