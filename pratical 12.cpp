
#include <iostream>
#include <climits>
using namespace std;

#define V 4

int graph[V][V] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

int minCost = INT_MAX;
int bestPath[V + 1];

void tsp(int currPos, int count, int cost,
         int path[], bool visited[])
{
    if (count == V && graph[currPos][0] != 0)
    {
        int totalCost = cost + graph[currPos][0];

        if (totalCost < minCost)
        {
            minCost = totalCost;

            for (int i = 0; i < V; i++)
                bestPath[i] = path[i];

            bestPath[V] = 0;
        }
        return;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && graph[currPos][i] != 0)
        {
            visited[i] = true;
            path[count] = i;

            tsp(i, count + 1,
                cost + graph[currPos][i],
                path, visited);

            visited[i] = false;
        }
    }
}

int main()
{
    int path[V + 1];
    bool visited[V] = {false};

    path[0] = 0;
    visited[0] = true;

    tsp(0, 1, 0, path, visited);

    cout << "Minimum Cost: " << minCost << endl;

    cout << "Optimal Path: ";

    for (int i = 0; i <= V; i++)
    {
        cout << bestPath[i];

        if (i < V)
            cout << " -> ";
    }

    cout << endl;

    return 0;
}
