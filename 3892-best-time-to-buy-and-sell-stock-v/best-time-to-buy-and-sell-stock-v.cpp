class Solution {
public:
 long long dp[1010][510][3];
 long long solve(int i, vector<int>& prices, int k, int state) {
        if(i==prices.size()){
            if(state!=0)return -1e10;
        }
        if (k <= 0 || i >= prices.size()) return 0;
        if(dp[i][k][state]!=-1)return dp[i][k][state];

        long long ans = LLONG_MIN;

        if (state == 0) {
            ans = max(ans, prices[i] + solve(i + 1, prices, k, 1)); // sell?
            ans = max(ans, -prices[i] + solve(i + 1, prices, k, 2)); // buy?
            ans = max(ans, solve(i + 1, prices, k, 0)); // skip
        }
        else if (state == 1) {
            ans = max(ans, -prices[i] + solve(i + 1, prices, k - 1, 0));
            ans = max(ans, solve(i + 1, prices, k, 1));
        }
        else { // state == 2
            ans = max(ans, prices[i] + solve(i + 1, prices, k - 1, 0));
            ans = max(ans, solve(i + 1, prices, k, 2));
        }

        return dp[i][k][state]=ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        // 1 buy karo , 2 sell karo ,0 jo maan hai wo karo
        int state=0;
        memset(dp,-1,sizeof(dp));
        long long ans=solve(0,prices,k,state);
        return ans;
    }
};