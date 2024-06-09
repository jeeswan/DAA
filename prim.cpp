/*Theory of Prim's Algorithm:

    Prim's Algorithm: Prim's algorithm is a greedy algorithm used to find the minimum spanning tree (MST) of a connected, undirected graph. It starts with an arbitrary node and grows the tree by adding the cheapest edge that connects a vertex in the tree to a vertex outside the tree. This process continues until all vertices are included in the MST.

    Complexities:
        Time Complexity:
            Best Case: O(V2)O(V2) where VV is the number of vertices. This occurs when the graph is dense and represented using an adjacency matrix.
            Worst Case: O(V2)O(V2) where VV is the number of vertices. This also occurs when the graph is dense and represented using an adjacency matrix.
            Average Case: O(V2)O(V2) where VV is the number of vertices.
        Space Complexity:
            O(V2)O(V2) for storing the adjacency matrix.
        Auxiliary Space Complexity:
            O(V)O(V) for storing key values, parent array, and mstSet array.
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 6

int minKey(int key[], bool mstSet[], int& steps) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void primMST(int graph[V][V], int& steps) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, steps);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            steps++;
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Edge   Weight" << endl;
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0, 0},
        {2, 0, 3, 8, 5, 0},
        {0, 3, 0, 0, 7, 9},
        {6, 8, 0, 0, 9, 0},
        {0, 5, 7, 9, 0, 4},
        {0, 0, 9, 0, 4, 0}};
    int steps = 0;

    primMST(graph, steps);
    cout << "Number of steps taken: " << steps << endl;

    return 0;
}

