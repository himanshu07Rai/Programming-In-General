#include <bits/stdc++.h>

using namespace std;

void print_Min_platforms(vector<int> &arr, vector<int> &dept, int n)
{
    int ans = 1;
    int atm = 1;
    int prev = 0, curr = 1;
    while (curr < n)
    {
        if (arr[curr] <= dept[prev])
        {
            atm++;
            curr++;
        }
        else
        {
            atm--;
            prev++;
        }
        ans = max(ans, atm);
    }
    cout << ans;
}

int main()
{
    int n, a, b;
    cin >> n;
    vector<int> arr(n);
    vector<int> dept(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[i] = a;
        dept[i] = b;
    }

    sort(arr.begin(), arr.end());
    sort(dept.begin(), dept.end());

    print_Min_platforms(arr, dept, n);
    return 0;
}