class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long dp[5005][7][16];

    int solve(int left, int prev, int cnt, vector<int>& rollMax) {
        if (left == 0)
            return 1;

        if (dp[left][prev][cnt] != -1)
            return dp[left][prev][cnt];

        long long ans = 0;

        for (int face = 1; face <= 6; face++) {
            if (face == prev) {
                if (cnt == rollMax[face - 1])
                    continue;

                ans = (ans + solve(left - 1, face, cnt + 1, rollMax)) % MOD;
            } else {
                ans = (ans + solve(left - 1, face, 1, rollMax)) % MOD;
            }
        }

        return dp[left][prev][cnt] = ans;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 0, 0, rollMax);
    }
};