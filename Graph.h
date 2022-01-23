#include <limits>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>

namespace Graphs
{
    using NodeId = char;

    struct Link {
        NodeId To;
        int Weight;

        Link(NodeId dest, int weight):
            To(dest),
            Weight(weight)
        {
        }
    };

    class Graph
    {
        std::unordered_map<NodeId, std::vector<Link>> _graph;

    public:
        Graph()
        {
        }

        void AddEdge(NodeId from, NodeId to, int weight)
        {
            if (std::any_of(
                this->_graph[from].begin(),
                this->_graph[from].end(),
                [&to](Link e) {
                    return e.To == to;
                }))
            {
                throw std::exception();
            }

            this->_graph[from].push_back(Link(to, weight));
        }

        int GetDistance(NodeId from, NodeId to)
        {
            std::unordered_map<NodeId, int> distanceTo;
            std::set<NodeId> unvisitedNodes;

            for (const auto &[key, value]: this->_graph) {
                distanceTo[key] = INT16_MAX;

                for (auto n: value)
                {
                    distanceTo[n.To] = INT16_MAX;
                    unvisitedNodes.insert(n.To);
                }

                unvisitedNodes.insert(key);
            }

            for (auto link: this->_graph[from])
            {
                distanceTo[link.To] = link.Weight;
            }
            unvisitedNodes.erase(from);

            distanceTo[from] = 0;
            while (!unvisitedNodes.empty())
            {
                auto it = std::min_element(
                    std::begin(unvisitedNodes),
                    std::end(unvisitedNodes),
                    [&distanceTo](const NodeId& l, const NodeId& r) { return distanceTo[l] < distanceTo[r]; }
                );

                NodeId currentVisitedNode = *it;

                for (auto link: this->_graph[currentVisitedNode])
                {
                    distanceTo[link.To] = std::min(
                        distanceTo[currentVisitedNode] + link.Weight,
                        distanceTo[link.To]
                    );
                }

                unvisitedNodes.erase(currentVisitedNode);
            }

            return distanceTo[to];
        }
    };
}
