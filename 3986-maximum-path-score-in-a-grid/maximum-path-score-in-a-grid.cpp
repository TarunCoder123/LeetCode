class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(int x, int y, vector<vector<int>> &grid, int k) {
        if (k < 0) return -1e7;
        if (x >= m || y >= n) return -1e7;

        // base case
        if (x == m - 1 && y == n - 1) {
            int cost = (grid[x][y] == 0 ? 0 : 1);
            if (k < cost) return -1e7;
            return grid[x][y];
        }

        // memoization check
        if (dp[x][y][k] != -1) return dp[x][y][k];

        int cost = (grid[x][y] == 0 ? 0 : 1);

        int right = solve(x + 1, y, grid, k - cost);
        int down  = solve(x, y + 1, grid, k - cost);

        return dp[x][y][k] = grid[x][y] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        // initialize DP with -1 (uncomputed)
        dp.assign(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        int ans = solve(0, 0, grid, k);
        return ans < 0 ? -1 : ans;
    }
};