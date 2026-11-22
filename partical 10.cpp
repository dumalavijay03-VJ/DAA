
#include <iostream>
#include <algorithm>
using namespace std;

#define V 4
#define E 5

// Structure to represent an edge
struct Edge
{
    int src, dest, weight;
};

// Find parent of a vertex
int find(int parent[], int i)
{
    if (parent[i] == i)
        return i;

    return find(parent, parent[i]);
}

// Union of two sets
void Union(int parent[], int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);

    parent[xset] = yset;
}

// Compare edges by weight
bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// Kruskal's Algorithm
void KruskalMST(Edge edges[])
{
    sort(edges, edges + E, compare);

    int parent[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "Edges in Minimum Spanning Tree:\n";

    int totalWeight = 0;
    int count = 0;

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = find(parent, edges[i].src);
        int v = find(parent, edges[i].dest);

        if (u != v)
        {
            cout << edges[i].src << " - "
                 << edges[i].dest << " : "
                 << edges[i].weight << endl;

            totalWeight += edges[i].weight;

            Union(parent, u, v);
            count++;
        }
    }

    cout << "Total MST Weight: " << totalWeight << endl;
}

int main()
{
    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    KruskalMST(edges);

    return 0;
}
