class Solution {
public:
    int n;
    int dp[104][2][104];
    int solve(int i, vector<int>& piles, int turn, int M) {
        // Base case
        if (i >= n) return 0;
        if(dp[i][turn][M]!=-1)return dp[i][turn][M];
        if (turn == 1) {
            int maxi = INT_MIN;
            long long sum = 0;
            for (int j = 1; j <= 2 * M && i + j <= n; j++) {
                sum += piles[i + j - 1];
                maxi = max( maxi,(int)(sum + solve(i + j, piles, 0, max(M, j))));
            }

            return dp[i][turn][M]=maxi;
        } 
        else {
            int mini = INT_MAX;
            long long sum = 0;
            for (int j = 1; j <= 2 * M && i + j <= n; j++) {
                sum += piles[i + j - 1];
                 mini = min(mini,(int)(solve(i + j, piles, 1, max(M, j)))
                );
            }

            return dp[i][turn][M]=mini;
        }
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0, piles, 1, 1);
    }
};