int cutRod(int price[], int n)
{
    vector<int> dp(n + 1, 0);
    for (int len = 1; len <= n; len++)
    {
        int m = 0;
        for (int i = 0; i < len; i++)
        {
            int remLen = len - i - 1;
            m = max(m, price[i] + dp[remLen]);
        }
        dp[len] = m;
    }
    return dp[n];
}