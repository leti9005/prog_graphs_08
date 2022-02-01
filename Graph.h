#include <iostream>
#include <limits>
#include <vector>

using intvector = std::vector<int>;

char int2char(int a) {
    return char('A' + a);
}

int char2int(char a) {
    return int(a - 'A');
}

void printPath(intvector &parent, int j) {
    if (parent[j] == -1) {
        return;
    }

    printPath(parent, parent[j]);

    printf("%c ", int2char(j));
}

struct Graph {
    std::vector<intvector> graph;

    explicit Graph(int vcount) {
        graph.resize(vcount);
        for (auto &l: graph) {
            l.resize(vcount);
        }
    }

    static void printSolution(intvector &dist, int src, int dst, intvector &parent) {
        std::cout << int2char(src) << " -> " << int2char(dst) << std::endl;
        std::cout << "Distance: " << dist[dst] << " Path: " << int2char(src) << " ";
        printPath(parent, dst);
    }

    int minDistance(const intvector &dist, const std::vector<bool> &sptSet) const {
        int min = std::numeric_limits<int>::max();
        int min_index = 0;
        int vcount = (int ) graph.size();

        for (int v = 0; v < vcount; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v], min_index = v;
            }
        }

        return min_index;
    }

    void dijkstra(char srcchar, char dstchar) {
        int vcount = (int) graph.size();
        int src = char2int(srcchar);
        int dst = char2int(dstchar);

        intvector dist(vcount, std::numeric_limits<int>::max());
        intvector parent(vcount, -1);
        std::vector<bool> sptSet(vcount, false);

        dist[src] = 0;

        for (int count = 0; count < vcount - 1; ++count) {
            int u = minDistance(dist, sptSet);

            sptSet[u] = true;

            for (int v = 0; v < vcount; v++) {
                if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
        printSolution(dist, src, dst, parent);
    }

    void add_link(const char a, const char b, const int w) {
        graph[char2int(a)][char2int(b)] = w;
    }

};

