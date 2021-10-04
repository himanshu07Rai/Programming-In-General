class Solution{
public:
    bool subsetSum(int N,int arr[],long long sum)
    {
        vector<vector<bool>>dp(N+1,vector<bool>(sum+1,true));
        for(int j=1;j<sum+1;j++)dp[0][j] = false;
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[N][sum];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        long long sum = 0;
        for(int i=0;i<N;i++)
            sum+=arr[i];
        if(sum%2!=0)
            return 0;
        if(subsetSum(N,arr,sum/2))
            return 1;
        return 0;
    }
};