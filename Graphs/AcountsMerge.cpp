/*
Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
*/
// [
    
    
//     ["John","johnsmith@mail.com","john_newyork@mail.com"],  
    
    
//     ["John","john00@mail.com","johnsmith@mail.com"],
    
    
//     ["Mary","mary@mail.com"],
    
    
//     ["John","johnnybravo@mail.com"]
// ]

// [
    
//     ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
    
//     ["Mary","mary@mail.com"],
    
//     ["John","johnnybravo@mail.com"]
    
// ]



class Solution {
public:
    string find(string s,unordered_map<string,string> &parent)
    {
        if(parent[s]==s)
            return s;
        parent[s] = find(parent[s],parent);
        return parent[s];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> parent;
        unordered_map<string,string> owner;
        unordered_map<string,set<string>> commonParent;
        
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        
        for(int i=0;i<accounts.size();i++)
        {
            string u = find(accounts[i][1],parent);
            for(int j=2;j<accounts[i].size();j++)
            {
                string v = find(accounts[i][j],parent);
                parent[v] = u;
            }
        }
        
        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string p = find(accounts[i][j], parent);
                commonParent[p].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> ans;
        for(auto c : commonParent)
        {
            vector<string> temp(c.second.begin(),c.second.end());
            temp.insert(temp.begin(),owner[c.first]);
            ans.push_back(temp);
        }
        
        return ans;                
        
    }
};













