class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int i, int buy, vector<int>& prices) {
        if (i == n) return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy == 1) {
            return dp[i][buy] = max(
                -prices[i] + solve(i + 1, 0, prices),
                solve(i + 1, 1, prices)
            );
        } else {
            return dp[i][buy] = max(
                prices[i],               // sell and finish
                solve(i + 1, 0, prices)  // skip
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n, vector<int>(2, -1));
        return solve(0, 1, prices);
    }
};
