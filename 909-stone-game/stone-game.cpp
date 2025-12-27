class Solution {
public:
    int dp[505][505];
    int solve(int l, int r, vector<int>& piles) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int takeLeft  = piles[l] - solve(l + 1, r, piles);
        int takeRight = piles[r] - solve(l, r - 1, piles);

        return dp[l][r] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        return solve(0, piles.size() - 1, piles) > 0;
    }
};
