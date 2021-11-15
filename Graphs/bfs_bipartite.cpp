#include <bits/stdc++.h>

using namespace std;

bool bipartiteBfs(int src, vector<vector<int>> &g, vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : g[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if (color[it] == color[node])
                return false;
        }
    }
    return true;
}

bool checkBipartite(vector<vector<int>> &g)
{
    int V = g.size();
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteBfs(i, g, color))
                return false;
        }
    }
    return true;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> g(V);
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (checkBipartite(g))
        cout << "yes\n";
    else
        cout << "no\n";
}