/*
The Kosaraju algorithm is a DFS based algorithm used to find Strongly Connected Components(SCC) in a graph. It is based on the idea that if one is able to reach a vertex v starting from vertex u, then one should be able to reach vertex u starting from vertex v and if such is the case, one can say that vertices u and v are strongly connected - they are in a strongly connected sub-graph.
*/

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<vector<int>> &adj)
{

    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<vector<int>> transpose)
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDfs(it, vis, transpose);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    // vector<int> adj[n],transpose;
    vector<vector<int>> adj(n), transpose(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    // vector<int> transpose[n];

    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     vis[i] = 0;
    //     for (auto it : adj[i])
    //     {
    //         transpose[it].push_back(i);
    //     }
    // }

    while (!st.empty())
    {
        int node = st.top();
        cout << node << " ";
        st.pop();
        // if (!vis[node])
        // {
        //     cout << "SCC: ";
        //     revDfs(node, vis, transpose);
        //     cout << endl;
        // }
    }
    cout << endl;

    return 0;
}