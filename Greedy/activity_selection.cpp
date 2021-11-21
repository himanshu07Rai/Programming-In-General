#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
        return (a[0] < b[0]);
    else
        return (a[1] < b[1]);
}

void print_Max_Activities(vector<vector<int>> &arr, int n)
{
    int count = 1;
    int prev = 0;

    for (int curr = 1; curr < n; curr++)
    {
        if (arr[curr][0] >= arr[prev][1])
        {
            count++;
            prev = curr;
        }
    }
    cout << count;
}

int main()
{
    int n, a, b;
    cin >> n;
    vector<vector<int>> meeting(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        meeting[i].push_back(a);
        meeting[i].push_back(b);
    }

    sort(meeting.begin(), meeting.end(), comp);

    print_Max_Activities(meeting, n);
    return 0;
}