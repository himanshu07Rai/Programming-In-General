int minCoins(int coins[], int M, int V)
{
    if (V == 0)
        return 0;

    vector<long long> dp(V + 1, 0);
    dp[0] = 0;

    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;

    for (int i = 0; i < M; i++)
    {
        if (coins[i] > V)
            continue;
        for (int j = coins[i]; j <= V; j++)
        {
            int rem = j - coins[i];
            if (dp[rem] != INT_MAX)
                dp[j] = min(dp[j], dp[rem] + 1);
        }
    }

    return dp[V] == INT_MAX ? -1 : dp[V];
}