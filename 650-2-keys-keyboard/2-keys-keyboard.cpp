class Solution {
public:
    int N;
    int dp[1001][1001];

    int solve(int screen, int clip){

        if(screen == N)
            return 0;

        if(screen > N)
            return 1e9;

        if(dp[screen][clip] != -1)
            return dp[screen][clip];

        int ans = 1e9;

        // Copy All
        if(screen != clip)
            ans = min(ans, 1 + solve(screen, screen));

        // Paste
        if(clip > 0)
            ans = min(ans, 1 + solve(screen + clip, clip));

        return dp[screen][clip] = ans;
    }

    int minSteps(int n) {

        if(n == 1)
            return 0;

        N = n;
        memset(dp,-1,sizeof(dp));

        return solve(1,0);
    }
};