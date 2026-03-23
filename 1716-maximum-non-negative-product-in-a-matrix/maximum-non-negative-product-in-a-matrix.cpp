class Solution {
public:
    int m, n;
    long long mod = 1e9 + 7;
    vector<vector<pair<long long,long long>>> dp;
    vector<vector<int>> grid;

    pair<long long,long long> dfs(int i, int j) {
        if (i == m-1 && j == n-1) {
            return {grid[i][j], grid[i][j]};
        }

        if (dp[i][j].first != LLONG_MIN) return dp[i][j];

        long long maxi = LLONG_MIN;
        long long mini = LLONG_MAX;

        if (i + 1 < m) {
            auto [mx, mn] = dfs(i+1, j);
            long long a = grid[i][j] * mx;
            long long b = grid[i][j] * mn;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        if (j + 1 < n) {
            auto [mx, mn] = dfs(i, j+1);
            long long a = grid[i][j] * mx;
            long long b = grid[i][j] * mn;
            maxi = max({maxi, a, b});
            mini = min({mini, a, b});
        }

        return dp[i][j] = {maxi, mini};
    }

    int maxProductPath(vector<vector<int>>& g) {
        grid = g;
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<pair<long long,long long>>(n, {LLONG_MIN, LLONG_MIN}));

        auto [maxProd, minProd] = dfs(0, 0);

        if (maxProd < 0) return -1;
        return maxProd % mod;
    }
};
