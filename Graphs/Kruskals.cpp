#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, pair<int, int>>> viii;

int findParent(int node, vector<int> &parent)
{
    if (parent[node] < 0)
        return node;
    return findParent(parent[node], parent);
}

void unionByWeights(int s, int d, vector<int> &parent)
{
    if (parent[s] < parent[d])
    {
        parent[s] += parent[d];
        parent[d] = s;
    }
    else
    {
        parent[d] += parent[s];
        parent[s] = d;
    }
}

viii kruskals(viii g, int V)
{
    viii res;
    int s, d, w;
    vector<int> parent(V,-1);

    sort(g.begin(), g.end());

    int E = g.size();
    for (int i = 0; i < E; i++)
    {
        s = g[i].second.first;
        d = g[i].second.second;
        w = g[i].first;
        if (findParent(s, parent) != findParent(d, parent))
        {
            res.push_back(g[i]);
            unionByWeights(s, d, parent);
        }
    }
    return res;
}

int main()
{
    viii g, res;
    int V, E, s, d, w;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        cin >> s >> d >> w;
        g.push_back(make_pair(w,make_pair(s,d)));
    }

    res = kruskals(g, V);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
    {
        int w = res[i].first;
        cout << res[i].second.first << " -- " << res[i].second.second << endl;
        sum += w;
    }
    cout << "Min sum = " << sum;
    return 0;
}