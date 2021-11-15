#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &graph)
{
    cout << node << " ";
    visited[node] = 1;
    for (int i = 1; i <= graph.size(); i++)
    {
        if (graph[node][i] && !visited[i])
            dfs(i, visited, graph);
    }
}

int main()
{
    int V = 7, E = 6;
    vector<vector<int>> graph(V + 1, vector<int>(V + 1, 0));
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    vector<bool> visited(V + 1, false);

    for (int i = 1; i <= V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, graph);
        }
    }
    cout << "\n";
}