
#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

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


public:

    // constructor
    Map();

    // adds a city's edges too the vector stored in Map object
    void AddCity(int nameCityOne, int nameCityTwo, int distance);

    // each city is stored in the vector as a number and will need decoded
    // pass the number to decode here to recieve the cities name string
    string CityDecoder(int toDecode);

    // display all cities and their distances to each other
    void DisplayMap();

    // function to handle the recursive DFS traversal of a graph stored in an Adjacency List structure.
    //void dfsRecursive(vector<bool>& visited, int currCity, vector<int>& result, vector<pair<int, int>>& discoveryEdges);
    void dfsRecursive(vector<bool>& visited, int currCity, vector<int>& result, vector<pair<int, int>>& discoveryEdges);

    // function to perform a DFS traversal
    void DFS();
};