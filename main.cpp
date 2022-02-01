#include "Graph.h"

using namespace std;

int main()
{
    Graph graph1(6);
    graph1.add_link('A', 'B', 4);
    graph1.add_link('A', 'C', 2);

    graph1.add_link('C', 'E', 5);
    graph1.add_link('C', 'B', 1);

    graph1.add_link('B', 'D', 2);
    graph1.add_link('B', 'E', 3);
    graph1.add_link('E', 'D', 1);

    char from;
    char to;

    cout << "Get path" << endl;
    cout << "From (char): ";
    cin >> from;
    cout << "To (char): ";
    cin >> to;

    graph1.dijkstra(from, to);
    std::cout << std::endl;

    return 0;
}
