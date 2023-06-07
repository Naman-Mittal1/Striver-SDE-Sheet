int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        int val = values[i - 1];
        int wt = weights[i - 1];

        for (int currWt = 1; currWt <= w; currWt++) {
            if (wt > currWt)
                dp[i][currWt] = dp[i - 1][currWt];
            else
                dp[i][currWt] = max(dp[i - 1][currWt], val + dp[i - 1][currWt - wt]);
        }
    }

    return dp[n][w];
}
