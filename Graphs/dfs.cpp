/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/


class Solution {
public:
    bool isNeighbour(int i,int j,int n,int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &visited, int i,int j,int n,int m,vector<vector<int>>&dir)
    {
        visited[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0],nj=j+dir[k][1];
            if(isNeighbour(ni,nj,n,m) && grid[ni][nj]=='1' && !visited[ni][nj])
                dfs(grid,visited,ni,nj,n,m,dir);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if(!n)
            return 0;
        int count = 0;
        vector<vector<bool>> visited(n,vector<bool>(m));
        vector<vector<int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(grid, visited, i, j,n,m,dir);
                }
            }
        }
        

    return count;
    }
};



/*-------------------------------------------------------------------------------------------------------------------------------------------------*/


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
