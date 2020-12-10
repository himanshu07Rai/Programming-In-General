#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int m, int n)
{
    return i >= 0 && i < m && j >= 0 && j < n;
}

void dfs(vector<vector<int>> &g, vector<vector<int>> &visited, int i, int j, int m, int n)
{
    visited[i][j] = 1;
    int new_i, new_j;
    // int r[] = {-1, 0, 0, 1};
    // int c[] = {0, -1, 1, 0};
    int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int c[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int s = sizeof(r) / sizeof(int);
    for (int k = 0; k < s; k++)
    {
        new_i = i + r[k], new_j = j + c[k];
        if (isValid(new_i, new_j, m, n) && g[new_i][new_j] == 1 && visited[new_i][new_j] == 0)
            dfs(g, visited, new_i, new_j, m, n);
    }
}

int connectedComponents(vector<vector<int>> &g, int m, int n)
{
    int count = 0;
    vector<vector<int>> visited(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            visited[i].push_back(0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 1 && visited[i][j] == 0)
            {
                count++;
                dfs(g, visited, i, j, m, n);
            }
        }

    return count;
}

int main()
{
    int m, n, k;
    cin >> m >> n;
    vector<vector<int>> g(m);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> k;
            g[i].push_back(k);
        }
    cout << connectedComponents(g, m, n) << endl;
}