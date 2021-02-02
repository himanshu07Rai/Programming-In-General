/*
There are given n ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to the sum of their lengths. We need to connect the ropes with minimum cost.
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int len[] = { 4, 3, 2, 6 }; 
    int size = sizeof(len) / sizeof(len[0]);
    priority_queue <int, vector<int>, greater<int> > minh;
    for(int i=0;i<size;i++)
    {
        minh.push(len[i]);
    }
    long long cost = 0;
    int first = 0, second=0;
    while(minh.size()>=2)
    {
        first = minh.top();
        minh.pop();
        second = minh.top();
        minh.pop();
        cost+=first+second;
        minh.push(first+second);
    }
    cout<<"cost : "<<cost<<"\nlength : "<<minh.top();
}