class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<vector<int>> patterns = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int maxLen = 0;

        for (const auto& pattern : patterns) {
            maxLen = max(maxLen, countPatternMatch(nums, pattern));
        }

        return maxLen;
    }

private:
    int countPatternMatch(const vector<int>& nums, const vector<int>& pattern) {
        int count = 0;
        for (int num : nums) {
            if (num % 2 == pattern[count % 2]) {
                count++;
            }
        }
        return count;
    }
};