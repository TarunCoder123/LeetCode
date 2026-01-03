class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int l = 0;
        long long distinctSum = 0;
        unordered_map<int, int> freq;
        int ans = INT_MAX;

        for (int r = 0; r < nums.size(); r++) {
            // Add nums[r]
            if (freq[nums[r]] == 0) {
                distinctSum += nums[r];
            }
            freq[nums[r]]++;

            // Try shrinking window
            while (distinctSum >= k) {
                ans = min(ans, r - l + 1);

                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    distinctSum -= nums[l];
                }
                l++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
