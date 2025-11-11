#include "Header.h"

// Map Class Definitions

// constructor, makes initial map using AddCity
Map::Map()
{
    // size the list too 13, only 12 cities but enum starts at 1 so the 0'th spot will be left empty
    adjList.resize(13);

    // add all cities
    AddCity(Seattle, SanFrancisco, 807);
    AddCity(Seattle, Denver, 1331);
    AddCity(SanFrancisco, LosAngeles, 381);
    AddCity(LosAngeles, Denver, 1015);
    AddCity(Denver, Chicago, 1003);
    AddCity(Denver, SanFrancisco, 1267);
    AddCity(Chicago, Seattle, 2097);
    AddCity(Chicago, Boston, 983);
    AddCity(Boston, NewYork, 214);
    AddCity(NewYork, Chicago, 787);
    AddCity(NewYork, Atlanta, 888);
    AddCity(Atlanta, Miami, 661);
    AddCity(Miami, Houston, 1187);
    AddCity(Houston, Atlanta, 810);
    AddCity(Houston, Dallas, 239);
    AddCity(Dallas, LosAngeles , 1435);
    AddCity(Dallas, Atlanta, 781);
    AddCity(Dallas, KansasCity, 496);
    AddCity(KansasCity, LosAngeles, 1663);
    AddCity(KansasCity, Denver, 599);
    AddCity(KansasCity, Chicago, 533);
    AddCity(KansasCity, NewYork, 1260);
    AddCity(KansasCity, Atlanta, 864);

}

// adds a SINGLE city too the list and one directed edge to another city. must be repeated for each edge
void Map::AddCity(int nameCityOne, int nameCityTwo, int distance)
{
    // add the first city and its distance too the second
    adjList[nameCityOne].push_back({ nameCityTwo, distance });
    // add the second city and its distance too the first
    //adjList[nameCityTwo].push_back({ nameCityOne, distance });
}

// passed a number to decode will return the correct name for that number
string Map::CityDecoder(int toDecode)
{
    // initlize as an error code, if it ISN'T replaced something is wrong
    string toReturn = "WRONG VALUE FED";

    // Assign the correct name to return
    switch (toDecode)
    {
    case Seattle:
        toReturn = "Seattle";
        break;
    case Chicago:
        toReturn = "Chicago";
        break;
    case Boston:
        toReturn = "Boston";
        break;
    case SanFrancisco:
        toReturn = "San Francisco";
        break;
    case Denver:
        toReturn = "Denver";
        break;
    case NewYork:
        toReturn = "New York";
        break;
    case LosAngeles:
        toReturn = "Los Angeles";
        break;
    case KansasCity:
        toReturn = "Kansas City";
        break;
    case Atlanta:
        toReturn = "Atlanta";
        break;
    case Dallas:
        toReturn = "Dallas";
        break;
    case Houston:
        toReturn = "Houston";
        break;
    case Miami:
        toReturn = "Miami";
        break;
    }

    // return the correct name
    return toReturn;
}

void Map::DisplayMap()
{
    for (int i = 1; i < adjList.size(); i++)
    {
        cout << CityDecoder(i) << ": ";
        for (auto& j : adjList[i])
        {
            cout << "{" << CityDecoder(j.first) << ", " << j.second << "} ";
        }
        cout << endl;
    }
}

/* Comment blocked due too an error: "MapClass.cpp(132,34): error C2955: 'std::pair': use of class template requires template argument list"
// function to handle the recursive DFS traversal of a graph stored in an Adjacency List structure.
// note for future reference: only the visited, currCity and result parameters are necessary for a correct DFS traversal. Everything else works as a helper to the other parts of this assignment
void Map::dfsRecursive(vector<bool>& visited, int currCity, vector<int>& result, vector<pair<int, int>>& discoveryEdges) {
    visited[currCity] = true;
    result.push_back(currCity);

    // visit each adjacent city given it has yet to be visited
    while (true) {
        pair<int, int> edgeWSmallMileage(-1, INT_MAX);

        // find the unvisited neighbor with smallest mileage
        for (auto& i : adjList[currCity]) {
            if (!visited[i.first] && i.second < edgeWSmallMileage.second) {
                edgeWSmallMileage = i;
            }
        }

        if (edgeWSmallMileage.first == -1) // no unvisited neighbors left
            break;

        int nextCity = edgeWSmallMileage.first;
        discoveryEdges.push_back(pair(currCity, nextCity));	//update this upcoming edge traversal as a discovery edge
        dfsRecursive(visited, nextCity, result, discoveryEdges);
    }
}


// function to set up and return a DFS traversal of graph.
void Map::DFS() {
    // instantiate the two lists required to perform DFS traversal and identify the city to start at (Denver).
    vector<bool> visited(adjList.size(), false);
    vector<int> result;
    int start = Denver;
    vector<pair<int, int>> discoveryEdges; // where first = cityOne, and second = cityTwo (the joint of them denoting an edge that connects the two cities).
    int dist = 0;	// distance traveled along discovery edges

    // perform DFS traversal
    dfsRecursive(visited, start, result, discoveryEdges);

    // output DFS traversal:
    // print edges and according types
    cout << "\nEdges:\n";

    for (int i = 1; i < adjList.size(); i++) {
        for (auto& nbr : adjList[i]) {
            int u = i;
            int v = nbr.first;

            // Only print if this is the first appearance of the edge, skips the other orientation of the same edges in the adjacency list
            if (u >= v) continue;

            string edgeType = ": Back Edge";

            // check if (u,v) is a discovery edge
            for (auto& edge : discoveryEdges) {
                if ((edge.first == u && edge.second == v) || (edge.first == v && edge.second == u)) {
                    edgeType = ": Discovery Edge";
                    break;
                }
            }

            cout << CityDecoder(u) << " ---> " << CityDecoder(v) << edgeType << "\n";
        }
    }

    // sum distances along discovery edges
    for (pair<int, int> edge : discoveryEdges) {
        int i = 0;
        while (edge.second != adjList[edge.first][i].first && i < 12) // find corresponding edge within the adjList
            i++;
        // found, now get distance along this discovery edge and sum
        dist += adjList[edge.first][i].second;
    }
    cout << "\nTotal Distance Traveled Between Discovery Edges: " << dist << " miles.\n";
    cout << "\nDFS order:\n";
    int numCitiesOutput = 0; //only for output cleanliness, used to determine whether or not a comma is needed.
    for (int city : result)
    {
        string name = CityDecoder(city);
        cout << name;
        numCitiesOutput++;
        if (numCitiesOutput < result.size())
            cout << ", ";
    }
}
*/