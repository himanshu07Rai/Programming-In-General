int perfectSum(int arr[], int N, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(N+1,vector<int>(sum+1,true));
        for(int j=1;j<sum+1;j++)
            dp[0][j] = false;
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = (dp[i-1][j]+dp[i-1][j-arr[i-1]])%1000000007;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][sum];
	}