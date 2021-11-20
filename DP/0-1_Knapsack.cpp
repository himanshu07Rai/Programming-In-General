#include <bits/stdc++.h>

using namespace std;
/*
     RECURSIVE ( gives TLE )

     int knapSack(int W, int wt[], int val[], int n) 
    { 
       if(n==0 || W==0)
        return 0;
        if(wt[n-1]<=W)
        {
            return max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
        }
        else return knapSack(W,wt,val,n-1);
    }

    */

/*

   Memoized

int check(int W, int wt[], int val[], int n,vector<vector<int>>&dp)
{
    if(n==0 || W==0)
        return 0;
    if(dp[n][W]>-1)
        return dp[n][W];
    if(wt[n-1]<=W)
    {
        return dp[n][W] = max(val[n-1]+check(W-wt[n-1],wt,val,n-1,dp),check(W,wt,val,n-1,dp));
    }
    else return dp[n][W] = check(W,wt,val,n-1,dp);
}
    //Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n) 
{ 
       // Your code here
       
    vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
    return check(W,wt,val,n,dp);
}

*/

int knapSack(int W, int wt[], int val[], int n)
{
    // Your code here
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][W];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(W, wt, val, n);

    return 0;
}