#include <bits/stdc++.h>

using namespace std;

int main()
{
    int V = 4, E = 4;
    vector<vector<int>> g(V + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    for (int i = 0; i <= V; i++)
    {
        for (int j = 0; j <= V; j++)
            cout << g[i][j] << " ";
        cout << "\n";
    }
}