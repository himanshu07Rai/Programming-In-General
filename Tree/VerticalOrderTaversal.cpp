/*
Leetcode 987

Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        int h = 0,v = 0;
        q.push({root,{h,v}});
        map<int,vector<pair<int,int>>>m;
        while(!q.empty())
        {
            auto [node,p]= q.front();
            auto [h,v]= p;
            q.pop();
            m[v].push_back({h,node->val});
            if(node->left)q.push({node->left,{h+1,v-1}});
            if(node->right)q.push({node->right,{h+1,v+1}});
        }
        vector<vector<int>> ans;
        for(auto it : m)
        {
            sort(it.second.begin(),it.second.end());
            vector<int> t;
            for(auto i : it.second)
            {
                // cout<<i.first<<" ";
                t.push_back(i.second);
            }
            
            ans.push_back(t);
            // cout<<endl;
        }
        return ans;
    }
};
