#include <iostream>
#include <limits>
#include <vector>

char alphabetAt(int a) { return static_cast<char>('A' + a); }
int alphabetIndexOf(char a) { return static_cast<int>(a - 'A'); }

void printPath(std::vector<int>& parent, int j)
{
    if (parent[j] == -1) return;

    printPath(parent, parent[j]);

    printf("%c ", alphabetAt(j));
}

struct Graph
{
    std::vector<std::vector<int>> graph;

    explicit Graph(int vcount)
    {
        graph.resize(vcount);
        for (auto& l : graph)
        {
            l.resize(vcount);
        }
    }

    static void printSolution(std::vector<int>& dist, int src, int dst,
                              std::vector<int>& parent)
    {
        std::cout << alphabetAt(src) << " -> " << alphabetAt(dst) << std::endl;
        std::cout << "Distance: " << dist[dst] << " Path: " << alphabetAt(src)
                  << " ";
        printPath(parent, dst);
    }

    int minDistance(const std::vector<int>& dist,
                    const std::vector<bool>& sptSet) const
    {
        int min = std::numeric_limits<int>::max();
        int min_index = 0;
        int vcount = (int)graph.size();

        for (int v = 0; v < vcount; v++)
        {
            if (!sptSet[v] && dist[v] <= min)
            {
                min = dist[v], min_index = v;
            }
        }

        return min_index;
    }

    void dijkstra(char srcchar, char dstchar)
    {
        int vcount = (int)graph.size();
        int src = alphabetIndexOf(srcchar);
        int dst = alphabetIndexOf(dstchar);

        std::vector<int> dist(vcount, std::numeric_limits<int>::max());
        std::vector<int> parent(vcount, -1);
        std::vector<bool> sptSet(vcount, false);

        dist[src] = 0;

        for (int count = 0; count < vcount - 1; count++)
        {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < vcount; v++)
            {
                if (!sptSet[v] && graph[u][v] &&
                    dist[u] + graph[u][v] < dist[v])
                {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        printSolution(dist, src, dst, parent);
    }

    void add_link(const char a, const char b, const int w)
    {
        graph[alphabetIndexOf(a)][alphabetIndexOf(b)] = w;
    }
};
