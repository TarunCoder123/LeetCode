class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        // 1️⃣ Build prefix sum
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] = mat[i - 1][j - 1]
                           + pref[i - 1][j]
                           + pref[i][j - 1]
                           - pref[i - 1][j - 1];
            }
        }

        // 2️⃣ Binary search on side length
        int lo = 0, hi = min(m, n), ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            bool ok = false;

            for (int i = 0; i + mid <= m; i++) {
                for (int j = 0; j + mid <= n; j++) {
                    int sum = pref[i + mid][j + mid]
                            - pref[i][j + mid]
                            - pref[i + mid][j]
                            + pref[i][j];
                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }

            if (ok) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};
