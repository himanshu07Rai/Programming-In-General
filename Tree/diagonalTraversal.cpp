/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
vector<int> solve(Tree* root) {
    queue<pair<Tree*,int>> q;
    // map<int,vector<int>>m;
    vector<int> ans(1);
    q.push({root,0});
    while(!q.empty())
    {
        auto [node,t] = q.front();
        q.pop();
        if (ans.size() > t)
            ans[t]+=node->val;
        else
            ans.push_back(node->val);
        // m[t].push_back(node->val);
        if(node->left)
        {
            q.push({node->left,t+1});
        }
        if(node->right)
        {
            q.push({node->right,t});
        }
    }

    // for(auto it : m)
    // {
    //     int sum = 0;
    //     for(auto i:it.second)
    //     {
    //         sum+=i;
    //     }
    //     ans.push_back(sum);
    // }

    return ans;
}
