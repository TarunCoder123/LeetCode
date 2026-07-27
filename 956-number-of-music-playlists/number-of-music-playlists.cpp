class Solution {
public:
    const int MOD = 1e9 + 7;

    int n, goal, k;
    vector<vector<long long>> dp;

    long long solve(int len, int used) {

        if (len == goal)
            return (used == n);

        if (dp[len][used] != -1)
            return dp[len][used];

        long long ans = 0;

        // Choose a new song
        if (used < n) {
            ans = (ans + (n - used) * solve(len + 1, used + 1)) % MOD;
        }

        // Replay an old song
        if (used > k) {
            ans = (ans + (used - k) * solve(len + 1, used)) % MOD;
        }

        return dp[len][used] = ans;
    }

    int numMusicPlaylists(int N, int Goal, int K) {
        n = N;
        goal = Goal;
        k = K;

        dp.assign(goal + 1, vector<long long>(n + 1, -1));

        return solve(0, 0);
    }
};