#include <iostream>
#include <map>
#include <vector>
#include "Graph.h"

using namespace std;

int main()
{
    Graphs::Graph graph;
    graph.AddEdge('A', 'B', 4);
    graph.AddEdge('A', 'C', 2);

    graph.AddEdge('C', 'E', 5);
    graph.AddEdge('C', 'B', 1);
    graph.AddEdge('B', 'C', 3);

    graph.AddEdge('B', 'D', 2);
    graph.AddEdge('B', 'E', 3);
    graph.AddEdge('E', 'D', 1);

    Graphs::NodeId from;
    Graphs::NodeId to;

    cout << "Measure distance" << endl;
    cout << "From (char): ";
    cin >> from;
    cout << "To (char): ";
    cin >> to;

    auto distance = graph.GetDistance(from, to);

    if (distance == INT16_MAX)
    {
        cout << "No path between specified nodes." << endl;
        return 0;
    }

    cout << distance << endl;

    return 0;
}
