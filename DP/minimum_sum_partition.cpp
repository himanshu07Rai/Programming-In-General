#include <bits/stdc++.h>
using namespace std;

int minDifference(int arr[], int n)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	long long S = sum / 2 + 1;
	vector<vector<bool>> dp(n + 1, vector<bool>(S, true));
	for (int j = 1; j < S; j++)
		dp[0][j] = false;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < S; j++)
		{
			if (arr[i - 1] <= j)
			{
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	int ans = INT_MAX;

	for (int j = 0; j < S; j++)
	{
		if (dp[n][j])
			ans = min(ans, abs(int(2 * j - sum)));
	}

	return ans;
}

int main()
{

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << minDifference(a, n) << "\n";

	return 0;
}