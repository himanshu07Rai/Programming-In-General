#include<bits/stdc++.h>
using namespace std;

int findParent(int node,vector<int> &parent)
    {
        if(parent[node]<0)
            return node;
        return findParent(parent[node],parent); 
    }

void unionByWeight(int u,int v,vector<int>&parent)
{
    int pu = fundParent(u,parent),pv = findParent(v,parent);
    if(pu!=pv)
    {
        if(parent[pu]<parent[pv])
        {
            parent[pu]+=parent[pv];
            parent[pv] = pu;
        }
        else{
            parent[pv]+=parent[pu];
            parent[pu] = pv;
        }
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

//     int findParent(int node,vector<int> &parent)
//     {
//         if(node==parent[node])
//             return node;
//         parent[node] = findParent(parent[node],parent);    //path compression
//         return parent[node];
//     }
    
// int findComponents(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         int ans = n;
//         vector<int> parent(n+1),rank(n+1);
//         for(int i=1;i<=n;i++)
//             parent[i]=i;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(isConnected[i][j]==1)
//                 {
//                     // cout<<i+1<<" "<<j+1<<"\n";
//                     int u = findParent(i+1,parent),v=findParent(j+1,parent);
//                     // cout<<u<<" "<<v<<"\n";
//                     if(u!=v)
//                         ans--;
                    
//                     // union by rank
                    
//                     if(rank[u]<rank[v])
//                         parent[u] = v;
//                     else if(rank[v]<rank[u])
//                         parent[v]=u;
//                     else{
//                         parent[v] = u;
//                         rank[u]++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
