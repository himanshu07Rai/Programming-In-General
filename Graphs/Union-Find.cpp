    int findParent(int node,vector<int> &parent)
    {
        if(node==parent[node])
            return node;
        parent[node] = findParent(parent[node],parent);    //path compression
        return parent[node];
    }
    
int findComponents(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = n;
        vector<int> parent(n+1),rank(n+1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    // cout<<i+1<<" "<<j+1<<"\n";
                    int u = findParent(i+1,parent),v=findParent(j+1,parent);
                    // cout<<u<<" "<<v<<"\n";
                    if(u!=v)
                        ans--;
                    
                    // union by rank
                    
                    if(rank[u]<rank[v])
                        parent[u] = v;
                    else if(rank[v]<rank[u])
                        parent[v]=u;
                    else{
                        parent[v] = u;
                        rank[u]++;
                    }
                }
            }
        }
        return ans;
    }
