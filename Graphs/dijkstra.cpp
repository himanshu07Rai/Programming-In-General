#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n + 1);

    int u, v, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        g[u].push_back(make_pair(v, wt));
        g[v].push_back(make_pair(u, wt));
    }

    cin >> source;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n + 1, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (it = g[prev].begin(); it != g[prev].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    cout << "The distances from source, " << source << ", are : \n";
    for (int i = 1; i <= n; i++)
        cout << distTo[i] << " ";
    cout << "\n";

    return 0;
}

/*

matrix


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, source;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, -1));

    int u, v, wt;
    for (int i = 0; i <= n; i++)
    {
        g[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        g[u][v] = wt;
        g[v][u] = wt;
    }

    cin >> source;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n + 1, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        // vector<pair<int, int>>::iterator it;
        int i;
        for (i = 1; i <= n; i++)
        {
            if (g[prev][i] != -1)
            {
                int nextDist = g[prev][i];
                if (distTo[i] > distTo[prev] + nextDist)
                {
                    distTo[i] = distTo[prev] + nextDist;
                    pq.push({distTo[i], i});
                }
            }
        }
    }

    cout << "The distances from source, " << source << ", are : \n";
    for (int i = 1; i <= n; i++)
        cout << distTo[i] << " ";
    cout << "\n";

    return 0;
}

*/