class Solution {
public:
    int n, k;
    vector<int> prefix;
    vector<vector<int>> memo;
    const int INF = 1e9;

    int sum(int l, int r) {
        return prefix[r + 1] - prefix[l];
    }

    int solve(int l, int r) {
        if (l == r) return 0;
        if (memo[l][r] != -1) return memo[l][r];

        int ans = INF;

        for (int mid = l; mid < r; mid += k - 1) {
            ans = min(ans, solve(l, mid) + solve(mid + 1, r));
        }

        // Can merge into one pile only when valid
        if ((r - l) % (k - 1) == 0) {
            ans += sum(l, r);
        }

        return memo[l][r] = ans;
    }

    int mergeStones(vector<int>& stones, int K) {
        n = stones.size();
        k = K;

        // Impossible check
        if ((n - 1) % (k - 1) != 0) return -1;

        // Prefix sum
        prefix.assign(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        memo.assign(n, vector<int>(n, -1));

        return solve(0, n - 1);
    }
};
