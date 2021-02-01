/*
Given an array of n elements, where each element is at most k away from its target position, devise an algorithm that sorts in O(n log k) time. For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array.
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = { 2, 6, 3, 12, 56, 8 }; 
    int k=3;
    int n = sizeof(arr) / sizeof(arr[0]); 
    priority_queue <int, vector<int>, greater<int> > minh;
    for (int i = 0; i < n; i++) 
    {  
        minh.push(arr[i]); 
        if(minh.size()>k) 
        {
            cout<<minh.top()<<" ";
            minh.pop(); 
        } 
    }  
    while(minh.size()>0)
    {
        cout<<minh.top()<<" ";
        minh.pop();
    }

	return 0;
}