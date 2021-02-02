#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { 1,1,1,2,2,3,3,3,4 }; 
    int k=2;
    int n = sizeof(arr) / sizeof(arr[0]); 
    unordered_map <int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minh;
    for (auto i = mp.begin(); i !=mp.end(); i++) 
    {  
        minh.push(*i); 
        if(minh.size()>k) 
        {
            minh.pop(); 
        } 
    }  
    while(minh.size()>0)
    {
        cout<<minh.top().second<<" ";
        minh.pop();
    }

	return 0;
}