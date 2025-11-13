
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

// makes identifying cities easier
enum City
{
    Seattle = 1,
    Chicago = 2,
    Boston = 3,
    SanFrancisco = 4,
    Denver = 5,
    NewYork = 6,
    LosAngeles = 7,
    KansasCity = 8,
    Atlanta = 9,
    Dallas = 10,
    Houston = 11,
    Miami = 12
};

// class to track the cities  in a Adjacency List Structure
class Map
{
private:
    //int Vertices = 12;

    // Vector to store data for cities and their distances
    vector<vector<pair<int, int>>> adjList;
    vector<vector<pair<int, int>>> reverseAdjList; // same list but with edge direction reversed for determining if the graph is strongly connected


public:

    // constructor
    Map();

    //getters for each list to call the DFS algorithm (so as to avoid having to fully copy and paste the existing DFS alg so that it access the reverse adjacency list
    vector<vector<pair<int, int>>>& getAdjList() {return adjList;}
    vector<vector<pair<int, int>>>& getReverseAdjList() {return reverseAdjList;}


    // adds a city's edges too the vector stored in Map object
    void AddCity(int nameCityOne, int nameCityTwo, int distance);

    // each city is stored in the vector as a number and will need decoded
    // pass the number to decode here to recieve the cities name string
    string CityDecoder(int toDecode);

    // display all cities and their distances to each other
    void DisplayMap();

    // function to handle the recursive DFS traversal of a graph stored in an Adjacency List structure.
    void dfsRecursive(vector<bool>& visited, int currCity, vector<int>& result, vector<vector<pair<int, int>>>& list, vector<bool>& inStack, vector<int>& discovery, vector<int>& finish, int& timeStamp, vector<vector<pair<int, int>>>& edges, set<pair<int, int>>& discoveryEdges, int& dist);

    // function to perform a DFS traversal
    void DFS(vector<vector<pair<int, int>>> list);
};
