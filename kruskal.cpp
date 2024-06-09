/*
Theory of Kruskal's Algorithm:

    Kruskal's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph.
    The algorithm works by adding the smallest edge that connects two disjoint sets of vertices until all vertices are included in the
    MST.It starts with an empty graph and iteratively adds edges in ascending order of their weights, ensuring that adding an edge does
    not form a cycle in the graph.The algorithm terminates when all vertices are connected or when there are no more edges to consider.

Complexities:

    Time Complexity:
        Best Case: O(Elog?V)O(ElogV) 
        Worst Case: O(Elog?V)O(ElogV) 
        Average Case: O(Elog?V)O(ElogV) 
    Space Complexity:
        O(V)O(V) for storing the parent and rank arrays.
    Auxiliary Space Complexity:
        O(V)O(V) for storing the subsets array.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    int find(Subset subsets[], int i) {
        if (subsets[i].parent != i) {
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void Union(Subset subsets[], int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
        } else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    void kruskalMST(int& total_steps) {
        vector<Edge> result;
        int e = 0, i = 0;
        total_steps = 0;

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        Subset* subsets = new Subset[V];
        for (int v = 0; v < V; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        while (e < V - 1 && i < E) {
            total_steps++;
            Edge next_edge = edges[i++];
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);

            if (x != y) {
                result.push_back(next_edge);
                Union(subsets, x, y);
                ++e;
            }
        }

        cout << "Edges in the Minimum Spanning Tree:" << endl;
        for (i = 0; i < e; ++i) {
            cout << result[i].src << " - " << result[i].dest << "  Weight: " << result[i].weight << endl;
        }
    }
};

int main() {
    const int V = 6;
    const int E = 9;

    Graph graph(V, E);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 6);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 4, 5);
    graph.addEdge(2, 4, 7);
    graph.addEdge(2, 5, 9);
    graph.addEdge(3, 4, 1);
    graph.addEdge(3, 5, 8);
    graph.addEdge(4, 5, 4);

    int total_steps = 0; // Initialize total steps counter
    graph.kruskalMST(total_steps);

    cout << "Total number of steps: " << total_steps << endl; // Print total steps

    return 0;
}

