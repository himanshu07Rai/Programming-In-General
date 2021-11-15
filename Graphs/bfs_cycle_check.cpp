#include <bits/stdc++.h>
using namespace std;

bool cycleCheck(int node, vector<bool> &visited, vector<vector<int>> &graph)
{
    queue<pair<int, int>> q;
    q.push({node, -1});
    visited[node] = true;
    while (!q.empty())
    {
        int n = q.front().first;
        int p = q.front().second;
        q.pop();
        cout << n << " ";
        for (int i = 1; i <= graph.size(); i++)
        {
            if (graph[n][i])
            {
                // cout << n << "-" << i << "\n";
                if (!visited[i])
                {
                    // cout << "not visited  " << n << "-" << i << "\n";
                    visited[i] = true;
                    q.push({i, n});
                }
                else if (p != i)
                {
                    // cout << "visited  " << n << "-" << i << "\n";
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int V = 6, E = 6;
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
            if (cycleCheck(i, visited, g))
            {
                cout << "Cycle\n";
                return 0;
            }
        }
    }
    cout << "Cycle Not found\n";
}