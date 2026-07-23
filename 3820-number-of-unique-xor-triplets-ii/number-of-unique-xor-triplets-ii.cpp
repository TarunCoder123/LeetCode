class Solution {
public:
    static const int MAXX = 2048;

    int uniqueXorTriplets(vector<int>& nums) {
        vector<vector<int>> dp(4, vector<int>(MAXX, 0));
        dp[0][0] = 1;

        for (int x : nums) {
            auto ndp = dp;

            for (int cnt = 0; cnt < 3; cnt++) {
                for (int xr = 0; xr < MAXX; xr++) {
                    if (!dp[cnt][xr]) continue;

                    // choose current element once
                    ndp[cnt + 1][xr ^ x] = 1;

                    // choose it twice
                    if (cnt + 2 <= 3)
                        ndp[cnt + 2][xr] = 1;

                    // choose it three times
                    if (cnt + 3 <= 3)
                        ndp[cnt + 3][xr ^ x] = 1;
                }
            }

            dp = move(ndp);
        }

        int ans = 0;
        for (int xr = 0; xr < MAXX; xr++)
            ans += dp[3][xr];

        return ans;
    }
};