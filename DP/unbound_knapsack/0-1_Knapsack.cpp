int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][W];
}

// 1d

int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<int> dp(W + 1, 0);
    for (int cap = 1; cap <= W; cap++)
    {
        int m = 0;
        for (int i = 0; i < N; i++)
        {
            if (wt[i] <= cap)
            {
                int remCap = cap - wt[i];
                m = max(m, val[i] + dp[remCap]);
            }
        }
        dp[cap] = m;
    }
    return dp[W];
}