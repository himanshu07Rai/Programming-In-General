#include <bits/stdc++.h>
using namespace std;

bool cycleCheck(int node, int par, vector<bool> &visited, vector<vector<int>> &graph)
{
    cout << node << " ";
    visited[node] = true;
    for (int i = 1; i <= graph.size(); i++)
    {
        if (graph[node][i])
        {
            if (!visited[i])
            {
                if (cycleCheck(i, node, visited, graph))
                    return true;
            }
            else if (i != par)
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 7, E = 6;
    vector<vector<int>> g(V + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    vector<bool> visited(V + 1, false);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            if (cycleCheck(i, -1, visited, g))
            {
                cout << "Cycle\n";
                return 0;
            }
        }
    }
    cout << "Cycle Not found\n";
}