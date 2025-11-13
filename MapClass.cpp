#include "Header.h"

// Map Class Definitions

// constructor, makes initial map using AddCity
Map::Map()
{
    // size the list too 13, only 12 cities but enum starts at 1 so the 0'th spot will be left empty
    adjList.resize(13);
    reverseAdjList.resize(13);

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
    reverseAdjList[nameCityTwo].push_back({nameCityOne, distance });

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

    cout << "\n\nReversed Edges Graph:\n";
    for (int i = 1; i < reverseAdjList.size(); i++)
    {
        cout << CityDecoder(i) << ": ";
        for (auto& j : reverseAdjList[i])
        {
            cout << "{" << CityDecoder(j.first) << ", " << j.second << "} ";
        }
        cout << endl;
    }
}

// Comment blocked due too an error: "MapClass.cpp(132,34): error C2955: 'std::pair': use of class template requires template argument list"
// function to handle the recursive DFS traversal of a graph stored in an Adjacency List structure.
// note for future reference: only the visited, currCity and result parameters are necessary for a correct DFS traversal. Everything else works as a helper to the other parts of this assignment
void Map::dfsRecursive(vector<bool>& visited, int currCity, vector<int>& result, vector<vector<pair<int, int>>>& list, vector<bool>& inStack, vector<int>& discovery, vector<int>& finish, int& timeStamp, vector<vector<pair<int, int>>>& edges, set<pair<int, int>>& discoveryEdges, int& dist) {
    visited[currCity] = true;
    inStack[currCity] = true;
    discovery[currCity] = ++timeStamp;

    result.push_back(currCity);

    // visit each adjacent city given it has yet to be visited
    while (true) {
        pair<int, int> edgeWSmallMileage(-1, INT_MAX);

        // find the unvisited neighbor with smallest mileage
        for (auto& i : list[currCity]) {
            if (!visited[i.first] && i.second < edgeWSmallMileage.second) {
                edgeWSmallMileage = i;
            }
        }

        if (edgeWSmallMileage.first == -1) // no unvisited neighbors left
            break;

        int nextCity = edgeWSmallMileage.first;
        dist += edgeWSmallMileage.second;
        discoveryEdges.insert({currCity, nextCity});	// to avoid overcounting discovery edges as forward edges
        edges[0].push_back(pair(currCity, nextCity));	// update this upcoming edge traversal as a discovery edge
        dfsRecursive(visited, nextCity, result, list, inStack, discovery, finish, timeStamp, edges, discoveryEdges, dist);
    }

    // classify edge types of already visited adjacent vertices
    for(auto& i : list[currCity]) {
        if(visited[i.first] && !discoveryEdges.count({currCity, i.first})) {
            if(inStack[i.first])
                edges[2].push_back({currCity, i.first});	// back edge
            else if (discovery[currCity] < discovery[i.first])
                edges[1].push_back({currCity, i.first}); // forward edge
            else
                edges[3].push_back({currCity, i.first}); // cross edge
        }
    }

    // this city's been fully explored:
    inStack[currCity] = false;
    finish[currCity] = ++timeStamp;
}


// function to set up and return a DFS traversal of graph.
void Map::DFS(vector<vector<pair<int, int>>> list) {
    // instantiate the two lists required to perform DFS traversal and identify the city to start at (Denver).
    vector<bool> visited(list.size(), false);
    vector<int> result;
    int start = Denver;
    vector<bool> inStack(list.size(), false); // denotes if an edge is in the call stack
    vector<int> discovery(list.size(), 0);
    vector<int> finish(list.size(), 0);
    int timeStamp = 0;
    vector<vector<pair<int, int>>> edges(4); // store all edges based on their type: edges[0] = discovery edge, edges[1] = forward edge, edges[2] = back edge, edges[3] = cross edge
    int dist = 0;	// distance traveled along discovery edges
    set<pair<int, int>> discoveryEdges;

    // perform DFS traversal
    dfsRecursive(visited, start, result, list, inStack, discovery, finish, timeStamp, edges, discoveryEdges, dist);

    // output DFS traversal:
    // print edges and according types
    vector<string> edgeNames = {"Discovery Edges", "Forward Edges", "Back Edges", "Cross Edges"};
    cout << "\nEdges:\n";
    for (int i = 0; i < 4; i++) {
        cout << edgeNames[i] << ":\n";
        for (auto& e : edges[i]) {
            cout << "  " << CityDecoder(e.first)
            << " -> " << CityDecoder(e.second) << "\n";
        }

        cout << endl;
    }

    //print total distance traveled
    cout << "\nTotal Distance Traveled Between Discovery Edges: " << dist << " miles.\n";

    // output result:
    cout << "\nDFS order:\n";
    int numCitiesOutput = 0; //only for output cleanliness, used to determine whether or not a comma is needed.
    for (int city : result) {
        string name = CityDecoder(city);
        cout << name;
        numCitiesOutput++;
        if (numCitiesOutput < result.size())
            cout << ", ";
    }
}

