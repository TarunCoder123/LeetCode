class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int solve(vector<int>& locations, int curr, int finish, int fuel) {
        if (fuel < 0)
            return 0;

        if (dp[curr][fuel] != -1)
            return dp[curr][fuel];

        long long ans = (curr == finish);

        for (int i = 0; i < locations.size(); i++) {
            if (i == curr)
                continue;

            int cost = abs(locations[curr] - locations[i]);

            if (fuel >= cost) {
                ans = (ans + solve(locations, i, finish, fuel - cost)) % MOD;
            }
        }

        return dp[curr][fuel] = ans;
    }

    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        dp.assign(n, vector<int>(fuel + 1, -1));

        return solve(locations, start, finish, fuel);
    }
};