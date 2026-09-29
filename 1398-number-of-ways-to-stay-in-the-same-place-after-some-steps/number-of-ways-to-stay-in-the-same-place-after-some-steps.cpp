class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(int pos, int steps) {
        if (pos < 0 || pos >= dp.size())
            return 0;

        if (steps == 0)
            return pos == 0 ? 1 : 0;

        if (dp[pos][steps] != -1)
            return dp[pos][steps];

        long long stay = solve(pos, steps - 1);
        long long left = solve(pos - 1, steps - 1);
        long long right = solve(pos + 1, steps - 1);

        return dp[pos][steps] =
            (stay + left + right) % MOD;
    }

    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps + 1);

        dp.assign(n, vector<int>(steps + 1, -1));

        return solve(0, steps);
    }
};