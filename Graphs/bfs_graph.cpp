#include <bits/stdc++.h>
using namespace std;

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
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                cout << node << " ";
                for (int i = 1; i <= V; i++)
                {
                    if (g[node][i] && !visited[i])
                    {
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    cout << "\n";
}