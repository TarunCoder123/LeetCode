class Solution {
public:
    vector<vector<int>> dp;

    bool isPalindrome(int l, int r, string &s) {
        if (l >= r) return true;

        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] != s[r])
            return dp[l][r] = false;

        return dp[l][r] = isPalindrome(l + 1, r - 1, s);
    }

    int countSubstrings(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        int count = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (isPalindrome(l, r, s))
                    count++;
            }
        }
        return count;
    }
};
