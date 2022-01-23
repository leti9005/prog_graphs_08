#include <iostream>
#include <map>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{
    Graphs::Graph graph;
    graph.AddEdge('A', 'B', 4);
    graph.AddEdge('A', 'C', 3);
    graph.AddEdge('A', 'E', 7);
    graph.AddEdge('B', 'D', 5);
    graph.AddEdge('D', 'F', 2);

    cout << graph.GetDistance('A', 'F') << endl;


    // int from, to;
    // cout << "Print start vertex (0-" << endl;  //<< graph.get_len() << "): ";
    // cin >> from;
    // cout << "Print end vertex: ";
    // cin >> to;

    return 0;
}
