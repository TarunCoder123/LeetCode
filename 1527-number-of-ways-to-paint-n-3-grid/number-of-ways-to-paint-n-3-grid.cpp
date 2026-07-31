class Solution {
public:
    const int INF=1e9+7;
    int dp[5005][4][4][4];
    int solve(int index,int prev1,int prev2,int prev3){
        // base case
        if(index==-1)return 1;
        if(dp[index][prev1][prev2][prev3]!=-1)return dp[index][prev1][prev2][prev3];
        int ans=0;
        for(int col1=0;col1<3;col1++){
            if(prev1==col1)continue;
            for(int col2=0;col2<3;col2++){
            if(prev2==col2 || col1 == col2)continue;
                for(int col3=0;col3<3;col3++){
            if(prev3==col3 || col2 == col3)continue;
                    ans=(ans+solve(index-1,col1,col2,col3))%INF;
                }
            }
        }
        return dp[index][prev1][prev2][prev3]=ans%INF;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n-1,3,3,3);
    }
};