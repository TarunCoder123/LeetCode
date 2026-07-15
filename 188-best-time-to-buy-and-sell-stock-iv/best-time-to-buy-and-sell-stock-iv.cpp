class Solution {
public:
        int n;
    // vector<vector<vector<int>>> dp;
    int dp[1005][3][105];
    int solve(int i, int buy,int count, vector<int>& prices) {
        if(count==0)return 0;
        if (i == n) return 0;

        if (dp[i][buy][count] != -1)
            return dp[i][buy][count];

        if (buy == 1) {
            return dp[i][buy][count] = max(
                -prices[i] + solve(i + 1, 0,count, prices),
                solve(i + 1, 1,count, prices)
            );
        } else {
            return dp[i][buy][count] = max(
                prices[i]+ solve(i + 1, 1,count-1, prices),               // sell and buy more
                solve(i + 1, 0,count, prices)  // skip
            );
        }
    }
    int maxProfit(int k, vector<int>& prices) {
               n = prices.size();
        // dp.assign(n, vector<int>(2, -1));
        memset(dp,-1,sizeof(dp));
        return solve(0, 1,k, prices);  
    }
};