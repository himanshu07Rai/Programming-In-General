/*
You are given an m x n integer matrix heights representing the height of each unit cell in a continent. The Pacific ocean touches the continent's left and top edges, and the Atlantic ocean touches the continent's right and bottom edges.

Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

*/

class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& heights,int prev,vector<vector<bool>> &ocean,vector<vector<int>> &dir)
    {
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || heights[i][j]<prev||ocean[i][j])
            return;
        ocean[i][j] = true;
        for(auto d:dir)
        {
            dfs(i+d[0],j+d[1],heights,heights[i][j],ocean,dir);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size(), m = heights[0].size();
        if(!n)
            return ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
         for(int j=0;j<m;j++)
        {
            dfs(0,j,heights,INT_MIN,pacific,dir);
            dfs(n-1,j,heights,INT_MIN,atlantic,dir);
        }

        for(int i=0;i<n;i++)
        {
            dfs(i,0,heights,INT_MIN,pacific,dir);
            dfs(i,m-1,heights,INT_MIN,atlantic,dir);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
