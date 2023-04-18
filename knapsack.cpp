int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{

    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    int notTaken = 0 + knapsackUtil(wt, val, ind - 1, W, dp);

    int taken = INT_MIN;
    if (wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

// Time Complexity: O(N*W)
// Reason: There are N*W states therefore at max ‘N*W’ new problems will be solved.

// Space Complexity: O(N*W) + O(N)
// Reason: We are using a recursion stack space(O(N)) and a 2D array ( O(N*W)).