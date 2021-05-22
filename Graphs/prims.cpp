#include<bits/stdc++.h>
using namespace std;

int main(){
    int V,E;
    cin>>V>>E;
    vector< vector<int> > graph(V,vector<int>(V,INT_MAX));

    while(E--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
	
    vector<int> parent(V,-1);
    vector<bool> mst(V);
    vector<int> key(V,INT_MAX);
    
    priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;

    key[0] = 0;
    pq.push({key[0], 0});    //{key[0],0}

    while(!pq.empty())
    { 
        int u = pq.top().second; 
        pq.pop();         
        mst[u] = true; 
        for(int i=0;i<V;i++)
        {
            if(graph[u][i]!=INT_MAX && !mst[i] && graph[u][i]<key[i])
            {
                parent[i] = u;
                key[i] = graph[u][i];
                pq.push({key[i],i});
            }
        }            
    } 
    
    for (int i = 1; i < V; i++) 
        cout << parent[i] << " - " << i <<" \n"; 
	return 0;
}