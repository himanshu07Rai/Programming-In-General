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

    cout << "Following activities are selected \n";

    int i = 0;
    cout << "(" << arr[i][0] << ", " << arr[i][1] << ")\n";

    for (int j = 1; j < n; j++)
    {
        if (arr[j][0] >= arr[i][1])
        {
            cout << "(" << arr[j][0] << ", " << arr[j][1] << ") \n";
            i = j;
        }
    }
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