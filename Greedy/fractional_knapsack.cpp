#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;
    double valuePerkg;
};

bool comp(Item a, Item b)
{
    return a.valuePerkg > b.valuePerkg;
}

double fractionalKnapsack(int W, vector<Item> &arr, int n)
{
    sort(arr.begin(), arr.end(), comp);
    double ans = 0;
    for (auto i : arr)
    {
        if (W >= i.weight)
        {
            ans += i.value;
            W -= i.weight;
        }
        else
        {
            ans += W * i.valuePerkg;
            break;
        }
    }

    return ans;
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<Item> arr(n);
    for (int i = 0; i < n; i++)
    {
        int val, weight;
        cin >> val >> weight;
        arr[i].value = val;
        arr[i].weight = weight;
        arr[i].valuePerkg = (double)(val / weight);
    }
    double ans = fractionalKnapsack(W, arr, n);
    cout << ans;
}
