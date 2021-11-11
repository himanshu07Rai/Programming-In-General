#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph,vector<bool> &visited,stack<int>&st,int i)
{
    visited[i] = true;
    int n = graph[i].size();
    for(int j=0;j<n;j++)
    {
        if(!visited[graph[i][j]])
            dfs(graph,visited,st,graph[i][j]);
    }
    st.push(i);
}

void topologicalSort(vector<vector<int>> &graph)
{
    int V = graph.size();
    stack<int> st;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            dfs(graph,visited,st,i);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}




int main()
{
    int V,E,s,d;
    cin>>V>>E;
    vector<vector<int>> graph(v);
    for(int i=0;i<E;i++)
    {
        cin>>s>>d;
        graph[s].push_back(d);
    }

    // for(int i=0;i<graph.size();i++)
    // {
    //     for(auto j:graph[i])
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<" fd\n";
    // }
    // cout<<graph.size()<<" fd";

    topologicalSort(graph);
}