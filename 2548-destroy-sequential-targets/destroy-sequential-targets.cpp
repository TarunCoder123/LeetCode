class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {

        unordered_map<int, int> cnt;
        unordered_map<int, int> mn;

        for (int x : nums) {
            int rem = x % space;
            cnt[rem]++;
            if (!mn.count(rem))
                mn[rem] = x;
            else
                mn[rem] = min(mn[rem], x);
        }

        int bestCnt = 0;
        int ans = INT_MAX;

        for (auto &[rem, freq] : cnt) {
            if (freq > bestCnt) {
                bestCnt = freq;
                ans = mn[rem];
            } else if (freq == bestCnt) {
                ans = min(ans, mn[rem]);
            }
        }

        return ans;
    }
};