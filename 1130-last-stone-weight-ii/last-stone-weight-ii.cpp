class Solution {
public:
    int f(int i, vector<int>& nums, int total, int path, vector<vector<int>>& dp) {

        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i][path] != -1) {
            return dp[i][path];
        }

        //skip
        int skip = f(i + 1, nums, total, path, dp);

        //take
        int take = 0;
        if (2 * (path + nums[i]) <= total) {
            take = nums[i] + f(i + 1, nums, total, path + nums[i], dp);
        }

        return dp[i][path] = max(skip, take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        //int ans = INT_MAX;
        int path = 0;
        int total = 0;
        int n = stones.size();
        for (int i = 0; i < stones.size(); i++) {
            total += stones[i];
        }
        vector<vector<int>>dp(n + 1, vector<int>(total, -1));
        int half = f(0, stones, total, path, dp);
        int ans = total - (2 * half);

        return ans;
    }
};