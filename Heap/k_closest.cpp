#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { 5,6,7,8,9 }; 
    int k=3,x=7;
    int n = sizeof(arr) / sizeof(arr[0]); 
    priority_queue <pair<int, int> > maxh;
    for (int i = 0; i < n; i++) 
    {  
        maxh.push(make_pair(abs(x-arr[i]),arr[i])); 
        if(maxh.size()>k) 
        {
            maxh.pop(); 
        } 
    }  
    while(maxh.size()>0)
    {
        cout<<maxh.top().second<<" ";
        maxh.pop();
    }

	return 0;
}