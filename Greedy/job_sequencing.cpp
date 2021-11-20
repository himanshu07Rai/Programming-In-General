#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(vector<Job> &arr, int n)
{
    sort(arr.begin(), arr.end(), comp);
    vector<int> ans(2); // no.    profit
    int d = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].dead > d)
            d = arr[i].dead;
    }
    vector<int> used(d, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead - 1; j >= 0; j--)
        {
            if (used[j] == -1)
            {
                ans[0]++;
                ans[1] += arr[i].profit;
                used[j] = arr[i].id;
                break;
            }
        }
    }

    for (int i : used)
        cout << i << " ";
    cout << "\n";
    return ans;
}

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n;
    cin >> n;
    vector<Job> arr(n);
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    vector<int> ans = JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1];
    // }
    return 0;
}