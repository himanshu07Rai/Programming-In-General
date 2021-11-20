#include <bits/stdc++.h>
using namespace std;

int perfectSum(int arr[], int N, int sum)
{
    // Your code goes here
    vector<vector<int>> dp(N + 1, vector<int>(sum + 1, 1));
    for (int j = 1; j < sum + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % 1000000007;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][sum];
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cout << perfectSum(a, n, sum) << "\n";
    }
    return 0;
}