#include <bits/stdc++.h>

using namespace std;

long long int count(int S[], int m, int n)
{

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; i++)
    {
        if (S[i] > n)
            continue;
        for (int j = S[i]; j <= n; j++)
        {
            int rem = j - S[i];
            dp[j] += dp[rem];
        }
    }

    return dp[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    cout << count(arr, m, n) << endl;
}