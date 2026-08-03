class Solution {
public:
    int n;
    vector<int> stoneValue;
    vector<vector<int>> dp;

    int solve(int i, int turn) {
        if (i >= n)
            return 0;

        if (dp[i][turn] != INT_MIN)
            return dp[i][turn];

        if (turn) { // Alice's turn (maximize)
            int res = INT_MIN;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                res = max(res, sum + solve(i + k + 1, 0));
            }

            return dp[i][turn] = res;
        } else { // Bob's turn (minimize)
            int res = INT_MAX;
            int sum = 0;

            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += stoneValue[i + k];
                res = min(res, -sum + solve(i + k + 1, 1));
            }

            return dp[i][turn] = res;
        }
    }

    string stoneGameIII(vector<int>& stoneValue) {
        this->stoneValue = stoneValue;
        n = stoneValue.size();

        dp.assign(n, vector<int>(2, INT_MIN));

        int verdict = solve(0, 1);

        if (verdict == 0)
            return "Tie";
        else if (verdict > 0)
            return "Alice";
        else
            return "Bob";
    }
};